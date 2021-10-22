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
    /*
            Adds a tutorial with the given data to the tutorial repository
        In:
            presenter: string
            title: string
            minutes: double
            seconds: double
            noLikes: double
            source: string
        Out:
            true if tutorial was added successfully
            false if it wasn't
    */
    bool add(const std::string &presenter, const std::string &title, double minutes, double seconds,
                                 double noLikes, const std::string &source, double d = 0);

    /*
            Removes a tutorial from the repository
        In:
            presenter: string
            title: string
        Out:
            true if tutorial was removed successfully
            false if it wasn't
    */
    bool remove(const std::string &presenter, const std::string &title);


    /*
            Updates a tutorial from the repository
        In:
            presenter: string
            title: string
            minutes: double
            seconds: double
            noLikes: double
            source: string
            newName: string
            newTitle: string
        Out:
            true if tutorial was updated successfully
            false if it wasn't
    */
    bool update(const std::string &presenter, const std::string &title, double minutes, double seconds,
                                 double noLikes, const std::string &source, const std::string newName,
                                 const std::string newTitle);

    Tutorial get();
};

