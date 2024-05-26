//
// Created by 10484 on 24-5-21.
//

#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "MyFtp.h"

namespace Window
{
	QT_BEGIN_NAMESPACE

	namespace Ui
	{
		class MyMainWindow;
	}

	QT_END_NAMESPACE

	class MyMainWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		explicit MyMainWindow(QWidget *parent = nullptr);

		~MyMainWindow() override;

	protected:
		void closeEvent(QCloseEvent *event) override;

	private:
		void InitConnectSlots();
		void InitRecentConnections();
		void InitMenu();

	public slots:
		// 右上方 添加小窗口的按钮
		void OnNewTab();
		// 关闭一个小窗口
		void OnCloseTab(int idx);

		void ActionConnect();
		void ActionDelete();

	private:
		Ui::MyMainWindow *ui;
		// 右上方 添加小窗口的按钮
		QPushButton *newBtn = nullptr;
	};
} // Window

#endif //MYMAINWINDOW_H
