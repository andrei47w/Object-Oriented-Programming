
#include "headers/Iterator.h"

Iterator::Iterator() {
    this->current = 0;
}

void Iterator::add(const List &tut) {
    this->tutorials.add(tut);
}

List Iterator::getCurrent() {
    if (this->current == this->tutorials.getSize())
        this->current = 0;
    return this->tutorials[this->current];
}

void Iterator::open() {
    if (this->tutorials.getSize() == 0)
        return;
    this->current = 0;
    List currentTutorial = this->getCurrent();
}

void Iterator::next() {
    if (this->tutorials.getSize() == 0)
        return;

    this->current++;
    List currentTut = this->getCurrent();
}

bool Iterator::isEmpty() {
    return this->tutorials.getSize() == 0;
}

void Iterator::emptyIterator() {
    while (!this->isEmpty())
        this->tutorials.deleteElem(0);
}