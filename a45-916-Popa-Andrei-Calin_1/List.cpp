
#include "headers/List.h"
#include <Windows.h>
#include <shellapi.h>

List::List() : title(""), presenter(""), numberOfLikes(int(0)), source(""), noViews(0) {}


List::List(const std::string &title, const std::string &presenter,
           const double &noLikes, const std::string &source, const double &noViews) {
    this->title = title;
    this->presenter = presenter;
    this->numberOfLikes = noLikes;
    this->source = source;
    this->noViews = noViews;
}


bool List::operator<(int value) {
    return this->noViews < value;
}

void List::like() {
    this->numberOfLikes++;
}