
#pragma once
#pragma once

#include <iostream>


class List {
private:
    std::string title;
    std::string presenter;
    long numberOfLikes;
    std::string source;
    long noViews;
public:
    // default constructor
    List();

    // constructor
    List(const std::string &title, const std::string &presenter, const double &noLikes,
         const std::string &source, const double &noViews = 0);

    std::string getTitle() const { return title; }

    std::string getPresenter() const { return presenter; }

    std::string getSource() const { return source; }

    double getNoLikes() const { return numberOfLikes; }

    long getNoViews() const { return noViews; }

    bool operator<(int value);

    void like();
};
