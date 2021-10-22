//
// Created by Andrei on 4/4/2021.
//

#pragma once

#include "DynamicVector.h"
#include "Tutorial.h"

class Repository {
private:
    DynamicVector <Tutorial> tutorials;

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
    bool add(const Tutorial &t);

    /*
    *Finds a tutorial, by presenter and title.
    *Input: (str) presenter, title
    *Output: the tutorial that was found
    *       false if nothing was found.
    */
    Tutorial findBy(const std::string &presenter, const std::string &title);

    /*
    *Returns all the tutorials from the repository.
    *Out: DynamicVector<Tutorial>
    */
    DynamicVector <Tutorial> get() { return tutorials; }

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
    int findPos(const Tutorial &t);
};