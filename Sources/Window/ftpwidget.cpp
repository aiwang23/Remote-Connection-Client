//
// Created by 10484 on 24-5-11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FtpWidget.h" resolved
#pragma execution_character_set("utf-8")

#include "ftpwidget.h"

#include "ui_FtpWidget.h"
#include <QMenu>
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFileDialog>
#include <QSet>
#include <set>

namespace Window
{
    FtpWidget::FtpWidget(QWidget *parent, const Core::FtpUserData &user_data) : QWidget(parent), ui(new Ui::FtpWidget)
    {
        ui->setupUi(this);
        // 连接槽
        InitConnectSlots();
        // 初始化菜单
        InitMenu();
        // 初始化列表
        ui->tableWidgetFileList->setColumnCount(7);
        ui->tableWidgetFileList->setHorizontalHeaderLabels(
            {"权限", "链接数", "属主", "属组", "大小", "修改日期", "名称"}
        );
        // 初始化ftp内核
        this->ftpCtx = std::make_unique<Core::MyFtp>();

        // 通过登录窗口 登录
        if (user_data.host.empty() || user_data.port.empty() ||
            user_data.user.empty() || user_data.password.empty())
        {
            // 默认为登录窗口
            ui->stackedWidgetFtp->setCurrentIndex(1);
        }
        // 通过历史记录 登录
        else
        {
            ui->editHost->setText(user_data.host.c_str());
            ui->editPort->setText(user_data.port.c_str());
            ui->editUser->setText(user_data.user.c_str());
            ui->editPassword->setText(user_data.password.c_str());
            OnLoginOK();
        }
    }

    FtpWidget::~FtpWidget()
    {
        ftpCtx.reset();
        delete ui;
    }

    void FtpWidget::closeEvent(QCloseEvent *event)
    {
        // 弹窗
        if (QMessageBox::question(this, this->windowTitle(), "您确认要关闭吗？") ==
            QMessageBox::Yes)
        {
            emit CloseSignal();
            return;
        }
        event->ignore();
    }

    void FtpWidget::OnLoginOK()
    {
        // 获取登录信息
        Core::FtpUserData ftp_data;
        ftp_data.host = ui->editHost->text().toStdString();
        ftp_data.port = ui->editPort->text().toStdString();
        ftp_data.user = ui->editUser->text().toStdString();
        ftp_data.password = ui->editPassword->text().toStdString();
        // 登录
        if (!ftpCtx->Login(ftp_data))
        {
            QMessageBox::warning(this, this->windowTitle(),
                                 QString("登录失败 %0").arg(ftpCtx->GetError().c_str()));
            qDebug() << __FILE__ << __FUNCTION__ << "fptCtx->Login failed";
            emit LoginFailedSignal();
            return;
        }
        emit LoginOKSignal(ftp_data);
        // 切换到 ftp 列表窗口
        ui->stackedWidgetFtp->setCurrentIndex(0);
        // 清空列表
        ClearList();
        ui->labelFtpStatus->setText(
            QString("连接成功 %0@%1://%2:%3")
            .arg(ftp_data.user.c_str())
            .arg("ftp")
            .arg(ftp_data.host.c_str())
            .arg(ftp_data.port.empty() ? "21" : ftp_data.port.c_str())
        );
        ui->editPath->setText(ftpCtx->Pwd().c_str());
        AppendList(ftpCtx->Dir());
    }

    void FtpWidget::OnCellDoubleClicked(const int row)
    {
        // 双击失败
        if (row < 0)
        {
            qDebug() << __FILE__ << __FUNCTION__ << "row is out index ";
            return;
        }
        // 双击选中的文件名
        QString fileName = ui->tableWidgetFileList->item(row, 6)->text();
        // 是否为目录
        if (ui->tableWidgetFileList->item(row, 0)->text().at(0) != 'd')
            fileName = fileName.split(" ")[0];
        // 进入文件夹
        if (!ftpCtx->Cd(fileName.toStdString()))
        {
            QMessageBox::warning(this, this->windowTitle(),
                                 QString("切换失败 %0 不是目录").arg(fileName));
            return;
        }
        // 更新路径框
        ui->editPath->setText(ftpCtx->Pwd().c_str());
        // 更新列表
        const auto list = ftpCtx->Dir();
        ClearList();
        AppendList(list);
    }

    void FtpWidget::OnCdup()
    {
        // 回退上级目录
        if (!ftpCtx->CdUp())
        {
            QMessageBox::warning(this, this->windowTitle(),
                                 QString("回退失败 %0").arg(ftpCtx->GetError().c_str()));
            return;
        }
        // 更新路径框
        ui->editPath->setText(ftpCtx->Pwd().c_str());
        // 更新列表
        ClearList();
        AppendList(ftpCtx->Dir());
    }

    void FtpWidget::OnRefresh() const
    {
        // 刷新
        ClearList();
        AppendList(ftpCtx->Dir());
    }

    void FtpWidget::PutAction()
    {
        // 文件选择窗口 选择要被上传的文件
        QFileDialog fileDialog(this, "上传文件");
        // 必须时已存在的文件
        fileDialog.setFileMode(QFileDialog::FileMode::ExistingFiles);
        // 弹出窗口
        if (fileDialog.exec() != QDialog::Accepted)
            return;
        // 要被上传的文件
        QStringList files = fileDialog.selectedFiles();
        // 上传成功的文件
        QString fileOK;
        for (const auto &file: files)
        {
            // 上传
            if (!ftpCtx->Put(file.toStdString()))
            {
                // 失败
                QMessageBox::warning(this, this->windowTitle(),
                                     QString("%0 上传失败\n%1")
                                     .arg(file).arg(ftpCtx->GetError().c_str()));
                return;
            }
            else
            // 成功
                fileOK.append(QString("%0\n").arg(file));
        }
        // 提示下 上传成功的有什么
        if (!fileOK.isEmpty())
            QMessageBox::information(this, this->windowTitle(),
                                     QString("%0 上传成功").arg(fileOK));
        // 更新列表
        ClearList();
        AppendList(ftpCtx->Dir());
    }

    void FtpWidget::GetAction()
    {
        // 选中的位置要有效
        if (const int row = ui->tableWidgetFileList->currentRow(); row < 0)
        {
            QMessageBox::warning(this, this->windowTitle(), "没有选择下载文件");
            return;
        }
        // 选择下载到哪里
        QFileDialog loadPaths(this, "下载文件到");
        loadPaths.setFileMode(QFileDialog::Directory);
        // 弹窗
        if (loadPaths.exec() != QDialog::Accepted)
            return;
        // 选择下载到的路径只能一个
        if (loadPaths.selectedFiles().size() > 1)
        {
            QMessageBox::warning(this, "选择路径过多！", "最多选择一个路径");
            return;
        }
        // 下载到的路径
        QString loadPath = loadPaths.selectedFiles().at(0);
        // 列表选择到的选项
        QList<QTableWidgetItem *> selectedItems = ui->tableWidgetFileList->selectedItems();
        // set容器 去重
        QSet<QString> setFiles;
        // 去重
        for (const auto &item: selectedItems)
            setFiles.insert(ui->tableWidgetFileList->item(item->row(), 6)->text());
        // 要被下载的文件
        QList<QString> files(setFiles.begin(), setFiles.end());
        // 下载成功的文件
        QString getOKFiles;
        for (const auto &file: files)
        {
            const QString tmp(loadPath);
            // 拼接下载到的路径
            loadPath.append(QString("/%0").arg(file));
            // 下载
            if (!ftpCtx->Get(loadPath.toStdString(), file.toStdString()))
            {
                // 失败
                QMessageBox::warning(this, this->windowTitle(),
                                     QString("%0下载错误 %1").arg(file).arg(ftpCtx->GetError().c_str()));
            }
            else
            // 成功
                getOKFiles.append(QString("%0\n").arg(file));
            loadPath = tmp;
        }
        // 把下载成功的文件提示一下
        if (!getOKFiles.isEmpty())
            QMessageBox::information(this, this->windowTitle(),
                                     QString("%0 下载成功").arg(getOKFiles));
    }

    void FtpWidget::DeleteAction()
    {
        // 列表中选择了哪个
        QList<QTableWidgetItem *> selectedItems = ui->tableWidgetFileList->selectedItems();
        // 去重
        QSet<QString> setFiles;
        for (const auto &item: selectedItems)
            setFiles.insert(ui->tableWidgetFileList->item(item->row(), 6)->text());
        // 要被删除的文件
        QStringList files(setFiles.begin(), setFiles.end());
        if (files.isEmpty())
        {
            QMessageBox::warning(this, this->windowTitle(),
                                 QString("请选择要删除的文件"));
            return;
        }
        // 删除成功的文件
        QString deleteOKFiles;
        for (const auto &file: files)
        {
            // 删除
            if (!ftpCtx->Delete(file.toStdString()))
                // 失败
                QMessageBox::warning(this, this->windowTitle(),
                                     QString("%0 删除失败 %1").arg(file).arg(ftpCtx->GetError().c_str()));
            else
                // 成功
                deleteOKFiles.append(QString("%0\n").arg(file));
        }
        // 把删除成功的文件提示一下
        if (!deleteOKFiles.isEmpty())
            QMessageBox::information(this, this->windowTitle(),
                                     QString("%0 删除成功").arg(deleteOKFiles));
    }

    void FtpWidget::OnDetailedInfo(const int row, int idx) const
    {
        const QString name = ui->tableWidgetFileList->item(row, 6)->text();
        const QString date = ui->tableWidgetFileList->item(row, 5)->text();
        ui->labelName->setText(QString("名称:\n%0").arg(name));
        ui->labelModifyTime->setText(QString("修改日期:\n%0").arg(date));
    }


    void FtpWidget::InitMenu()
    {
        // 新建菜单
        const auto menu = new QMenu(ui->tableWidgetFileList);

        const auto m_actionCdup = menu->addAction("回退上级");
        // 新建分割线
        menu->addSeparator();
        // 新建上传菜单项
        const auto m_actionPut = menu->addAction("上传");
        // 新建下载菜单项
        const auto m_actionGet = menu->addAction("下载");
        // 新建分割线
        menu->addSeparator();
        // 新建删除菜单项
        const auto m_actionDel = menu->addAction("删除");
        // 可以被右键
        this->ui->tableWidgetFileList->setContextMenuPolicy(Qt::CustomContextMenu);
        // 右键弹出窗口
        connect(ui->tableWidgetFileList,
                &QTabWidget::customContextMenuRequested,
                [=](const QPoint pos)
                {
                    // 局部位置转全局位置
                    menu->exec(ui->tableWidgetFileList->viewport()->mapToGlobal(pos));
                }
        );
        // 菜单对应的函数
        connect(m_actionCdup, &QAction::triggered, this, &FtpWidget::OnCdup);
        connect(m_actionPut, &QAction::triggered, this, &FtpWidget::PutAction);
        connect(m_actionGet, &QAction::triggered, this, &FtpWidget::GetAction);
        connect(m_actionDel, &QAction::triggered, this, &FtpWidget::DeleteAction);
    }

    void FtpWidget::InitConnectSlots()
    {
        // 登录窗口 确认
        connect(ui->btnLoginOK, &QPushButton::clicked, this, &FtpWidget::OnLoginOK);
        // 登录窗口 退出
        connect(ui->btnLoginClose, &QPushButton::clicked, this, &FtpWidget::close);
        // 列表窗口 刷新
        connect(ui->btnRefresh, &QPushButton::clicked, this, &FtpWidget::OnRefresh);
        // 列表窗口 回退上级
        connect(ui->btnReturn, &QPushButton::clicked, this, &FtpWidget::OnCdup);
        // 列表窗口 路径框 回车
        connect(ui->editPath, &QLineEdit::returnPressed, this, [this]()
        {
            // 失去焦点
            ui->editPath->clearFocus();
            if (!ftpCtx->Cd(ui->editPath->text().toStdString()))
            {
                // 失败
                ui->editPath->setStyleSheet("background-color:#FFE931");
                QMessageBox::warning(this, this->windowTitle(),
                                     QString("跳转失败"));
            }
            else
            {
                // 成功
                ui->editPath->setStyleSheet("background-color:#FFFFFF");
                ClearList();
                AppendList(ftpCtx->Dir());
            }
        });
        // 双击跳转
        connect(ui->tableWidgetFileList, &QTableWidget::cellDoubleClicked, this,
                &FtpWidget::OnCellDoubleClicked);
        // 单击显示详细信息
        connect(ui->tableWidgetFileList, &QTableWidget::cellClicked, this,
                &FtpWidget::OnDetailedInfo);
    }

    QString FtpWidget::GetFileName(const int row) const
    {
        QString fileName = ui->tableWidgetFileList->item(row, 6)->text();
        if (fileName.contains(" ") &&
            ui->tableWidgetFileList->item(row, 0)->text().at(0) == '1')
            fileName = fileName.split(" ").at(0);
        return fileName;
    }

    void FtpWidget::ClearList() const
    {
        while (ui->tableWidgetFileList->rowCount() > 0)
            ui->tableWidgetFileList->removeRow(0);
    }

    void FtpWidget::SetListItem(const int row, const int idx, const QString &item) const
    {
        auto pItem = new QTableWidgetItem(item);
        ui->tableWidgetFileList->setItem(row, idx, pItem);
        // Qt::ItemIsSelectable：项目可以被选中。
        // Qt::ItemIsUserCheckable：项目可以被用户勾选或取消勾选。
        // Qt::ItemIsEnabled：项目是可交互的。
        const auto retItem = ui->tableWidgetFileList->item(row, idx);
        retItem->setFlags(Qt::ItemIsSelectable |
                          Qt::ItemIsUserCheckable |
                          Qt::ItemIsEnabled);
    }

    void FtpWidget::InsertListRow(int row, const Core::FtpFileInfo &info) const
    {
        // 插入一行
        ui->tableWidgetFileList->insertRow(row);
        // 设置选项内容
        this->SetListItem(row, 0, info.access.c_str());
        this->SetListItem(row, 1, info.linkNB.c_str());
        this->SetListItem(row, 2, info.ower.c_str());
        this->SetListItem(row, 3, info.group.c_str());
        this->SetListItem(row, 4, info.size.c_str());
        this->SetListItem(row, 5, info.date.c_str());
        this->SetListItem(row, 6, info.fileName.c_str());
        if (info.access.at(0) == 'd')
        {
            for (int i = 0; i < ui->tableWidgetFileList->columnCount(); ++i)
            {
                ui->tableWidgetFileList->item(row, i)->setBackground(
                    QBrush(QColor(251, 222, 154))
                );
            }
        }
    }

    void FtpWidget::AppendList(const std::vector<Core::FtpFileInfo> &list) const
    {
        for (auto &info: list)
            this->InsertListRow(ui->tableWidgetFileList->rowCount(), info);
    }
} // Window
