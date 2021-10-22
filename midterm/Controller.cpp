//
// Created by Andrei on 4/4/2021.
//

#include "Controller.h"

bool Controller::add(const std::string& presenter, const std::string& title, double minutes, double seconds, double noLikes, const std::string& source, double noViews)
{
    Tutorial t{ title, presenter, Duration{ minutes, seconds },noLikes, source };
    return this->repo.add(t);
}

bool Controller::remove(const std::string & presenter, const std::string & title)
{
    return this->repo.remove(presenter, title);
}

bool Controller::update(const std::string & presenter, const std::string & title, double minutes, double seconds, double noLikes, const std::string & source, const std::string newName, const std::string newTitle)
{
    Tutorial t = this->repo.findBy(presenter, title);
    if (t.getPresenter() == "" || t.getTitle() == "")
        return false;
    Tutorial newT = this->repo.findBy(newName, newTitle);
    if ((newT.getPresenter() != "" || newT.getTitle() != "") && (newName != presenter && newTitle != title))
        return false;
    this->remove(presenter, title);
    this->add(newName, newTitle, minutes, seconds, noLikes, source);

    return true;
}
