
#include "headers/Controller.h"

bool Controller::add(const std::string& presenter, const std::string& title, double noLikes, const std::string& source, double d)
{
    List t{title, presenter, noLikes, source };
    return this->repo.add(t);
}

bool Controller::remove(const std::string & presenter, const std::string & title)
{
    return this->repo.remove(presenter, title);
}

bool Controller::update(const std::string & presenter, const std::string & title, double noLikes, const std::string & source, const std::string newName, const std::string newTitle)
{
    List t = this->repo.findBy(presenter, title);
    if (t.getPresenter() == "" || t.getTitle() == "")
        return false;
    List newT = this->repo.findBy(newName, newTitle);
    if ((newT.getPresenter() != "" || newT.getTitle() != "") && (newName != presenter && newTitle != title))
        return false;
    this->remove(presenter, title);
    this->add(newName, newTitle, noLikes, source);

    return true;
}


void Controller::configIterator(const std::string & presenter)
{
    this->Iter.emptyIterator();
    DynamicVector<List> s = this->repo.getTutorials();
    if (presenter.size() == 0) {
        for (int i = 0; i < s.getSize(); i++) {
            this->Iter.add(s[i]);
        }
    }
    else {
        for (int i = 0; i < s.getSize(); i++) {
            if (s[i].getPresenter()==presenter)
                this->Iter.add(s[i]);
        }
    }
}

List Controller::getCurrentTutorial()
{
    return this->Iter.getCurrent();
}



void Controller::startIteration() {
    this->Iter.open();
}
