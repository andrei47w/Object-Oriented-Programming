//
// Created by Andrei on 4/26/2021.
//

#include <iostream>
#include "UI.h"

void UI::addMeasurement() {
    std::string cmd;
    double BMI;
    int BP;
    std::cout << "specify which type of data you want to read (BMI, BP)";
    if (cmd == "BMI") {
        std::cin >> BMI;
    }
    else if (cmd == "BP") {
        std::cin >> BP;
    }

    std::cout << "Give date: ";
    std::cin >> cmd;
    if(cmd.size() == 10) {

    }

    this->pers->addMeasurement(this->serv->createBMIMeasurement(cmd, BMI));
}

void UI::display() {
    std::vector<Measurement> list = this->pers->getAll();

    if (list.empty()) {
        std::cout << "There are no measurements yet." << std::endl;
        return;
    }

    std::cout << this->pers->toString();
}

void UI::run() {
    std::cout << "Give name: ";
    std::string name;
    std::cin >> name;
    Person();
    this->pers->name = name;
    std::cout<<"Give command: ";
    while (true) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "0") return;
        else if(cmd == "1") this->addMeasurement();
        else if(cmd == "2") this->display();
    }
}