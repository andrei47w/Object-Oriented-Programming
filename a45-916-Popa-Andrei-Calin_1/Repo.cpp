
#include "headers/Repo.h"


bool Repository::add(const List &t) {
    List tut = findBy(t.getPresenter(), t.getTitle());
    if (!tut.getPresenter().empty() || !tut.getSource().empty())
        return false;
    this->list.add(t);
    return true;
}


List Repository::findBy(const std::string &presenter, const std::string &title) {
    List *tutorialsInDynamicVector = this->list.getAllElems();

    for (int i = 0; i < this->list.getSize(); i++) {
        List s = tutorialsInDynamicVector[i];
        if (s.getPresenter() == presenter && s.getTitle() == title)
            return s;
    }

    return List{};
}


bool Repository::remove(const std::string &presenter, const std::string &title) {
    List t = this->findBy(presenter, title);
    if (t.getPresenter().empty() && t.getTitle().empty())
        return false;
    int pos = this->findPos(t);
    this->list.deleteElem(pos);
    return true;
}

int Repository::findPos(const List &t) {
    for (int i = 0; i < this->list.getSize(); i++) {
        if (this->list[i].getPresenter() == t.getPresenter() && this->list[i].getTitle() == t.getTitle())
            return i;
    }
    return -1;
}


