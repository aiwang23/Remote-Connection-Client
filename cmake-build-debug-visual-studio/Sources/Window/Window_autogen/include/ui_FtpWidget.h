/********************************************************************************
** Form generated from reading UI file 'ftpwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTPWIDGET_H
#define UI_FTPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace Window {

class Ui_FtpWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QStackedWidget *stackedWidgetFtp;
    QWidget *pageFtp;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnRefresh;
    QPushButton *btnReturn;
    QLineEdit *editPath;
    QWidget *widgetMain;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QTableWidget *tableWidgetFileList;
    QGroupBox *groupBoxDetailedInfo;
    QVBoxLayout *verticalLayout;
    QLabel *labelImage;
    QLabel *labelName;
    QLabel *labelModifyTime;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelFtpStatus;
    QWidget *pageLogin;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelPort;
    QLineEdit *editHost;
    QLabel *labelHost;
    QLineEdit *editPassword;
    QSpacerItem *verticalSpacer_3;
    QLabel *labelUser;
    QLineEdit *editUser;
    QLabel *labelPassword;
    QLineEdit *editPort;
    QPushButton *btnLoginOK;
    QPushButton *btnLoginClose;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Window__FtpWidget)
    {
        if (Window__FtpWidget->objectName().isEmpty())
            Window__FtpWidget->setObjectName("Window__FtpWidget");
        Window__FtpWidget->resize(632, 568);
        horizontalLayout_3 = new QHBoxLayout(Window__FtpWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        stackedWidgetFtp = new QStackedWidget(Window__FtpWidget);
        stackedWidgetFtp->setObjectName("stackedWidgetFtp");
        pageFtp = new QWidget();
        pageFtp->setObjectName("pageFtp");
        verticalLayout_2 = new QVBoxLayout(pageFtp);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(pageFtp);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        btnRefresh = new QPushButton(widget);
        btnRefresh->setObjectName("btnRefresh");

        horizontalLayout->addWidget(btnRefresh);

        btnReturn = new QPushButton(widget);
        btnReturn->setObjectName("btnReturn");

        horizontalLayout->addWidget(btnReturn);

        editPath = new QLineEdit(widget);
        editPath->setObjectName("editPath");

        horizontalLayout->addWidget(editPath);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 20);

        verticalLayout_2->addWidget(widget);

        widgetMain = new QWidget(pageFtp);
        widgetMain->setObjectName("widgetMain");
        horizontalLayout_2 = new QHBoxLayout(widgetMain);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        splitter = new QSplitter(widgetMain);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        tableWidgetFileList = new QTableWidget(splitter);
        tableWidgetFileList->setObjectName("tableWidgetFileList");
        splitter->addWidget(tableWidgetFileList);
        groupBoxDetailedInfo = new QGroupBox(splitter);
        groupBoxDetailedInfo->setObjectName("groupBoxDetailedInfo");
        verticalLayout = new QVBoxLayout(groupBoxDetailedInfo);
        verticalLayout->setObjectName("verticalLayout");
        labelImage = new QLabel(groupBoxDetailedInfo);
        labelImage->setObjectName("labelImage");

        verticalLayout->addWidget(labelImage);

        labelName = new QLabel(groupBoxDetailedInfo);
        labelName->setObjectName("labelName");

        verticalLayout->addWidget(labelName);

        labelModifyTime = new QLabel(groupBoxDetailedInfo);
        labelModifyTime->setObjectName("labelModifyTime");

        verticalLayout->addWidget(labelModifyTime);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        splitter->addWidget(groupBoxDetailedInfo);

        horizontalLayout_2->addWidget(splitter);


        verticalLayout_2->addWidget(widgetMain);

        widget_3 = new QWidget(pageFtp);
        widget_3->setObjectName("widget_3");
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        labelFtpStatus = new QLabel(widget_3);
        labelFtpStatus->setObjectName("labelFtpStatus");

        horizontalLayout_5->addWidget(labelFtpStatus);


        verticalLayout_2->addWidget(widget_3);

        verticalLayout_2->setStretch(1, 10);
        stackedWidgetFtp->addWidget(pageFtp);
        pageLogin = new QWidget();
        pageLogin->setObjectName("pageLogin");
        horizontalLayout_4 = new QHBoxLayout(pageLogin);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        widget_2 = new QWidget(pageLogin);
        widget_2->setObjectName("widget_2");
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        labelPort = new QLabel(widget_2);
        labelPort->setObjectName("labelPort");

        gridLayout_2->addWidget(labelPort, 2, 0, 1, 1);

        editHost = new QLineEdit(widget_2);
        editHost->setObjectName("editHost");

        gridLayout_2->addWidget(editHost, 1, 1, 1, 1);

        labelHost = new QLabel(widget_2);
        labelHost->setObjectName("labelHost");

        gridLayout_2->addWidget(labelHost, 1, 0, 1, 1);

        editPassword = new QLineEdit(widget_2);
        editPassword->setObjectName("editPassword");

        gridLayout_2->addWidget(editPassword, 4, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 6, 1, 1, 1);

        labelUser = new QLabel(widget_2);
        labelUser->setObjectName("labelUser");

        gridLayout_2->addWidget(labelUser, 3, 0, 1, 1);

        editUser = new QLineEdit(widget_2);
        editUser->setObjectName("editUser");

        gridLayout_2->addWidget(editUser, 3, 1, 1, 1);

        labelPassword = new QLabel(widget_2);
        labelPassword->setObjectName("labelPassword");

        gridLayout_2->addWidget(labelPassword, 4, 0, 1, 1);

        editPort = new QLineEdit(widget_2);
        editPort->setObjectName("editPort");

        gridLayout_2->addWidget(editPort, 2, 1, 1, 1);

        btnLoginOK = new QPushButton(widget_2);
        btnLoginOK->setObjectName("btnLoginOK");

        gridLayout_2->addWidget(btnLoginOK, 5, 0, 1, 1);

        btnLoginClose = new QPushButton(widget_2);
        btnLoginClose->setObjectName("btnLoginClose");

        gridLayout_2->addWidget(btnLoginClose, 5, 1, 1, 1);


        horizontalLayout_4->addWidget(widget_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(2, 1);
        stackedWidgetFtp->addWidget(pageLogin);

        horizontalLayout_3->addWidget(stackedWidgetFtp);


        retranslateUi(Window__FtpWidget);

        stackedWidgetFtp->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Window__FtpWidget);
    } // setupUi

    void retranslateUi(QWidget *Window__FtpWidget)
    {
        Window__FtpWidget->setWindowTitle(QCoreApplication::translate("Window::FtpWidget", "FtpWidget", nullptr));
        btnRefresh->setText(QCoreApplication::translate("Window::FtpWidget", "\345\210\267\346\226\260", nullptr));
        btnReturn->setText(QCoreApplication::translate("Window::FtpWidget", "\345\233\236\351\200\200\344\270\212\347\272\247", nullptr));
        groupBoxDetailedInfo->setTitle(QCoreApplication::translate("Window::FtpWidget", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        labelImage->setText(QCoreApplication::translate("Window::FtpWidget", "\345\233\276\346\240\207", nullptr));
        labelName->setText(QCoreApplication::translate("Window::FtpWidget", "\345\220\215\347\247\260", nullptr));
        labelModifyTime->setText(QCoreApplication::translate("Window::FtpWidget", "\344\277\256\346\224\271\346\227\245\346\234\237", nullptr));
        labelFtpStatus->setText(QCoreApplication::translate("Window::FtpWidget", "\346\234\252\350\277\236\346\216\245", nullptr));
        labelPort->setText(QCoreApplication::translate("Window::FtpWidget", "Port: ", nullptr));
        editHost->setText(QCoreApplication::translate("Window::FtpWidget", "192.168.0.11", nullptr));
        labelHost->setText(QCoreApplication::translate("Window::FtpWidget", "Host: ", nullptr));
        editPassword->setText(QCoreApplication::translate("Window::FtpWidget", "123456", nullptr));
        labelUser->setText(QCoreApplication::translate("Window::FtpWidget", "User: ", nullptr));
        editUser->setText(QCoreApplication::translate("Window::FtpWidget", "wang", nullptr));
        labelPassword->setText(QCoreApplication::translate("Window::FtpWidget", "Password: ", nullptr));
        editPort->setText(QCoreApplication::translate("Window::FtpWidget", "21", nullptr));
        btnLoginOK->setText(QCoreApplication::translate("Window::FtpWidget", "OK", nullptr));
        btnLoginClose->setText(QCoreApplication::translate("Window::FtpWidget", "Close", nullptr));
    } // retranslateUi

};

} // namespace Window

namespace Window {
namespace Ui {
    class FtpWidget: public Ui_FtpWidget {};
} // namespace Ui
} // namespace Window

#endif // UI_FTPWIDGET_H
