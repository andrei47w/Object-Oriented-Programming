
#pragma once

#include "DynamicVector.h"
#include "List.h"

class Repository {
private:
    DynamicVector <List> list;

public:
    Repository() {}

    bool add(const List &t);

    List findBy(const std::string &presenter, const std::string &title);

    DynamicVector <List> getTutorials() { return list; }

    bool remove(const std::string &presenter, const std::string &title);

    int findPos(const List &t);
};