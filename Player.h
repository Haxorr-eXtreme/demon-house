#pragma once
#include <iostream>
#include <vector>
#include "Demons.h"
#include "Weapons.h"
#include "Coins.h"
#ifndef Player_H
#define Player_H
using namespace std;

class Player
{
    friend ostream& operator<<(ostream& o, const Player& pl);

private:
    string name;
    static int vis[5];
    int visibility;
    int power;
    int lives;
    bool silverArmour;
    bool earmuffs;
    bool blueTorch;
    bool knife;
    bool sword;
    vector<Demons*> d;
    vector<Weapons*> w;
    vector<Coins*> c;
    vector<int>::iterator t;

public:
    // Constructor
    Player();

    // Setters
    void setName(string n);
    void setPower();
    void setVisibility();

    // Inventory Management
    void addDemon(Demons* d1);
    void addWeapon(Weapons* w1);
    void addCoin(Coins* c1);

    // Power & Visibility Modifiers
    void increasePower();
    void decreasePower();
    void increaseVisibility();
    void decreaseVisibility();
    void giveUpDecreasePower();
    void giveUpDecreaseVisibility();
    void hitDamage(); // Reduces player's lives

    // Getters
    string getName();
    int getVisibility();
    int getPower();
    int getLives();

    // Equipment Check
    bool checkSilverArmour();
    bool checkEarmuffs();
    bool checkBlueTorch();
    bool checkKnife();
    bool checkSword();

    // Combat Function
    void attack(Demons* d);

    // Display Function
    void print();

    // Destructor
    ~Player();
};

#endif
