//
// Created by Andrei on 4/4/2021.
//

#include <iostream>
#include "UI.h"

int main() {
    {
        Repository repo{};
        Gene s1{"E_Coli_K12", "yqgE", "ATGACATCATCATTG"};

        repo.add(s1);

        Controller ctrl{repo};
        UI ui{ctrl};
        ui.run();
    }
    return 0;
}