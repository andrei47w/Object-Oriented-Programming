
#pragma once

#include "Controller.h"

class UI {
private:
    Controller ctrl;

public:
    UI(const Controller &c) : ctrl(c) {}
    //~UI();

    void run();

private:
    static void printMenu();

    void addToRepo();

    void deleteFromRepo();

    void updateFromRepo();

    void displayAll();

    static void print(const List &t, bool flag = true);
};

