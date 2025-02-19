#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include "Demons.h"
#include "Shadow.h"

using namespace std;

Shadow::Shadow()
{
    srand(time(0));
    type = "Shadow";
    int fly = 600 + rand() % 201;
    Demons::setFlyingSpeed(fly);

    Sleep(2000); // Adding a delay to build suspense.

    if (Demons::getFlyingSpeed() > 500)
    {
        phantomAttackSpeed = 51 + rand() % 50; // Attack speed between 51 and 100
    }
    else
    {
        phantomAttackSpeed = 1 + rand() % 51; // Attack speed between 1 and 50
    }

    speciality = "Blue Stone";
}

string Shadow::getDemonType()
{
    return type;
}

string Shadow::getSpeciality()
{
    return speciality;
}

int Shadow::getPhantomAttackSpeed()
{
    return phantomAttackSpeed;
}

void Shadow::phantomAttack(int playerPower, int playerVisibility, int reactionSpeed, string& result)
{
    srand(time(0));
    int attackType = 1 + rand() % 2;

    if (attackType == 1) // Normal attack
    {
        cout << "The Shadow Demon moves swiftly, its form flickering in the darkness." << endl;
        cout << "A chilling wind rises as it strikes, aiming to overpower you with speed and force." << endl << endl;

        if (getPower() > playerPower)
        {
            if (getVisibility() > playerVisibility)
            {
                if (reactionSpeed > Demons::getFlyingSpeed())
                {
                    cout << "You react just in time, dodging the attack and striking back with precision." << endl;
                    cout << "The Shadow recoils, its power and visibility weakening." << endl;
                    result = "win";
                }
                else
                {
                    cout << "The demon is too fast. Before you can react, it overwhelms you with its presence." << endl;
                    cout << "Your power and visibility are drained as the darkness closes in." << endl;
                    result = "defeat";
                }
            }
            else
            {
                cout << "You stand firm as the Shadow falters. With a final strike, you force it back." << endl;
                result = "win";
            }
        }
        else
        {
            cout << "Summoning all your strength, you land a decisive blow. The Shadow's form begins to fade." << endl;
            cout << "You have won this battle." << endl;
            result = "win";
        }
    }
    else if (attackType == 2) // Special attack
    {
        cout << "The Shadow raises an ancient Blue Stone, its surface glowing with an eerie light." << endl;
        cout << "A pulse of energy ripples through the air, distorting reality itself." << endl;
        result = "Blue Stone";
    }
}

void Shadow::print()
{
    ifstream inFile("Shadow.txt");
    string line;

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
        inFile.close();
    }
    else
    {
        cout << "The scroll containing the Shadow's lore is missing." << endl;
    }

    cout << endl;
    cout << "Demon's Type: " << type << endl;
    Demons::print();
    cout << "Phantom Attack Speed: " << phantomAttackSpeed << "%" << endl;
    cout << "Special Ability: " << speciality << " (Emits High-Frequency Gamma Rays)" << endl << endl;
}
