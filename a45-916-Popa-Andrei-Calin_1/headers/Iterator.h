
#pragma once

#include "DynamicVector.h"
#include "List.h"

class Iterator {
private:
    DynamicVector<List> tutorials;
    int current;
public:
    Iterator();

    void add(const List &t);

    List getCurrent();

    void open();

    void next();

    bool isEmpty();

    void emptyIterator();
};
