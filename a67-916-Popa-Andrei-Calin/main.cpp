//
// Created by Andrei on 4/13/2021.
//

#include <iostream>
#include <stdlib.h>
#include "headers/UI.h"
#include <crtdbg.h>
#include <string>
#include <fstream>
#include <HTMLRepo.h>
#include "headers/CSVRepo.h"
#include "headers/Tests.h"

int main() {
    {
        try {
            IFileRepo* r = new CSVRepo("..//input files//tutorials.txt");
            IFileRepo* watch = nullptr;
            std::string fileType{};
            std::cout << "What type of file would you like use? (CSV/HTML)" << std::endl;
            std::cin >> fileType;
            if (fileType == "CSV") watch = new CSVRepo("..//input files//watchlist.csv");
            else if (fileType == "HTML") watch = new HTMLRepo("..//input files//watchlist.html");
                else {
                    std::cout << "Invalid file type";
                    return 0;
                }

            auto* ctrl = new Controller(r, watch);
            UI* ui = new UI(ctrl);
            ui->run();
            delete ui;
        }
        catch (RepositoryException& exp) {
            std::cout << exp.what() << std::endl;
        }
    }

//    std::cout<<_CrtDumpMemoryLeaks();
    return 0;

}


