//
// Created by Andrei on 6/21/2021.
//

#include <QApplication>
#include <fstream>
#include <iostream>
#include "programmerwindow.h"
#include "form.h"
//#include "read_file.h"

int main(int argc, char *argv[]) {

    std::ifstream f("../programmers.txt");
    std::string line;
    long numLines;
    for (numLines = 0; std::getline(f, line); ++numLines);
    f.close();

    QApplication a(argc, argv);

    Form form;
    form.show();

    for (int i = 0; i < numLines; i++) {
        ProgrammerWindow w;
        w.index = i;
        w.update_titles();
        w.show();
        QApplication::exec();
    }

    return 0;
}