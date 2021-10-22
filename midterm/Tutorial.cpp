//
// Created by Andrei on 4/4/2021.
//

#include "Tutorial.h"


Tutorial::Tutorial() : title(""), presenter(""), duration(Duration()), numberOfLikes(int(0)), source(""), noViews(0) {}


Tutorial::Tutorial(const std::string &title, const std::string &presenter, const Duration &duration,
                   const double &noLikes, const std::string &source, const double &noViews) {
    this->title = title;
    this->presenter = presenter;
    this->duration = duration;
    this->numberOfLikes = noLikes;
    this->source = source;
    this->noViews = noViews;
}

bool Tutorial::operator<(int value) {
    return this->noViews < value;
}

void Tutorial::like() {
    this->numberOfLikes++;
}