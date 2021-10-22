#include <iostream>
#include "GUI/headers/userwindow.h"
#include "GUI/ui_headers/ui_userwindow.h"

UserWindow::UserWindow(QWidget *parent, CSVRepo *repo, Controller *ctrl) :
        QDialog(parent),
        ui(new Ui::UserWindow) {
    ui->setupUi(this);
    this->repo = repo;
    this->ctrl = ctrl;
    this->updateList();
    this->ctrl->configIterator("");
    ui->textBrowser_2->setText(QString::fromUtf8(this->printTutorial(this->ctrl->getCurrentTutorial(), false).c_str()));
}


UserWindow::~UserWindow() {
    this->repo->update_write();
    delete ui;
}

void UserWindow::on_Add_clicked() {
    try {
        this->ctrl->addTutorialToWatchlist(this->ctrl->getCurrentTutorial());
        this->updateList();
    }
    catch (RepositoryException &v) {}

}


void UserWindow::on_Remove_clicked() {
    try {
        this->ctrl->deleteTutorialFromWatchlist(this->ctrl->getCurrentTutorial());
        this->updateList();
    }
    catch (RepositoryException &v) {}
}


void UserWindow::on_Like_clicked() {
    this->ctrl->likeTutorial();
    ui->textBrowser_2->setText(QString::fromUtf8(this->printTutorial(this->ctrl->getCurrentTutorial(), false).c_str()));
    this->repo->update_write();
    try {
        this->ctrl->deleteTutorialFromWatchlist(this->ctrl->getCurrentTutorial());
        this->ctrl->addTutorialToWatchlist(this->ctrl->getCurrentTutorial());
    }
    catch(...){}
    this->updateList();
}


void UserWindow::on_Open_clicked() {
    this->ctrl->getCurrentTutorial().open();
}

void UserWindow::on_OpenList_clicked() {
    this->ctrl->display();
}


void UserWindow::on_Next_clicked() {
    this->ctrl->next();
    ui->textBrowser_2->setText(QString::fromUtf8(this->printTutorial(this->ctrl->getCurrentTutorial(), false).c_str()));
}

void UserWindow::on_Search_clicked() {
    std::string search = ui->SearchText->toPlainText().toStdString();

    if (search.empty()) {
        this->ctrl->configIterator("");
        ui->textBrowser_2->setText(
                QString::fromUtf8(this->printTutorial(this->ctrl->getCurrentTutorial(), false).c_str()));
    }
    this->ctrl->configIterator(search);
    if (this->ctrl->getCurrentTutorial().getPresenter().empty()) {
        ui->textBrowser_2->setText("");
        return;
    }
    ui->textBrowser_2->setText(QString::fromUtf8(this->printTutorial(this->ctrl->getCurrentTutorial(), false).c_str()));
}

std::string UserWindow::printTutorial(const Tutorial &t, bool flag) {
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
    return tutorials;
}

void UserWindow::updateList() {
    ui->textBrowser->setText(QString::fromUtf8(this->viewWatchlist().c_str()));
}

std::string UserWindow::viewWatchlist() {
    std::vector<Tutorial> *v = this->ctrl->getWatchlist()->getTutorials();
    std::string list;
    if (v->empty()) {
        list += "There are no tutorials in the watchlist.";
        return list;
    }

    list += "|____PRESENTER______|________________________TITLE_________________________|_LIKES_|_DURATION\n";
    int i = 0;
    for (auto &it : *v) {
        list += this->printTutorial(it, false);
        list += '\n';
        i++;
    }
    return list;
}