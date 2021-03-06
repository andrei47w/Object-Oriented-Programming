//
// Created by Andrei on 4/13/2021.
//

#include "headers/Repo.h"
#include <vector>
#include <algorithm>

Repository::Repository() {
    tutorials = new std::vector<Tutorial>();
}

Repository::~Repository() {
    delete tutorials;
}

Repository::Repository(const Repository &r) {
    tutorials = new std::vector<Tutorial>();

    for (auto &it : *(r.tutorials)) {
        tutorials->push_back(it);
    }
}

Repository &Repository::operator=(const Repository &r) {
    tutorials = new std::vector<Tutorial>();

    for (auto &it : *(r.tutorials)) {
        tutorials->push_back(it);
    }
    return *this;
}

bool Repository::addTutorial(const Tutorial &t) {
    Tutorial tut = findByPresenterAndTitle(t.getPresenter(), t.getTitle());
    if (tut.getPresenter() != "" || tut.getSource() != "")
        throw RepositoryException(
                "Cannot add tutorial: The given tutorial already exists (presenter and title are already given)");
    this->tutorials->push_back(t);
    return true;
}


Tutorial Repository::findByPresenterAndTitle(const std::string &presenter, const std::string &title) {
    auto it = std::find_if(this->tutorials->begin(), this->tutorials->end(), [&presenter, &title](const Tutorial &obj) {
        return obj.getPresenter() == presenter && obj.getTitle() == title;
    });
    if (it == this->tutorials->end())
        return Tutorial{};
    return *it;
}


bool Repository::removeTutorial(const std::string &presenter, const std::string &title) {
    Tutorial t = this->findByPresenterAndTitle(presenter, title);
    if (t.getPresenter() == "" && t.getTitle() == "")
        throw RepositoryException("Cannot find the given tutorial");
    int pos = this->findPosOfTutorial(t);
    this->tutorials->erase(this->tutorials->begin() + pos);
    return true;
}

int Repository::findPosOfTutorial(const Tutorial &t) {
    Tutorial ts = findByPresenterAndTitle(t.getPresenter(), t.getTitle());
    if (ts.getPresenter() != "")
        return std::distance(this->tutorials->begin(), std::find(this->tutorials->begin(), this->tutorials->end(), ts));
    return -1;
}



