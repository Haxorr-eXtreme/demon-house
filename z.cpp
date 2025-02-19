#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include "Demons.h"
#include "BlackDevil.h"

using namespace std;

BlackDevil::BlackDevil() 
{
    srand(time(0));
    type = "Black Devil";

    int flyingSpeed = 400 + rand() % 301;
    Demons::setFlyingSpeed(flyingSpeed);

    Sleep(2000);
    
    phantomAttackSpeed = (Demons::getFlyingSpeed() > 500) ? (51 + rand() % 50) : (1 + rand() % 51);

    Sleep(2000);
    daggerPoisonIntensity = 700 + rand() % 101;
    speciality = "Silver Dagger";
}

string BlackDevil::getDemonType() 
{
    return type;
}

string BlackDevil::getSpeciality() 
{
    return speciality;
}

int BlackDevil::getPhantomAttackSpeed() 
{
    return phantomAttackSpeed;
}

void BlackDevil::phantomAttack(int playerPower, int playerVisibility, int reactionSpeed, string& result) 
{
    cout << "*** The Black Devil Strikes! Defend Yourself! ***" << endl << endl;

    if (getPower() > playerPower && daggerPoisonIntensity > 770) 
    {
        cout << "<> You have fallen in battle! The Black Devil's Silver Dagger carried a lethal poison, draining your power and vision! <>" << endl << endl;
        cout << "<> The victorious demon grows even stronger... <>" << endl << endl;
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
                    cout << "<> Amazing! You have conquered the Black Devil! Your strength and vision have increased! <>" << endl << endl;
                    cout << "<> The defeated demon loses its power and fades into the darkness... <>" << endl << endl;
                    result = "win";
                } 
                else 
                {
                    cout << "<> You were too slow! The Black Devil overpowered you, weakening your energy and sight. <>" << endl << endl;
                    cout << "<> The demon thrives on its victory! <>" << endl << endl;
                    result = "defeat";
                }
            } 
            else 
            {
                cout << "<> You have triumphed! The Black Devil is now under your control, and your abilities have grown! <>" << endl << endl;
                cout << "<> The defeated demon weakens, losing its strength. <>" << endl << endl;
                result = "win";
            }
        } 
        else 
        {
            cout << "<> You have successfully overpowered the Black Devil! Your power surges as you claim victory! <>" << endl << endl;
            cout << "<> The demon’s strength diminishes, leaving only a faint trace behind. <>" << endl << endl;
            result = "win";
        }
    }
}

void BlackDevil::print() 
{
    ifstream file("BlackDevil.txt");
    string line;
    
    while (getline(file, line)) 
    {
        cout << line << endl;
    }
    
    file.close();
    cout << endl << endl;
    
    cout << "Demon's Type: " << type << endl;
    Demons::print();
    cout << "Phantom Attack Speed: " << phantomAttackSpeed << " %" << endl;
    cout << "Special Ability: " << speciality << " (Toxic Blade)" << endl;
    cout << "Poison Intensity of Silver Dagger: " << daggerPoisonIntensity << endl << endl;
}
