//
// Created by Andrei on 4/26/2021.
//
#include "person.cpp"

class UI {
private:
    Person *pers;
    Service *serv;
    Measurement *meas;

public:
    void run();

private:

    void addMeasurement();

    void display();
};