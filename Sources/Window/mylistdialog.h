//
// Created by 10484 on 24-5-21.
//

#ifndef MYLISTDIALOG_H
#define MYLISTDIALOG_H

#include <QDialog>

class QListWidgetItem;

namespace Window
{
	QT_BEGIN_NAMESPACE

	namespace Ui
	{
		class MyListDialog;
	}

	QT_END_NAMESPACE

	enum ConnectType
	{
		NONE = -1, // 未选择
		FTP,       // ftp 连接
		FTPS,      // TODO
		SFTP       // TODO
	};

	class MyListDialog : public QDialog
	{
		Q_OBJECT

	public:
		explicit MyListDialog(QWidget *parent = nullptr);

		~MyListDialog() override;

	signals:
		// 选择了 什么连接
		void NewSignal(enum ConnectType type);

	public slots:
		// 选择了 什么连接
		void OnNewConnect(QListWidgetItem *item);

	private:
		// 初始化列表
		void InitList();

	private:
		Ui::MyListDialog *ui;
	};
} // Window

#endif //MYLISTDIALOG_H
