#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Puzzles.h"
#include "Mysteries.h"
using namespace std;

Puzzles::Puzzles()
{
    srand(time(0));
    setMysteryType("Puzzle");
    bone = 'a' + rand() % 26;
}

void Puzzles::solveMystery(bool& chk1)
{
    char choice;
    cout << "A mystical skeleton lies in pieces before you..." << endl;
    cout << "To complete its form, choose the correct enchanted bone (a-z):" << endl << endl;
    cout << "Your Choice ---> ";
    cin >> choice;
    cout << endl;

    if (choice == bone)
    {
        cout << "Incredible! You have restored the Magical Skeleton to its full power!" << endl;
        cout << "A powerful aura surrounds you, granting you an increase in Power and Visibility!" << endl << endl;
        chk1 = true;
    }
    else
    {
        cout << "Oh no! You placed the wrong bone..." << endl;
        cout << "A dark energy swirls as the skeleton collapses into dust." << endl;
        cout << "The curse weakens you, draining your Power and Visibility!" << endl << endl;
        chk1 = false;
    }
}
