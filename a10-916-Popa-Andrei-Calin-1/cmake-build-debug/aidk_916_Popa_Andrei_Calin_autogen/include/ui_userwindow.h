/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QPushButton *Add;
    QPushButton *Remove;
    QPushButton *Like;
    QPushButton *Next;
    QPushButton *Open;
    QScrollArea *watchlist;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *current_tutorial;
    QWidget *scrollAreaWidgetContents_2;

    void setupUi(QDialog *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
        UserWindow->resize(720, 480);
        Add = new QPushButton(UserWindow);
        Add->setObjectName(QString::fromUtf8("Add"));
        Add->setGeometry(QRect(10, 450, 81, 21));
        Remove = new QPushButton(UserWindow);
        Remove->setObjectName(QString::fromUtf8("Remove"));
        Remove->setGeometry(QRect(100, 450, 80, 21));
        Like = new QPushButton(UserWindow);
        Like->setObjectName(QString::fromUtf8("Like"));
        Like->setGeometry(QRect(190, 450, 80, 21));
        Next = new QPushButton(UserWindow);
        Next->setObjectName(QString::fromUtf8("Next"));
        Next->setGeometry(QRect(630, 450, 80, 21));
        Open = new QPushButton(UserWindow);
        Open->setObjectName(QString::fromUtf8("Open"));
        Open->setGeometry(QRect(280, 450, 80, 21));
        watchlist = new QScrollArea(UserWindow);
        watchlist->setObjectName(QString::fromUtf8("watchlist"));
        watchlist->setGeometry(QRect(10, 10, 701, 391));
        watchlist->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 699, 389));
        watchlist->setWidget(scrollAreaWidgetContents);
        current_tutorial = new QScrollArea(UserWindow);
        current_tutorial->setObjectName(QString::fromUtf8("current_tutorial"));
        current_tutorial->setGeometry(QRect(10, 410, 701, 31));
        current_tutorial->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 699, 29));
        current_tutorial->setWidget(scrollAreaWidgetContents_2);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QDialog *UserWindow)
    {
        UserWindow->setWindowTitle(QApplication::translate("UserWindow", "User Mode", nullptr));
        Add->setText(QApplication::translate("UserWindow", "Add", nullptr));
        Remove->setText(QApplication::translate("UserWindow", "Remove", nullptr));
        Like->setText(QApplication::translate("UserWindow", "Like", nullptr));
        Next->setText(QApplication::translate("UserWindow", "Next", nullptr));
        Open->setText(QApplication::translate("UserWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
