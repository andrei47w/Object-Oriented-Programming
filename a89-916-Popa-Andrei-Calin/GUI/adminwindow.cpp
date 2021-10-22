#include <Tutorial.h>
#include <QMessageBox>
#include <headers/diagram.h>
#include "GUI/headers/adminwindow.h"
#include "GUI/ui_headers/ui_adminwindow.h"
#include "GUI/headers/adminadddialog.h"
#include "GUI/headers/adminremovedialog.h"
#include "GUI/headers/adminupdatedialog.h"

AdminWindow::AdminWindow(QWidget *parent, CSVRepo *repo, Controller *ctrl) :
        QDialog(parent),
        ui(new Ui::AdminWindow) {
    ui->setupUi(this);

    this->repo = repo;
    this->ctrl = ctrl;

    updateList();
}

AdminWindow::~AdminWindow() {
    delete ui;
}

void AdminWindow::updateList() {
    ui->textBrowser->setText(QString::fromUtf8(this->displayAllTutorialsRepo().c_str()));
}

void AdminWindow::on_Diagram_clicked() {
    auto *repo = new CSVRepo("..//input files//tutorials.txt");
    Diagram *d = new Diagram(0, repo);
    d->exec();
}

void AdminWindow::on_Add_clicked() {
    AdminAddDialog d;
    if (d.exec() == QDialog::Accepted) {
        std::string pres = d.getPres();
        std::string title = d.getTitle();
        std::string link = d.getLink();
        int likes = d.getLikes();
        int views = d.getViews();
        int min = d.getMinutes();
        int sec = d.getSeconds();
        if (title.empty() || pres.empty()) {
            QMessageBox::critical(window(), "Error", "Title or presenter cannot be empty!");
            return;
        }
        try {
            Tutorial t = Tutorial{title, pres, Duration(min, sec), likes, link, views};
            this->ctrl->addTutorialToRepository(t);
        }
        catch (RepositoryException &v) {
            QMessageBox::critical(window(), "Error", v.what());
        }
        catch (ValidationException &v) {
            QMessageBox::critical(window(), "Error", v.what());
        }
        updateList();
        this->repo->update_write();
    }
}


void AdminWindow::on_Remove_clicked() {
    AdminRemoveDialog d;
    if (d.exec() == QDialog::Accepted) {
        std::string pres = d.getPres();
        std::string title = d.getTitle();
        std::cout << pres << title;

        try {
            this->ctrl->removeTutorialFromRepository(pres, title);
        }
        catch (RepositoryException &r) {
            QMessageBox::critical(window(), "Error", r.what());
        }
        updateList();
        this->repo->update_write();
    }
}


void AdminWindow::on_Update_clicked() {
    AdminUpdateDialog d;
    if (d.exec() == QDialog::Accepted) {
        std::string old_pres = d.getOldPres();
        std::string old_title = d.getOldTitle();
        std::string pres = d.getPres();
        std::string title = d.getTitle();
        std::string link = d.getLink();
        int likes = d.getLikes();
        int views = d.getViews();
        int min = d.getMinutes();
        int sec = d.getSeconds();
        if (title.empty() || pres.empty() || old_title.empty() || old_pres.empty()) {
            QMessageBox::critical(window(), "Error", "Title or presenter cannot be empty!");
            return;
        }
        try {
            Tutorial t = Tutorial{title, pres, Duration(min, sec), likes, link, views};
            this->ctrl->updateTutorialFromRepository(old_pres,old_title,t);
        }
        catch (RepositoryException &v) {
            QMessageBox::critical(window(), "Error", v.what());
        }
        catch (ValidationException &v) {
            QMessageBox::critical(window(), "Error", v.what());
        }
        updateList();
        this->repo->update_write();
    }

}


std::string AdminWindow::printTutorial(const Tutorial &t, bool flag) {
    std::string tutorials;

    Duration d = t.getDuration();
    tutorials += "| ";
    tutorials += t.getPresenter();
    for (int i = 1; i <= 18 - t.getPresenter().length(); i++) tutorials += " ";

    tutorials += "| ";
    tutorials += t.getTitle();
    for (int i = 1; i <= 53 - t.getTitle().length(); i++) tutorials += " ";

    tutorials += "| ";
    tutorials += std::to_string(t.getNoLikes());
    int length = 1;
    int x = (int) t.getNoLikes();
    while (x != 0) {
        length++;
        x /= 10;
    }
    for (int i = 1; i <= 7 - length; i++) tutorials += " ";

    tutorials += "| ";
    tutorials += std::to_string(d.getMinutes());
    tutorials += ":";
    tutorials += std::to_string(d.getSeconds());
    length = 1;
    x = (int) d.getMinutes();
    while (x != 0) {
        length++;
        x /= 10;
    }
    x = (int) d.getSeconds();
    while (x != 0) {
        length++;
        x /= 10;
    }
    length++;
    for (int i = 1; i <= 10 - length; i++) tutorials += " ";

    if (flag) {
        tutorials += "| ";
        tutorials += std::to_string(t.getNoViews());
    }
    tutorials += '\n';
    return tutorials;
}

std::string AdminWindow::displayAllTutorialsRepo() {
    std::vector<Tutorial> *v = this->ctrl->getRepo()->getTutorials();
    if (v->empty()) {
        return nullptr;
    }
    std::string string = "\nNO.|____PRESENTER______|________________________TITLE_________________________|_LIKES_|_DURATION_|_VIEWS\n";
    int i = 1;
    for (auto &it : *v) {
        string += std::to_string(i);
        string += "  ";
        string += AdminWindow::printTutorial(it, true);
        i++;
    }
    return string;
}