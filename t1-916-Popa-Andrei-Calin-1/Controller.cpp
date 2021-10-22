//
// Created by Andrei on 4/4/2021.
//

#include "Controller.h"

bool Controller::add(const std::string& organism, const std::string& name, const std::string& sequence)
{
    Gene t{organism, name, sequence};
    return this->repo.add(t);
}

