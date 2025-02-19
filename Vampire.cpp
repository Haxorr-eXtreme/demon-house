#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include "Demons.h"
#include "Vampire.h"

using namespace std;

int Vampire::ghostlyWeils[5] = {10000, 16000, 18000, 20000, 24000};

Vampire::Vampire()
{
    srand(time(0));
    type = "Vampire";
    speciality1 = "Ghostly Weil";
    int fly = 700 + rand() % 301;
    Demons::setFlyingSpeed(fly);

    Sleep(2000); // Adding suspense

    phantomAttackSpeed = (Demons::getFlyingSpeed() > 500) ? (51 + rand() % 50) : (1 + rand() % 51);

    Sleep(2000);

    int r = rand() % 5;
    frequency = ghostlyWeils[r];
    speciality2 = "Golden Cloak";
}

string Vampire::getDemonType()
{
    return type;
}

string Vampire::getSpeciality()
{
    return "Golden Cloak & Ghostly Weil";
}

int Vampire::getPhantomAttackSpeed()
{
    return phantomAttackSpeed;
}

void Vampire::phantomAttack(int playerPower, int playerVisibility, int reactionSpeed, string &result)
{
    srand(time(0));
    int attackType = 1 + rand() % 3; // Three attack types

    if (attackType == 1) // Physical Attack
    {
        cout << "The Vampire vanishes into the mist, then strikes with blinding speed." << endl;
        cout << "Its presence is overwhelming, a shadow creeping closer with every breath." << endl << endl;

        if (getPower() > playerPower)
        {
            if (getVisibility() > playerVisibility)
            {
                if (reactionSpeed > Demons::getFlyingSpeed())
                {
                    cout << "You counter just in time, dodging the attack and retaliating with precision." << endl;
                    cout << "The Vampire falters, its strength waning." << endl;
                    result = "win";
                }
                else
                {
                    cout << "Too slow. The Vampire’s speed is unmatched, draining your strength with each strike." << endl;
                    cout << "Your power and visibility begin to fade as the darkness tightens its grip." << endl;
                    result = "defeat";
                }
            }
            else
            {
                cout << "With a surge of will, you overpower the Vampire, driving it back into the shadows." << endl;
                result = "win";
            }
        }
        else
        {
            cout << "A desperate final blow lands, forcing the Vampire to retreat. You stand victorious." << endl;
            result = "win";
        }
    }
    else if (attackType == 2) // Special Attack: Golden Cloak
    {
        cout << "The Vampire raises its arms, and a shimmering Golden Cloak forms around its body." << endl;
        cout << "An eerie silence fills the air as the cloak distorts reality itself." << endl;
        result = "Golden Cloak";
    }
    else if (attackType == 3) // Ultimate Attack: Ghostly Weil
    {
        cout << "A piercing wail shatters the silence. The Ghostly Weil’s sound ripples through your mind." << endl;
        cout << "The frequency is so intense that your vision blurs, and your strength wavers." << endl;

        if (getPower() > playerPower && frequency > 18000)
        {
            cout << "Your ears ring as the Vampire’s attack overwhelms your defenses." << endl;
            cout << "Even with all your might, you cannot resist. The darkness claims victory." << endl;
            result = "defeat";
        }
        else
        {
            if (getPower() > playerPower)
            {
                if (getVisibility() > playerVisibility)
                {
                    if (reactionSpeed > Demons::getFlyingSpeed())
                    {
                        result = "Ghostly Weil";
                    }
                    else
                    {
                        cout << "The sound paralyzes you momentarily, and the Vampire takes advantage." << endl;
                        cout << "You fall, weakened by the relentless attack." << endl;
                        result = "defeat";
                    }
                }
                else
                {
                    result = "Ghostly Weil";
                }
            }
            else
            {
                result = "Ghostly Weil";
            }
        }
    }
}

void Vampire::print()
{
    ifstream inFile("Vampire.txt");
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
        cout << "The Vampire's ancient scroll is missing. Its secrets remain unknown." << endl;
    }

    cout << endl;
    cout << "Demon Type: " << type << endl;
    Demons::print();
    cout << "Phantom Attack Speed: " << phantomAttackSpeed << "%" << endl;
    cout << "Special Ability 1: " << speciality1 << " (A devastating vocal attack at high frequencies)" << endl;
    cout << "Frequency of Ghostly Weil: " << frequency << " Hz" << endl;
    cout << "Special Ability 2: " << speciality2 << " (A mystical cloak that bends reality)" << endl << endl;
}
