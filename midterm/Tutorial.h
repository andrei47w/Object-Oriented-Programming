//
// Created by Andrei on 4/4/2021.
//
#pragma once
#pragma once

#include <iostream>

class Duration {
private:
    double minutes;
    double seconds;
public:
    // default constructor
    Duration() : minutes(0), seconds(0) {};

    // constructor
    Duration(double min, double sec) : minutes(min), seconds(sec) {};

    double getMinutes() const { return minutes; }

    double getSeconds() const { return seconds; }

    void setMinutes(double min) { minutes = min; }

    void setSeconds(double sec) { seconds = sec; }
};

class Tutorial {
private:
    std::string title;
    std::string presenter;
    Duration duration;
    long numberOfLikes;
    std::string source;
    long noViews;
public:
    // default constructor
    Tutorial();

    // constructor
    Tutorial(const std::string &title, const std::string &presenter, const Duration &duration, const double &noLikes,
             const std::string &source, const double &noViews = 0);

    std::string getTitle() const { return title; }

    std::string getPresenter() const { return presenter; }

    Duration getDuration() const { return duration; }

    std::string getSource() const { return source; }

    double getNoLikes() const { return numberOfLikes; }

    long getNoViews() const { return noViews; }

    void open();

    bool operator<(int value);

    void like();
};