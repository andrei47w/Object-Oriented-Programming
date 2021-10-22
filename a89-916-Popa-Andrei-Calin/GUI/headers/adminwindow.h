#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <Tutorial.h>
#include <Controller.h>
#include <CSVRepo.h>


namespace Ui {
    class AdminWindow;
}

class AdminWindow : public QDialog {
Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0, CSVRepo *repo = nullptr, Controller *ctrl = nullptr);

    ~AdminWindow();

private slots:

    void on_Add_clicked();

    void on_Remove_clicked();

    void on_Update_clicked();

    void on_Diagram_clicked();

private:
    Ui::AdminWindow *ui;
    CSVRepo *repo;
    Controller *ctrl;

    std::string displayAllTutorialsRepo();

    std::string printTutorial(const Tutorial &t, bool flag);

    void updateList();
};

#endif // ADMINWINDOW_H
