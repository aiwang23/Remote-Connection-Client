//
// Created by 10484 on 24-5-21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MyListDialog.h" resolved

#include "mylistdialog.h"
#include "ui_MyListDialog.h"

namespace Window
{
	MyListDialog::MyListDialog(QWidget *parent) : QDialog(parent), ui(new Ui::MyListDialog)
	{
		ui->setupUi(this);
		InitList();
	}

	MyListDialog::~MyListDialog()
	{
		delete ui;
	}


	void MyListDialog::OnNewConnect(QListWidgetItem *item)
	{
		const QString itemText = item->text();
		enum Window::ConnectType type = Window::ConnectType::NONE;

		// 查看点击了什么选项
		if (itemText == "Ftp 连接")
			type = Window::ConnectType::FTP;
		else
			type = Window::ConnectType::NONE;
		// TODO
		// * 这里还会考虑再加 FTPS和SFTP类型

		emit NewSignal(type);
		this->close();
	}

	void MyListDialog::InitList()
	{
		QList<QListWidgetItem *> list;
		// 新建 ftp 选项
		const auto newFtp = new QListWidgetItem(QString("Ftp 连接"), ui->listWidget);
		connect(ui->listWidget, &QListWidget::itemDoubleClicked, this,
		        &MyListDialog::OnNewConnect);
		list.append(newFtp);
		// TODO
		// * 这里还会考虑再加 FTPS和SFTP类型

		for (int i = 0; i < list.size(); ++i)
		{
			ui->listWidget->insertItem(i, list.at(i));
		}
	}
} // Window
