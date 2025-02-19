#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

// Include Game Components
#include "Demons.h"
#include "Dungeons.h"
#include "Coins.h"
#include "Weapons.h"
#include "Mysteries.h"
#include "Riddles.h"
#include "BlackDevil.h"
#include "CreepyWall.h"
#include "DarkDungeon.h"
#include "EvilSpirit.h"
#include "GoldCoin.h"
#include "Handgun.h"
#include "HungrySkeleton.h"
#include "PlatinumCoin.h"
#include "Player.h"
#include "Puzzles.h"
#include "Revolver.h"
#include "Rifle.h"
#include "Shadow.h"
#include "Shotgun.h"
#include "SilverCoin.h"
#include "Vampire.h"
#include "WeepingWell.h"

using namespace std;

// Overloaded Output Operator for Player
ostream &operator<<(ostream &o, const Player &pl) {
    string line;
    ifstream in("Player.txt");
    while (getline(in, line)) {
        o << line << endl;
    }
    in.close();

    o << "\n\nPlayer's Name: " << pl.name << endl
      << "Player's Visibility: " << pl.visibility << " %" << endl
      << "Player's Power: " << pl.power << " %" << endl
      << "Player's Lives: " << pl.lives << endl
      << "Equipment Found:\n" << endl;

    if (pl.silverArmour) o << "Silver Armour" << endl;
    if (pl.earmuffs) o << "Earmuffs" << endl;
    if (pl.blueTorch) o << "Blue Torch" << endl;
    if (pl.knife) o << "Knife" << endl;
    if (pl.sword) o << "Sword" << endl;
    
    o << "\nNumber of Demons Captured: " << pl.d.size() << endl << endl;
    for (size_t i = 0; i < pl.d.size(); i++) {
        o << "Demon " << i + 1 << ":\n\n"
          << "Demon's Type: " << pl.d[i]->getDemonType() << endl
          << "Demon's Name: " << pl.d[i]->getName() << endl
          << "Demon's Power: " << pl.d[i]->getPower() << " %" << endl
          << "Demon's Visibility: " << pl.d[i]->getVisibility() << " %" << endl
          << "Demon's Flying Speed: " << pl.d[i]->getFlyingSpeed() << " m/s" << endl
          << "Demon's Phantom Attack Speed: " << pl.d[i]->getPhantomAttackSpeed() << " %" << endl
          << "Demon's Speciality: " << pl.d[i]->getSpeciality() << "\n" << endl;
    }

    o << "Number of Weapons Collected: " << pl.w.size() << endl << endl;
    for (size_t i = 0; i < pl.w.size(); i++) {
        o << "Weapon " << i + 1 << ":\n\n"
          << "Weapon's Type: " << pl.w[i]->getWeaponType() << endl
          << "Weapon's Ammo: " << pl.w[i]->getAmmo() << endl
          << "Weapon's Range: " << pl.w[i]->getRange() << " m" << endl
          << "Weapon's Damage: " << pl.w[i]->getDamage() << " %" << endl << endl;
    }

    o << "Number of Coins Collected: " << pl.c.size() << endl << endl;
    for (size_t i = 0; i < pl.c.size(); i++) {
        o << "Coin " << i + 1 << ":\n\n"
          << "Coin's Type: " << pl.c[i]->getCoinType() << endl
          << "Coin's Value: " << pl.c[i]->getValue() << " points" << endl << endl;
    }

    return o;
}

// ----------------- Factory Functions -----------------

Demons *createDemon() {
    srand(time(0));
    int r = rand() % 50 + 1;
    if (r <= 20) return new HungrySkeleton();
    if (r <= 27) return new BlackDevil();
    if (r <= 38) return new EvilSpirit();
    if (r <= 46) return new Shadow();
    return new Vampire();
}

Dungeons *createDungeon() {
    srand(time(0));
    int r = rand() % 3 + 1;
    if (r == 1) return new WeepingWell();
    if (r == 2) return new DarkDungeon();
    return new CreepyWall();
}

Mysteries *createMystery() {
    srand(time(0));
    return (rand() % 2 == 0) ? static_cast<Mysteries *>(new Riddles()) : new Puzzles();
}

Coins *createCoin() {
    srand(time(0));
    int r = rand() % 50 + 1;
    if (r <= 30) return new SilverCoin();
    if (r <= 45) return new GoldCoin();
    return new PlatinumCoin();
}

Weapons *createWeapon() {
    srand(time(0));
    int r = rand() % 50 + 1;
    if (r <= 20) return new Rifle();
    if (r <= 35) return new Revolver();
    if (r <= 45) return new Handgun();
    return new Shotgun();
}

// ----------------- Main Function -----------------

int main() {
    ifstream in("DemonHouse.txt");
    ofstream out;
    string playerName, saveFile;
    char choice;

    // Game Intro
    cout << "\n\n\t\t\t\t\t>>>>>>>>>> LOADING GAME <<<<<<<<<<" << endl << endl;
    Player p;
    system("cls");

    cout << "********************************************************************************************************************************" << endl;
    cout << "\t\t\t\t\t*------> Demon House <------*" << endl;
    cout << "********************************************************************************************************************************\n\n";

    while (!in.eof()) {
        string line;
        getline(in, line);
        cout << line << endl;
    }
    in.close();

    // Player Input
    cout << "\n>>>>> Enter Your Name: ";
    getline(cin, playerName);
    saveFile = playerName + ".txt";
    p.setName(playerName);

    cout << "\n>>>>> Player At The Start <<<<<\n" << endl;
    p.print();

    do {
        cout << ">>>>> Press [a] Random Play | [b] Fight Demon | [c] Save & Pause | [d] Quit <<<<<\n";
        cout << "-----> ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 'a': {
                int randomEvent = rand() % 5 + 1;
                if (randomEvent == 1) {
                    Demons *de = createDemon();
                    cout << ">>>>> Demon Appeared <<<<<\n";
                    de->print();
                    p.attack(de);
                } else if (randomEvent == 2) {
                    Coins *co = createCoin();
                    cout << ">>>>> Coin Found <<<<<\n";
                    co->print();
                    p.addCoin(co);
                }
                break;
            }
            case 'c': {
                out.open(saveFile);
                out << p;
                out.close();
                cout << ">>>>> Game Stats Updated <<<<<\n";
                break;
            }
        }
    } while (choice != 'd');

    cout << "\n>>>>> Game Over! <<<<<\n";
    return 0;
}
