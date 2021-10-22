
#pragma once

#include "Repo.h"
#include "Iterator.h"

class Controller {
    Repository repo;
    Iterator Iter;
public:
    Controller(const Repository& r) : repo{ r }, Iter() {}

    Repository getRepo() const { return repo; }

    bool add(const std::string &presenter, const std::string &title,
             double noLikes, const std::string &source, double d = 0);


    bool remove(const std::string &presenter, const std::string &title);

    bool
    update(const std::string &presenter, const std::string &title,
           double noLikes, const std::string &source, const std::string newName,
           const std::string newTitle);


    void configIterator(const std::string & presenter);

    List getCurrentTutorial();

    void startIteration();
};

