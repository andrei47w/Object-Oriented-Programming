
#include <iostream>
#include "headers/UI.h"
#include <crtdbg.h>


int main() {
    {
        Repository repo{};
        List s1{"Detecting memory leaks in Visual Studio", "CodeVault", 175,
                "https://www.youtube.com/watch?v=t1wqj6J6Vhs", 9685};
        List s2{"Difference between arrays and pointers in C", "CodeVault", 96,
                "https://www.youtube.com/watch?v=iSZLE9qPN14", 3398};
        List s3{"title", "Google", 10000, "google.com", 10000};

        repo.add(s1);
        repo.add(s2);
        repo.add(s3);

        Controller ctrl{repo};
        UI ui{ctrl};
        ui.run();
    }

    return 0;
}