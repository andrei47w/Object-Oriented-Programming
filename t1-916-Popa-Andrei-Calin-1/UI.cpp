//
// Created by Andrei on 4/4/2021.
//

#include "UI.h"
#include <string>
#include <vector>
#include <dvec.h>


using namespace std;

void UI::printMenu() {
    cout << endl << "_________________MENU_________________" << endl;
    cout << "\t 0 - Exit" << endl;
    cout << "\t 1 - Add gene" << endl;
    cout << "\t 2 - Show all genes" << endl;
    cout << "\t 3 - Search gene" << endl;
    cout << "\t 4 - Given a pair of organism and gene names, display their longest common subsequence" << endl;
    cout << "__________________________________" << endl;
}

void UI::addGene() {
    cout << "Organism: ";
    std::string organism;
    getline(cin, organism);

    cout << "Name: ";
    std::string name;
    getline(cin, name);

    cout << "Sequence: ";
    std::string sequence;
    getline(cin, sequence);

    this->ctrl.add(organism, name, sequence);
}

void UI::printGene(const Gene &t, int length) {
    cout << t.getOrganism();
    for (int i = 1; i <= 20 - t.getOrganism().length(); i++) cout << " ";

    cout << "| " << t.getName();
    for (int i = 1; i <= 20 - t.getName().length(); i++) cout << " ";

    cout << "| ";
    if (length) for (int i = 0; i <= length - t.getSequence().length(); i++) cout << " ";
    cout << t.getSequence();
    cout << endl;
}

void UI::searchGenes() {
    cout << "Search: ";
    std::string string;
    getline(cin, string);

    DynamicVector<Gene> v = this->ctrl.getRepo().get();
    Gene *genes = v.getAllElems();
    if (genes == nullptr)
        return;
    if (v.getSize() == 0) {
        cout << "There are no genes in the repository." << endl;
        return;
    }

    for (int i = 0; i < v.getSize(); i++) {
        Gene t = genes[i];
        if(t.getSequence().find(string) != std::string::npos) UI::printGene(t, 0);

    }
}

void UI::sortGenes() {
    DynamicVector<Gene> v = this->ctrl.getRepo().get();
    Gene *genes = v.getAllElems();
    if (genes == nullptr)
        return;
    if (v.getSize() == 0) {
        cout << "There are no genes in the repository." << endl;
        return;
    }
    int length = 0;

    std::vector<std::string> arr;
    for (int i = 0; i < v.getSize(); i++) {
        Gene t = genes[i];
        if(length < t.getSequence().length()) length = t.getSequence().length();
        arr.push_back(t.getSequence());
    }

    int n = arr.capacity();
    sort(arr, n, length);
}

void UI::sort(std::vector<std::string> s, int n, int length) {
    for (int i=1 ;i<n; i++)
    {
        string temp = s[i];

        int j = i - 1;
        while (j >= 0 && temp.length() > s[j].length())
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = temp;
    }

    DynamicVector<Gene> v = this->ctrl.getRepo().get();
    Gene *genes = v.getAllElems();

    cout<<endl;

    for (int i = 0; i < v.getSize(); i++) {
        for (int j = 0; j < v.getSize(); j++) {
            Gene t = genes[j];
            if (t.getSequence().length() == s[i].length()) UI::printGene(t, length);
        }
    }
}

void UI::commonSeq() {
    int organism;
    int organism2;

    cout << "Organism ID: ";
    cin>>organism;

    cout << "Organism ID: ";
    cin>>organism2;

    DynamicVector<Gene> v = this->ctrl.getRepo().get();
    Gene *genes = v.getAllElems();
    int idk = this->LCS(genes[organism].getSequence(), genes[organism2].getSequence(), 30,30);
    cout<< genes[organism].getSequence()[idk/2];
}

int UI::LCS(string X, string Y, int m, int n)
{
    int L[100][100];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

void UI::run() {
    while (true) {
        UI::printMenu();
        int command{0};
        cout << "Input command: ";
        cin >> command;
        cin.ignore();
        if (command == 0) break;
        switch (command) {
            case 1:
                this->addGene();
                break;
            case 3:
                this->searchGenes();
                break;
            case 2:
                this->sortGenes();
            case 4:
                this->commonSeq();
                break;
        }
    }
}