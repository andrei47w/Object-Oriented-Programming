//
// Created by Andrei on 4/4/2021.
//

#include <iostream>
#include "UI.h"

int main() {
    {
        Repository repo{};
//        Tutorial s1{"Detecting memory leaks in Visual Studio", "CodeVault", Duration{6, 33}, 175,
//                    "https://www.youtube.com/watch?v=t1wqj6J6Vhs", 9685};
//        Tutorial s2{"Difference between arrays and pointers in C", "CodeVault", Duration{11, 22}, 96,
//                    "https://www.youtube.com/watch?v=iSZLE9qPN14", 3398};
//        Tutorial s3{"title", "Google", Duration{0, 0}, 10000, "google.com", 10000};
//
//        repo.add(s1);
//        repo.add(s2);
//        repo.add(s3);

        Controller ctrl{repo};
        UI ui{ctrl};
        ui.run();
    }
    return 0;
}