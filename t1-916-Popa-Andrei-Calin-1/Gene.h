//
// Created by Andrei on 4/4/2021.
//
#pragma once
#pragma once

#include <iostream>

class Gene {
private:
    std::string name;
    std::string organism;
    std::string sequence;

public:
    // default constructor
    Gene();

    // constructor
    Gene(const std::string &organism, const std::string &name, const std::string &sequence);

    std::string getName() const { return name; }

    std::string getOrganism() const { return organism; }

    std::string getSequence() const { return sequence; }
};