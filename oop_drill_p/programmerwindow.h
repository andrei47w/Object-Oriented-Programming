#ifndef PROGRAMMERWINDOW_H
#define PROGRAMMERWINDOW_H

#include <QMainWindow>
#include "read_file.h"
#include "TableModel.h"

namespace Ui {
class ProgrammerWindow;
}

class ProgrammerWindow : public QMainWindow
{
    Q_OBJECT


private slots:

    void on_Revise_clicked();

    void on_Add_clicked();

public:
    void update_titles();
    int index;
    std::vector<std::string> programmer;
    explicit ProgrammerWindow(QWidget *parent = nullptr);
    ~ProgrammerWindow();

private:
    Ui::ProgrammerWindow *ui;
    Repository f_repo = Repository("sources.txt");
    Repository p_repo = Repository("programmers.txt");
    TableModel *myModel;


    void showTable();
};

#endif // PROGRAMMERWINDOW_H
