//
// Created by Andrei on 4/4/2021.
//


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

};
