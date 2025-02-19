#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>  // For input validation
#include "CreepyWall.h"
#include "Dungeons.h"

using namespace std;

CreepyWall::CreepyWall() 
{
    srand(time(0));
    dungeonName = "Creepy Wall";
    mysteryRune = 33 + rand() % 15;  // Generates a random symbol between '!' and '/'
}

void CreepyWall::check(bool& chk) 
{
    char attempt;
    
    cout << "A strange wall covered in blood and eerie symbols stands before you.\n";
    cout << "To pass safely, you must identify the correct **Mystery Rune** (a special symbol from '!' to '/').\n";
    cout << "Enter your guess: ";
    cin >> attempt;
    cout << endl;

    if (attempt < '!' || attempt > '/') 
    {
        cout << "-> Invalid choice! You must guess a symbol between '!' and '/'. <-" << endl << endl;
        chk = false;
        return;
    }

    if (attempt == mysteryRune) 
    {
        cout << "-> Amazing! You deciphered the rune and the wall grants you safe passage! <-" << endl;
        cout << "-> You emerge stronger and more aware of your surroundings. <-" << endl << endl;
        chk = true;
    } 
    else 
    {
        cout << "-> Incorrect! The wall rejects you, leaving deep wounds that drain your strength. <-" << endl << endl;
        chk = false;
    }
}

void CreepyWall::print() 
{
    cout << "Dungeon: " << dungeonName << endl;
    Dungeons::print();
}
