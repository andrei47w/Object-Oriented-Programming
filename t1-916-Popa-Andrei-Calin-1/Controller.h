//
// Created by Andrei on 4/4/2021.
//

#pragma once
#include "Repository.h"

class Controller {
    Repository repo;

public:
    Controller(const Repository& r) : repo{ r } {}

    Repository getRepo() const { return repo; }

    bool add(const std::string &organism, const std::string &name, const std::string &sequence);

};

