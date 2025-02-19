#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DarkDungeon.h"
#include "Dungeons.h"

using namespace std;

DarkDungeon::DarkDungeon() 
{
    srand(time(0));
    dungeonName = "Abyss of Shadows";
    ancientRune = 'A' + rand() % 26;
}

void DarkDungeon::check(bool& chk) 
{
    char attempt;
    
    cout << "The Abyss of Shadows is filled with eerie whispers and unseen horrors.\n";
    cout << "To navigate through the darkness, you must uncover the **Ancient Rune** (A-Z) hidden within the ruins.\n";
    cout << "Enter your rune guess: ";
    cin >> attempt;
    attempt = toupper(attempt);
    cout << endl;

    if (attempt < 'A' || attempt > 'Z') 
    {
        cout << "-> Invalid input! You must choose a rune between 'A' and 'Z'. <-" << endl << endl;
        chk = false;
        return;
    }

    if (attempt == ancientRune) 
    {
        cout << "-> You deciphered the Ancient Rune! The shadows retreat, revealing the way forward! <-" << endl;
        cout << "-> Strength and awareness surge through you as you leave the abyss. <-" << endl << endl;
        chk = true;
    } 
    else 
    {
        cout << "-> The rune was incorrect! The darkness engulfs you, draining your strength and vision. <-" << endl << endl;
        chk = false;
    }
}

void DarkDungeon::print() 
{
    cout << "Dungeon: " << dungeonName << endl;
    Dungeons::print();
}
