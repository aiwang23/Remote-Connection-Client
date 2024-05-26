//
// Created by 10484 on 24-5-21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MyMainWindow.h" resolved

#include "mymainwindow.h"

#include <QCloseEvent>
#include <QMessageBox>
#include <QMenu>
#include "ui_MyMainWindow.h"
#include "mylistdialog.h"
#include "ftpwidget.h"
#include <QWidget>
#include <fstream>
#include "nlohmann/json.hpp"

namespace Window
{
	MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MyMainWindow)
	{
		ui->setupUi(this);
		// * "用来添加窗口的按钮"
		newBtn = new QPushButton(QString("+"), this);
		ui->tabWidgetMain->setCornerWidget(newBtn);
		// 小窗口可移动
		ui->tabWidgetMain->setMovable(true);

		// 历史记录菜单
		InitMenu();
		// 连接信号槽
		InitConnectSlots();
		// 历史记录
		InitRecentConnections();
	}

	MyMainWindow::~MyMainWindow()
	{
		delete ui;
	}

	void MyMainWindow::closeEvent(QCloseEvent *event)
	{
		// 弹窗
		if (QMessageBox::question(this, this->windowTitle(), "您确认要退出吗？") ==
		    QMessageBox::Yes)
			return;
		event->ignore();
	}

	void MyMainWindow::InitConnectSlots()
	{
		connect(this->newBtn, &QPushButton::clicked, this, &MyMainWindow::OnNewTab);
		connect(ui->tabWidgetMain, &QTabWidget::tabCloseRequested,
		        this, &MyMainWindow::OnCloseTab);
		connect(ui->listWidgetRecentConnect, &QListWidget::doubleClicked,
			this, &MyMainWindow::ActionConnect);
	}

	void MyMainWindow::InitRecentConnections()
	{
		using json = nlohmann::json;
		std::ifstream f("RecentConnections.json");
		json jsonData = json::parse(f);
		for (const auto &i: jsonData["root"])
		{
			std::string host = i["host"];
			std::string port = i["port"];
			std::string user = i["user"];
			std::string password = i["password"];
			std::string type = i["type"];
			auto itemStr = user + "@" + type + "://" + host + ":" + port;
			ui->listWidgetRecentConnect->addItem(itemStr.c_str());
		}
	}

	void MyMainWindow::InitMenu()
	{
		const auto menu = new QMenu(ui->listWidgetRecentConnect);
		auto actionConnect = menu->addAction("连接");
		menu->addSeparator();
		auto avtionDelete = menu->addAction("删除");

		// 可以被右键
		ui->listWidgetRecentConnect->setContextMenuPolicy(Qt::CustomContextMenu);
		connect(ui->listWidgetRecentConnect,
		        &QListWidget::customContextMenuRequested,
		        this, [=](QPoint pos)
		        {
			        menu->exec(ui->listWidgetRecentConnect->viewport()->mapToGlobal(pos));
		        });
		// 菜单对应函数
		connect(actionConnect, &QAction::triggered, this,
		        &MyMainWindow::ActionConnect);
		connect(avtionDelete, &QAction::triggered, this,
		        &MyMainWindow::ActionDelete);
	}

	void MyMainWindow::OnNewTab()
	{
		// 选择连接窗口
		Window::MyListDialog list_dialog;
		// 想要连接的类型
		enum Window::ConnectType type;
		connect(&list_dialog, &Window::MyListDialog::NewSignal, this, [&](const enum Window::ConnectType t)
		{
			type = t;
		});
		list_dialog.exec();

		QString typeName;
		// 新建的连接控件
		QWidget *widget = nullptr;
		// ftp
		if (type == Window::ConnectType::FTP)
		{
			typeName = "ftp";
			widget = new Window::FtpWidget;
		}
		// 没有被选择到
		else
			typeName = "未知类型";
		// TODO

		// 垂直布局
		const auto vLayout = new QVBoxLayout;
		vLayout->addWidget(widget);
		// 新建的小窗口
		const auto newWidget = new QWidget;
		newWidget->setLayout(vLayout);
		// 把新建的小窗口加到 tab里
		ui->tabWidgetMain->addTab(newWidget, QString("%0连接").arg(typeName));
		ui->tabWidgetMain->setCurrentIndex(ui->tabWidgetMain->count() - 1);
		// 假如小窗口还在登陆时 点击关闭按钮 就关闭
		connect(dynamic_cast<Window::FtpWidget *>(widget), &Window::FtpWidget::CloseSignal,
		        this, [=]()
		        {
			        ui->tabWidgetMain->removeTab(ui->tabWidgetMain->indexOf(newWidget));
		        });

		if (widget)
			// 添加历史记录
			connect(dynamic_cast<Window::FtpWidget *>(widget), &Window::FtpWidget::LoginOKSignal,
			        this, [=](Core::FtpUserData data)
			        {
				        ifstream in("RecentConnections.json");
				        nlohmann::json rootJson = nlohmann::json::parse(in);
				        for (const auto &i: rootJson["root"])
					        // 没有被加过
					        if (!(i["host"] == data.host && i["port"] == data.port &&
					              i["user"] == data.user && i["password"] == data.password &&
					              i["type"] == "ftp")
					        )
					        {
						        nlohmann::json inJson;
						        inJson["host"] = data.host;
						        inJson["port"] = data.port;
						        inJson["user"] = data.user;
						        inJson["password"] = data.password;
						        inJson["type"] = "ftp";
						        rootJson["root"].push_back(inJson);
						        ofstream out("RecentConnections.json");
						        out << rootJson;
						        break;
					        }
			        });
	}

	void MyMainWindow::OnCloseTab(const int idx)
	{
		if (ui->tabWidgetMain->count() == 1)
		{
			this->close();
			return;
		}
		ui->tabWidgetMain->currentWidget()->close();
		ui->tabWidgetMain->removeTab(idx);
	}

	void MyMainWindow::ActionConnect()
	{
		// user@type://host:port
		auto selectedItems = ui->listWidgetRecentConnect->selectedItems();
		QString itemStr = selectedItems.at(0)->text();

		const auto userAndList = itemStr.split("@");
		// user
		std::string user = userAndList.at(0).toStdString();
		auto typeAndList = userAndList.at(1).split("://");
		// type
		std::string type = typeAndList.at(0).toStdString();
		const auto hostAndList = typeAndList.at(1).split(":");
		// host
		std::string host = hostAndList.at(0).toStdString();
		// port
		std::string port = hostAndList.at(1).toStdString();

		std::ifstream in("RecentConnections.json");
		nlohmann::json rootJson = nlohmann::json::parse(in);
		std::string password;
		// 在历史记录里寻找
		for (const auto &i: rootJson["root"])
		{
			if (i["host"] == host && i["port"] == port && i["user"] == user &&
			    i["type"] == type)
			{
				password = i["password"];
				break;
			}
		}

		QString typeName = type.c_str();
		// 新建的连接控件
		QWidget *widget = nullptr;
		// ftp
		if (type == "ftp")
		{
			Core::FtpUserData user_data = {
				host, port, user, password
			};
			widget = new Window::FtpWidget(nullptr, user_data);
		}
		// 没有被选择到
		else
			typeName = "未知类型";
		// TODO

		// 垂直布局
		const auto vLayout = new QVBoxLayout;
		vLayout->addWidget(widget);
		// 新建的小窗口
		const auto newWidget = new QWidget;
		newWidget->setLayout(vLayout);
		// 把新建的小窗口加到 tab里
		ui->tabWidgetMain->addTab(newWidget, QString("%0连接").arg(typeName));
		ui->tabWidgetMain->setCurrentIndex(ui->tabWidgetMain->count() - 1);
		// 假如小窗口还在登陆时 点击关闭按钮 就关闭
		connect(dynamic_cast<Window::FtpWidget *>(widget), &Window::FtpWidget::CloseSignal,
		        this, [=]()
		        {
			        ui->tabWidgetMain->removeTab(ui->tabWidgetMain->indexOf(newWidget));
		        });
	}

	void MyMainWindow::ActionDelete()
	{
		auto selectedItems = ui->listWidgetRecentConnect->selectedItems();
		const QString itemStr = selectedItems.at(0)->text();
		const auto userAndList = itemStr.split("@");
		// user
		std::string user = userAndList.at(0).toStdString();
		auto typeAndList = userAndList.at(1).split("://");
		// type
		std::string type = typeAndList.at(0).toStdString();
		const auto hostAndList = typeAndList.at(1).split(":");
		// host
		std::string host = hostAndList.at(0).toStdString();
		// port
		std::string port = hostAndList.at(1).toStdString();

		std::ifstream in("RecentConnections.json");
		nlohmann::json rootJson = nlohmann::json::parse(in);

		auto wantDelIdx = rootJson["root"].begin();
		for (const auto &i: rootJson["root"])
		{
			if (i["user"] == user && i["type"] == type &&
			    i["host"] == host && i["port"] == port)
				break;
			++wantDelIdx;
		}
		rootJson["root"].erase(wantDelIdx);
		std::ofstream out("RecentConnections.json");
		out << rootJson;
		auto wantDelItem = ui->listWidgetRecentConnect->currentItem();
		ui->listWidgetRecentConnect->removeItemWidget(wantDelItem);
		delete wantDelItem;
	}
} // Window
