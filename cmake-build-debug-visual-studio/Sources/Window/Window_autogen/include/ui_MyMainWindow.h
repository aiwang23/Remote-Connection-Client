/********************************************************************************
** Form generated from reading UI file 'mymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

namespace Window {

class Ui_MyMainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidgetMain;
    QWidget *tab;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *labelRecentConnect;
    QSpacerItem *verticalSpacer_2;
    QListWidget *listWidgetRecentConnect;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window__MyMainWindow)
    {
        if (Window__MyMainWindow->objectName().isEmpty())
            Window__MyMainWindow->setObjectName("Window__MyMainWindow");
        Window__MyMainWindow->resize(636, 514);
        centralwidget = new QWidget(Window__MyMainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidgetMain = new QTabWidget(centralwidget);
        tabWidgetMain->setObjectName("tabWidgetMain");
        tabWidgetMain->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        labelRecentConnect = new QLabel(tab);
        labelRecentConnect->setObjectName("labelRecentConnect");

        gridLayout->addWidget(labelRecentConnect, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        listWidgetRecentConnect = new QListWidget(tab);
        listWidgetRecentConnect->setObjectName("listWidgetRecentConnect");

        gridLayout->addWidget(listWidgetRecentConnect, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 2, 1);

        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 10);
        gridLayout->setColumnStretch(1, 10);
        tabWidgetMain->addTab(tab, QString());

        horizontalLayout->addWidget(tabWidgetMain);

        Window__MyMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window__MyMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 636, 22));
        Window__MyMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Window__MyMainWindow);
        statusbar->setObjectName("statusbar");
        Window__MyMainWindow->setStatusBar(statusbar);

        retranslateUi(Window__MyMainWindow);

        tabWidgetMain->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Window__MyMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *Window__MyMainWindow)
    {
        Window__MyMainWindow->setWindowTitle(QCoreApplication::translate("Window::MyMainWindow", "MyMainWindow", nullptr));
        labelRecentConnect->setText(QCoreApplication::translate("Window::MyMainWindow", "\346\234\200\350\277\221\350\277\236\346\216\245: ", nullptr));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab), QCoreApplication::translate("Window::MyMainWindow", "\346\234\200\350\277\221\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

} // namespace Window

namespace Window {
namespace Ui {
    class MyMainWindow: public Ui_MyMainWindow {};
} // namespace Ui
} // namespace Window

#endif // UI_MYMAINWINDOW_H
