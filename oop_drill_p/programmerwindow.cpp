#include <iostream>
#include <QMessageBox>
#include "programmerwindow.h"
#include "ui_programmerwindow.h"
#include "TableModel.h"
#include <C:/Qt/5.12.2/mingw73_32/include/QtSql/QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <C:/Qt/5.12.2/mingw73_32/include/QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>

ProgrammerWindow::ProgrammerWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::ProgrammerWindow) {
    ui->setupUi(this);
    Repository *temp_repo = &f_repo;
    myModel = new TableModel{temp_repo};
    ui->tableView->setModel(myModel);
//    showTable();
}

ProgrammerWindow::~ProgrammerWindow() {
    delete ui;
}

void ProgrammerWindow::update_titles() {
    programmer = p_repo.get_elem()[index];
    ui->revised_files->setText(QString::fromStdString("revised files: " + programmer[1]));
    ui->unrevised_files->setText(QString::fromStdString(
            "files not revised: " + std::to_string(std::stoi(programmer[2]) - std::stoi(programmer[1]))));
    setWindowTitle(QApplication::translate("ProgrammerWindow", programmer[0].c_str(), nullptr));
}

void ProgrammerWindow::on_Revise_clicked() {
    if (std::stoi(programmer[2]) - std::stoi(programmer[1]) > 0) {
        programmer[1] = std::to_string(std::stoi(programmer[1]) + 1);
//        p_repo->elem[index][1] = programmer[1];
        ui->revised_files->setText(QString::fromStdString("revised files: " + programmer[1]));

        ui->unrevised_files->setText(QString::fromStdString(
                "files not revised: " + std::to_string(std::stoi(programmer[2]) - std::stoi(programmer[1]))));
    }
    if (std::stoi(programmer[2]) - std::stoi(programmer[1]) <= 0) {
        QMessageBox messageBox;
        messageBox.information(0, "Alert", "Congratulations!");
    }


}

void ProgrammerWindow::on_Add_clicked() {
    if (ui->File_name->text().isEmpty()) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Invalid name!");
        return;
    }

    for (int i = 0; i < f_repo.get_elem().size(); i++)
        if (ui->File_name->text().toUtf8().constData() == f_repo.get_elem()[i][0]) {
            QMessageBox messageBox;
            messageBox.critical(0, "Error", "Invalid name!");
            return;
        }

    f_repo.add_elem(ui->File_name->text().toUtf8().constData(), "not_revised", programmer[0], "");
    myModel->addTableToRepository(ui->File_name->text().toUtf8().constData(), "not_revised", programmer[0], "");
//    showTable();
}

void ProgrammerWindow::showTable() {
    for (int i = 0; i < f_repo.get_elem().size(); i++) {
//        myModel->setData(myModel->index(i, 0), QString::fromStdString(f_repo.get_elem()[i][0]));
//        myModel->setData(myModel->index(i, 1), QString::fromStdString(f_repo.get_elem()[i][2]));
//        myModel->setData(myModel->index(i, 2), QString::fromStdString(f_repo.get_elem()[i][3]));
    }
}