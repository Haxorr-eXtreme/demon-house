#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include "Demons.h"
#include "EvilSpirit.h"

using namespace std;

EvilSpirit::EvilSpirit()
{
    srand(time(0));
    type = "Evil Spirit";
    int flySpeed = 300 + rand() % 201;  // Speed between 300-500
    Demons::setFlyingSpeed(flySpeed);
    
    Sleep(1500);
    
    phantomAttackSpeed = (flySpeed > 450) ? (60 + rand() % 41) : (10 + rand() % 51);
    
    Sleep(1500);
    
    magicPotionIntensity = 500 + rand() % 501;  // Intensity between 500-1000
    speciality = "Cursed Elixir";
}

string EvilSpirit::getDemonType()
{
    return type;
}

string EvilSpirit::getSpeciality()
{
    return speciality;
}

int EvilSpirit::getPhantomAttackSpeed()
{
    return phantomAttackSpeed;
}

void EvilSpirit::phantomAttack(int p, int v, int r, string& res)
{
    cout << "*** A chilling presence fills the air... The Evil Spirit emerges! ***" << endl << endl;

    if (getPower() > p && magicPotionIntensity > 850)
    {
        cout << "<> The Evil Spirit overwhelms you with its **Cursed Elixir**, draining your strength and vision! <>" << endl << endl;
        cout << "<> You have been defeated... The demon grows stronger from your loss. <>" << endl << endl;
        res = "defeat";
        return;
    }

    if (getPower() > p)
    {
        if (getVisibility() > v)
        {
            if (r > Demons::getFlyingSpeed())
            {
                cout << "<> With unmatched agility, you evade the spirit's grasp and overpower it! <>" << endl << endl;
                cout << "<> The demon is now under your control, granting you increased strength and awareness. <>" << endl << endl;
                res = "win";
            }
            else
            {
                cout << "<> The Evil Spirit's flight speed was too great! You are unable to keep up and fall victim to its power. <>" << endl << endl;
                cout << "<> Your energy fades as the demon grows stronger... <>" << endl << endl;
                res = "defeat";
            }
        }
        else
        {
            cout << "<> Despite the darkness, you outmaneuver the demon and claim victory! <>" << endl << endl;
            cout << "<> Your abilities have been enhanced by your conquest. <>" << endl << endl;
            res = "win";
        }
    }
    else
    {
        cout << "<> Against all odds, you harness your willpower and overpower the Evil Spirit! <>" << endl << endl;
        cout << "<> Your power and awareness surge as the demon falls before you. <>" << endl << endl;
        res = "win";
    }
}

void EvilSpirit::print()
{
    ifstream in("EvilSpirit.txt");
    string line;

    while (getline(in, line))
    {
        cout << line << endl;
    }
    in.close();

    cout << "\n\n";
    cout << "Demon Type: " << type << endl;
    Demons::print();
    cout << "Phantom Attack Speed: " << phantomAttackSpeed << " %" << endl;
    cout << "Special Ability: " << speciality << " (A dark concoction with mysterious effects)" << endl;
    cout << "Intensity of Cursed Elixir: " << magicPotionIntensity << endl << endl;
}
