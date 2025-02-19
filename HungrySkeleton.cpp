#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include "Demons.h"
#include "HungrySkeleton.h"

using namespace std;

HungrySkeleton::HungrySkeleton()
{
    int fly;
    srand(time(0));

    type = "Hungry Skeleton";
    fly = 100 + rand() % 201;  // Flying speed between 100-300
    Demons::setFlyingSpeed(fly);

    Sleep(2000); // Simulate a delay

    if (Demons::getFlyingSpeed() > 500)
    {
        phantomAttackSpeed = 51 + rand() % 50;
    }
    else
    {
        phantomAttackSpeed = 1 + rand() % 51;
    }

    speciality = "Magic Spell";
}

string HungrySkeleton::getDemonType()
{
    return type;
}

string HungrySkeleton::getSpeciality()
{
    return speciality;
}

int HungrySkeleton::getPhantomAttackSpeed()
{
    return phantomAttackSpeed;
}

void HungrySkeleton::phantomAttack(int p, int v, int r, string& res)
{
    char magicSpell, userGuess;
    string answer;

    srand(time(0));
    magicSpell = 'a' + rand() % 26;

    cout << "**********************************************************\n";
    cout << "  You are trapped in the magic spell of the Hungry Skeleton!  \n";
    cout << "  Solve the riddle and guess the magical character to escape. \n";
    cout << "**********************************************************\n\n";

    cout << "Enter the magical character (a-z): ";
    cin >> userGuess;
    cout << "\n";

    cout << "Solve this riddle to break the magic spell:\n";
    cout << "I speak without a mouth and hear without ears. I have no body, but I come alive with the wind.\n";
    cout << "Your Answer: ";
    cin >> answer;
    cout << "\n";

    if ((answer == "Echo" || answer == "echo") && userGuess == magicSpell)
    {
        cout << "You guessed the magical character correctly: '" << magicSpell << "'\n";
        cout << "You also solved the riddle! The demon is defeated!\n\n";
        cout << "Your power and visibility have increased.\n";
        res = "win";
    }
    else
    {
        cout << "You failed to break the spell! The Hungry Skeleton attacks!\n\n";

        if (getPower() > p)
        {
            if (getVisibility() > v)
            {
                if (r > Demons::getFlyingSpeed())
                {
                    cout << "You fought bravely and won the battle!\n";
                    cout << "Your power and visibility have increased.\n";
                    res = "win";
                }
                else
                {
                    cout << "The demon overpowered you! You lost power and visibility.\n";
                    res = "defeat";
                }
            }
            else
            {
                cout << "You fought courageously and won the battle!\n";
                cout << "Your power and visibility have increased.\n";
                res = "win";
            }
        }
        else
        {
            cout << "You vanquished the demon and claimed victory!\n";
            cout << "Your power and visibility have increased.\n";
            res = "win";
        }
    }
}

void HungrySkeleton::print()
{
    ifstream in("HungrySkeleton.txt", ios::in);
    if (!in)
    {
        cerr << "Error: Could not open file 'HungrySkeleton.txt'\n";
        return;
    }

    string line;
    while (getline(in, line))
    {
        cout << line << endl;
    }
    in.close();

    cout << "\nDemon Details\n";
    cout << "-----------------------------\n";
    cout << "Demon Type: " << type << endl;
    Demons::print();
    cout << "Phantom Attack Speed: " << phantomAttackSpeed << " %\n";
    cout << "Speciality: " << speciality << endl;
    cout << "-----------------------------\n\n";
}
