//
// Created by Andrei on 4/4/2021.
//

#include "Gene.h"


Gene::Gene() : name(""), organism(""), sequence() {}


Gene::Gene(const std::string &org, const std::string &name, const std::string &seq) {
    this->organism = org;
    this->name = name;
    this->sequence = seq;
}
