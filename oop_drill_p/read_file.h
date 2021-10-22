//
// Created by Andrei on 6/21/2021.
//


#pragma once

class Repository{
protected:
    std::string source;
    void repoFromFile();
    void repoToFile();

public:
    std::vector<std::vector<std::string>> elem;
    void add_elem(std::string name, std::string revised, std::string total);
    void add_elem(std::string name, std::string status, std::string creator, std::string reviewer);
    std::vector<std::vector<std::string>> get_elem();
    Repository(const std::string& source);
    ~Repository();
};