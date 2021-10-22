//
// Created by Andrei on 4/4/2021.
//

#include "Repository.h"


bool Repository::add(const Gene &t) {
    Gene gene = findBy(t.getOrganism(), t.getName());
    if (!gene.getOrganism().empty() || !gene.getSequence().empty())
        return false;
    this->genes.add(t);
    return true;
}


Gene Repository::findBy(const std::string &presenter, const std::string &title) {
    Gene *tutorialsInDynamicVector = this->genes.getAllElems();

    for (int i = 0; i < this->genes.getSize(); i++) {
        Gene s = tutorialsInDynamicVector[i];
        if (s.getOrganism() == presenter && s.getName() == title)
            return s;
    }

    return Gene{};
}


bool Repository::remove(const std::string &presenter, const std::string &title) {
    Gene t = this->findBy(presenter, title);
    if (t.getOrganism().empty() && t.getName().empty())
        return false;
    int pos = this->findPos(t);
    this->genes.deleteElem(pos);
    return true;
}

int Repository::findPos(const Gene &t) {
    for (int i = 0; i < this->genes.getSize(); i++) {
        if (this->genes[i].getOrganism() == t.getOrganism() && this->genes[i].getName() == t.getName())
            return i;
    }
    return -1;
}


