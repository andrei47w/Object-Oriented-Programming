//
// Created by Andrei on 6/21/2021.
//

#include <fstream>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <QMessageBox>
#include "read_file.h"

void Repository::repoFromFile() {
    std::ifstream infile(source);
    if (!infile.is_open())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Could not open file!");
    }

    std::string line;
    while(getline(infile, line)){
        std::stringstream stream_line(line);
        std::vector<std::string> seglist;
        std::string segment;
        while(std::getline(stream_line, segment, ';'))
        {
            seglist.push_back(segment);
        }

        if (seglist.size() == 2) add_elem(seglist[0], seglist[1]);
            else if(seglist.size() == 4) add_elem(seglist[0], seglist[1], seglist[2], seglist[3]);
    }

    infile.close();
}

void Repository::repoToFile() {
    std::ofstream outFile(source);
    std::vector<std::vector<std::string>> s = get_elem();
    for (auto &elems : s){
        for (auto &item : elems) outFile << item << ";";
        outFile << '\n';
    }
    outFile.close();
}

Repository::Repository(const std::string &source) {
    this->source = "../" + source;
    this->repoFromFile();
}

Repository::~Repository() {
    this->repoToFile();
}

void Repository::add_elem(std::string name, std::string revised) {
    std::vector<std::string> p;
    p.push_back(name);
    p.push_back(revised);
    p.push_back(total);
    elem.push_back(p);
}

void Repository::add_elem(std::string id, std::string desc, std::string type, std::vector<std::string> coords) {
    std::vector<std::string> f;
    f.push_back(name);
    f.push_back(status);
    f.push_back(creator);
    f.push_back(reviewer);
    elem.push_back(f);
}

std::vector<std::vector<std::string>> Repository::get_elem() {
    return elem;
}
