#include "headers/UI.h"
#include <string>


using namespace std;

void UI::printMenu() {
    cout << endl;
    cout << "____________________MENU_____________________" << endl;
    cout << "\t " << endl;
    cout << "_____________________________________________" << endl;
}


void UI::addToRepo() {
    cout << "Presenter: ";
    std::string presenter;
    getline(cin, presenter);
    cout << "Title: ";
    std::string title;
    getline(cin, title);
    double noLikes, noViews;

    cout << "\tLikes: ";
    cin >> noLikes;
    cin.ignore();
    cout << "\tViews: ";
    cin >> noViews;
    cin.ignore();
    cout << "Link to the tutorial: ";
    std::string link;
    getline(cin, link);

    if (this->ctrl.add(presenter, title, noLikes, link, noViews))
        cout << "Tutorial added successfully!" << endl;
    else
        cout << "Cannot add tutorial!";
}

void UI::deleteFromRepo() {
    cout << "Presenter: ";
    std::string presenter;
    getline(cin, presenter);
    cout << "Title: ";
    std::string title;
    getline(cin, title);
    if (this->ctrl.remove(presenter, title))
        cout << "The tutorial was removed successfully!";
    else
        cout << "Cannot find the tutorial!" << endl;
}

void UI::updateFromRepo() {
    cout << "Presenter: ";
    std::string presenter;
    getline(cin, presenter);
    cout << "Title: ";
    std::string title;
    getline(cin, title);
    cout << "New presenter: ";
    std::string newPresenter;
    getline(cin, newPresenter);
    cout << "New title: ";
    std::string newTitle;
    getline(cin, newTitle);
    double noLikes;

    cout << "\tNumber of likes: ";
    cin >> noLikes;
    cin.ignore();
    cout << "Link to the tutorial: ";
    std::string link;
    getline(cin, link);


    if (this->ctrl.update(presenter, title, noLikes, link, newPresenter,
                          newTitle))
        cout << "Tutorial updated successfully!" << endl;
    else
        cout << "Could not update tutorial!" << endl;


}

void UI::displayAll() {
    DynamicVector<List> v = this->ctrl.getRepo().getTutorials();
    List *tutorials = v.getAllElems();
    if (tutorials == nullptr)
        return;
    if (v.getSize() == 0) {
        cout << "There are no tutorials in the repository." << endl;
        return;
    }

    for (int i = 0; i < v.getSize(); i++) {
        cout << i << "  ";
        List t = tutorials[i];
        UI::print(t, true);

    }
}


void UI::print(const List &t, bool flag) {
    cout << "| " << t.getPresenter();
    for (int i = 1; i <= 18 - t.getPresenter().length(); i++) cout << " ";

    cout << "| " << t.getTitle();
    for (int i = 1; i <= 53 - t.getTitle().length(); i++) cout << " ";

    cout << "| " << t.getNoLikes();
    int length = 1;
    int x = (int) t.getNoLikes();
    while (x != 0) {
        length++;
        x /= 10;
    }

    length++;
    for (int i = 1; i <= 10 - length; i++) cout << " ";

    flag && cout << "| " << t.getNoViews();
    cout << endl;
}


void UI::run() {
    while (true) {
        UI::printMenu();
        int commandRepo{0};
        cout << "Input command: ";
        cin >> commandRepo;
        cin.ignore();
        if (commandRepo == 0)
            break;
        switch (commandRepo) {
            case 1:
                this->addToRepo();
                break;
            case 2:
                this->displayAll();
                break;
            case 3:
                this->deleteFromRepo();
                break;
            case 4:
                this->updateFromRepo();
                break;
            default:
                cout << "Invalid input!" << endl;
        }
    }
}
