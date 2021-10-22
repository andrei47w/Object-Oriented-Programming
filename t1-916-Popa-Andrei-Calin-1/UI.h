//
// Created by Andrei on 4/4/2021.
//


#pragma once

#include <vector>
#include "Controller.h"

class UI {
private:
    Controller ctrl;

public:
    UI(const Controller &c) : ctrl(c) {}
    //~UI();

    void run();

private:

    void addGene();


    static void printGene(const Gene &t, int length);

    void searchGenes();

    void sortGenes();

    void sort(std::vector<std::string> s, int n, int length);

    void commonSeq();

    int LCS(std::string X, std::string Y, int m, int n);

    void printMenu();
};
