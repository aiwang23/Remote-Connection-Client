//
// Created by 10484 on 24-5-11.
//

#ifndef FTPWIDGET_H
#define FTPWIDGET_H

#include <QWidget>
#include "MyFtp.h"
#include <QString>

namespace Window
{
	QT_BEGIN_NAMESPACE

	namespace Ui
	{
		class FtpWidget;
	}

	QT_END_NAMESPACE

	class FtpWidget : public QWidget
	{
		Q_OBJECT

	public:
		/**
		 * 初始化ftp内核
		 * @param parent
		 * @param user_data
		 */
		explicit FtpWidget(QWidget *parent = nullptr,
		                   const Core::FtpUserData &user_data = Core::FtpUserData());

		~FtpWidget() override;

		/**
		 * 关闭窗口时 弹出确认窗口
		 * @param event 
		 */
		void closeEvent(QCloseEvent *event) override;

	signals:
		void LoginOKSignal(Core::FtpUserData data);

		void LoginFailedSignal();

		// 关闭窗口 发送信号
		void CloseSignal();

	public slots:
		/**
		 * 登录 确认按钮
		 */
		void OnLoginOK();

		/**
		 * 鼠标双击跳转目录
		 * @param row 在列表的哪一行
		 */
		void OnCellDoubleClicked(int row);

		/**
		 * 退出上级目录 按钮
		 */
		void OnCdup();

		/**
		 * 刷新 按钮
		 */
		void OnRefresh() const;

		/**
		 * 上传 右键菜单
		 */
		void PutAction();

		/**
		 * 下载 右键菜单
		 */
		void GetAction();

		/**
		 * 删除 右键菜单
		 */
		void DeleteAction();

		void OnDetailedInfo(int row, int idx) const;

	private:
		/**
		 * 初始化菜单
		 */
		void InitMenu();

		// 连接槽
		void InitConnectSlots();

		/**
		 * 获取文件名
		 * @param row 列表行 
		 * @return 
		 */
		[[nodiscard]] QString GetFileName(int row) const;

		/**
		 * 清空列表
		 */
		void ClearList() const;

		/**
		 * 设置一项
		 * @param row 行
		 * @param idx 列
		 * @param item 名字
		 */
		void SetListItem(int row, int idx, const QString &item) const;

		/**
		 *插入一行
		 * @param row 行
		 * @param info 一行的信息
		 */
		void InsertListRow(int row, const Core::FtpFileInfo &info) const;

		/**
		 * 添加列表
		 * @param list
		 */
		void AppendList(const std::vector<Core::FtpFileInfo> &list) const;

	private:
		Ui::FtpWidget *ui;
		/**
		 * Ftp对象 用来执行实际的操作
		 */
		std::unique_ptr<Core::MyFtp> ftpCtx;
	};
} // Window

#endif //FTPWIDGET_H
