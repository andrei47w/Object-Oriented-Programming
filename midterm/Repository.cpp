//
// Created by Andrei on 4/4/2021.
//

#include "Repository.h"


bool Repository::add(const Tutorial &t) {
    Tutorial tut = findBy(t.getPresenter(), t.getTitle());
    if (!tut.getPresenter().empty() || !tut.getSource().empty())
        return false;
    this->tutorials.add(t);
    return true;
}


Tutorial Repository::findBy(const std::string &presenter, const std::string &title) {
    Tutorial *tutorialsInDynamicVector = this->tutorials.getAllElems();

    for (int i = 0; i < this->tutorials.getSize(); i++) {
        Tutorial s = tutorialsInDynamicVector[i];
        if (s.getPresenter() == presenter && s.getTitle() == title)
            return s;
    }

    return Tutorial{};
}


bool Repository::remove(const std::string &presenter, const std::string &title) {
    Tutorial t = this->findBy(presenter, title);
    if (t.getPresenter().empty() && t.getTitle().empty())
        return false;
    int pos = this->findPos(t);
    this->tutorials.deleteElem(pos);
    return true;
}

int Repository::findPos(const Tutorial &t) {
    for (int i = 0; i < this->tutorials.getSize(); i++) {
        if (this->tutorials[i].getPresenter() == t.getPresenter() && this->tutorials[i].getTitle() == t.getTitle())
            return i;
    }
    return -1;
}


