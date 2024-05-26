/********************************************************************************
** Form generated from reading UI file 'mylistdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLISTDIALOG_H
#define UI_MYLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>

namespace Window {

class Ui_MyListDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *Window__MyListDialog)
    {
        if (Window__MyListDialog->objectName().isEmpty())
            Window__MyListDialog->setObjectName("Window__MyListDialog");
        Window__MyListDialog->resize(465, 377);
        gridLayout = new QGridLayout(Window__MyListDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        label = new QLabel(Window__MyListDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        listWidget = new QListWidget(Window__MyListDialog);
        listWidget->setObjectName("listWidget");

        gridLayout->addWidget(listWidget, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 10);
        gridLayout->setColumnStretch(1, 10);

        retranslateUi(Window__MyListDialog);

        QMetaObject::connectSlotsByName(Window__MyListDialog);
    } // setupUi

    void retranslateUi(QDialog *Window__MyListDialog)
    {
        Window__MyListDialog->setWindowTitle(QCoreApplication::translate("Window::MyListDialog", "MyListDialog", nullptr));
        label->setText(QCoreApplication::translate("Window::MyListDialog", "\350\257\267\351\200\211\346\213\251\344\270\200\347\247\215\350\277\236\346\216\245\346\226\271\345\274\217: ", nullptr));
    } // retranslateUi

};

} // namespace Window

namespace Window {
namespace Ui {
    class MyListDialog: public Ui_MyListDialog {};
} // namespace Ui
} // namespace Window

#endif // UI_MYLISTDIALOG_H
