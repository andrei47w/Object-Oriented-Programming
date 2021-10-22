//
// Created by Andrei on 4/4/2021.
//

#pragma once

#include "DynamicVector.h"
#include "Gene.h"

class Repository {
private:
    DynamicVector <Gene> genes;

public:
    /*
    *Default constructor.
    *Initializes an object of type repository.
    */
    Repository() {}
    //~Repository();

    /*
    *Adds a tutorial to the repository.
    *Input: tutorial.
    *Output: (bool) true if tutorial is added to the repository
    *        false if it's not
    */
    bool add(const Gene &t);

    /*
    *Finds a tutorial, by presenter and title.
    *Input: (str) presenter, title
    *Output: the tutorial that was found
    *       false if nothing was found.
    */
    Gene findBy(const std::string &presenter, const std::string &title);

    /*
    *Returns all the genes from the repository.
    *Out: DynamicVector<Gene>
    */
    DynamicVector <Gene> get() { return genes; }

    /*
    *Removes a tutorial from repository by presenter and title.
    *Input: (str) presenter, title
    *Output: (bool) true the tutorial is removed from the repository
    *        false if it's not
    */
    bool remove(const std::string &presenter, const std::string &title);

    /*
    *Finds a tutorial
    *Input: presenter, title - string
    *Output: its position in the dynamic vector
    */
    int findPos(const Gene &t);
};