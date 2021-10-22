#ifndef UI_PROGRAMMERWINDOW_H
#define UI_PROGRAMMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <QTableView>

QT_BEGIN_NAMESPACE

class Ui_ProgrammerWindow
{
public:
    QWidget *centralwidget;
    QLabel *revised_files;
    QLabel *unrevised_files;
    QPushButton *Revise;
    QPushButton *Add;
    QLineEdit *File_name;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QTableView *tableView;

    void setupUi(QMainWindow *ProgrammerWindow)
    {
        if (ProgrammerWindow->objectName().isEmpty())
            ProgrammerWindow->setObjectName(QString::fromUtf8("ProgrammerWindow"));
        ProgrammerWindow->resize(720, 480);
        centralwidget = new QWidget(ProgrammerWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        revised_files = new QLabel(centralwidget);
        revised_files->setObjectName(QString::fromUtf8("revised_files"));
        revised_files->setGeometry(QRect(10, 10, 131, 21));
        unrevised_files = new QLabel(centralwidget);
        unrevised_files->setObjectName(QString::fromUtf8("unrevised_files"));
        unrevised_files->setGeometry(QRect(160, 10, 131, 21));
        Revise = new QPushButton(centralwidget);
        Revise->setObjectName(QString::fromUtf8("Revise"));
        Revise->setGeometry(QRect(10, 410, 80, 21));
        Add = new QPushButton(centralwidget);
        Add->setObjectName(QString::fromUtf8("Add"));
        Add->setGeometry(QRect(400, 410, 80, 21));
        File_name = new QLineEdit(centralwidget);
        File_name->setObjectName(QString::fromUtf8("File_name"));
        File_name->setGeometry(QRect(490, 410, 221, 21));
        ProgrammerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProgrammerWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 720, 20));
        ProgrammerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ProgrammerWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ProgrammerWindow->setStatusBar(statusbar);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 40, 701, 361));
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        retranslateUi(ProgrammerWindow);

        QMetaObject::connectSlotsByName(ProgrammerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ProgrammerWindow)
    {
        ProgrammerWindow->setWindowTitle(QApplication::translate("ProgrammerWindow", "programmer_name", nullptr));
        revised_files->setText(QApplication::translate("ProgrammerWindow", "revised files:", nullptr));
        unrevised_files->setText(QApplication::translate("ProgrammerWindow", "files not revised:", nullptr));
        Revise->setText(QApplication::translate("ProgrammerWindow", "Revise", nullptr));
        Add->setText(QApplication::translate("ProgrammerWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgrammerWindow: public Ui_ProgrammerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMERWINDOW_H
