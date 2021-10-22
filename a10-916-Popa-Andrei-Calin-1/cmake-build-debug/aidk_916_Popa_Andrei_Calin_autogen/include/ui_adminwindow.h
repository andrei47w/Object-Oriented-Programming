/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *Add;
    QPushButton *Remove;
    QPushButton *Update;

    void setupUi(QDialog *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->resize(720, 480);
        scrollArea = new QScrollArea(AdminWindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 701, 431));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 699, 429));
        scrollArea->setWidget(scrollAreaWidgetContents);
        Add = new QPushButton(AdminWindow);
        Add->setObjectName(QString::fromUtf8("Add"));
        Add->setGeometry(QRect(10, 450, 80, 21));
        Remove = new QPushButton(AdminWindow);
        Remove->setObjectName(QString::fromUtf8("Remove"));
        Remove->setGeometry(QRect(100, 450, 80, 21));
        Update = new QPushButton(AdminWindow);
        Update->setObjectName(QString::fromUtf8("Update"));
        Update->setGeometry(QRect(190, 450, 80, 21));

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "Admin Mode", nullptr));
        Add->setText(QApplication::translate("AdminWindow", "Add", nullptr));
        Remove->setText(QApplication::translate("AdminWindow", "Remove", nullptr));
        Update->setText(QApplication::translate("AdminWindow", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
