#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
#include <fstream>
#include <string>
#include "Player.h"
#include "Demons.h"
#include "Weapons.h"
#include "Coins.h"

using namespace std;

int Player::vis[5] = { 20, 40, 60, 80, 100 };

Player::Player()
{
    srand(time(0));
    int r;

    name = "";
    r = rand() % 5;
    visibility = vis[r];
    Sleep(1500);

    silverArmour = rand() % 2;
    Sleep(1500);

    earmuffs = rand() % 2;
    Sleep(1500);

    blueTorch = rand() % 2;
    Sleep(1500);

    knife = rand() % 2;
    Sleep(1500);

    sword = rand() % 2;

    power = 50;
    lives = 3;
    vector<Demons*> d;
    vector<Weapons*> w;
    vector<Coins*> c;
}

void Player::setName(string n)
{
    name = n;
}

void Player::setPower()
{
    power = 50;
}

void Player::setVisibility()
{
    srand(time(0));
    visibility = vis[rand() % 5];
}

void Player::addDemon(Demons* d1)
{
    d.push_back(d1);
}

void Player::addWeapon(Weapons* w1)
{
    w.push_back(w1);
}

void Player::addCoin(Coins* c1)
{
    c.push_back(c1);
}

void Player::increasePower()
{
    power += 10;
}

void Player::decreasePower()
{
    power -= 10;
}

void Player::increaseVisibility()
{
    visibility += 10;
}

void Player::decreaseVisibility()
{
    visibility -= 10;
}

void Player::giveUpDecreasePower()
{
    power -= 16;
}

void Player::giveUpDecreaseVisibility()
{
    visibility -= 16;
}

void Player::hitDamage()
{
    lives -= 1;
}

string Player::getName()
{
    return name;
}

int Player::getVisibility()
{
    return visibility;
}

int Player::getPower()
{
    return power;
}

int Player::getLives()
{
    return lives;
}

bool Player::checkSilverArmour()
{
    return silverArmour;
}

bool Player::checkEarmuffs()
{
    return earmuffs;
}

bool Player::checkBlueTorch()
{
    return blueTorch;
}

bool Player::checkKnife()
{
    return knife;
}

bool Player::checkSword()
{
    return sword;
}

void Player::attack(Demons* d)
{
    string result, demonName;
    int maxRange = 0;

    for (int i = 0; i < w.size(); i++)
    {
        if (w[i]->getRange() > maxRange)
        {
            maxRange = w[i]->getRange();
        }
    }

    d->phantomAttack(power, visibility, maxRange, result);

    if (result == "win")
    {
        d->decreasePower();
        d->decreaseVisibility();
        increasePower();
        increaseVisibility();
        cin.ignore();
        cout << "You have conquered the demon! Give it a name: ";
        getline(cin, demonName);
        cout << endl;
        d->setName(demonName);
        addDemon(d);
    }
    else if (result == "defeat")
    {
        cout << "The battle is lost. The demon remains untamed!" << endl << endl;
        d->increasePower();
        d->increaseVisibility();
        decreasePower();
        decreaseVisibility();
    }
    else if (result == "Blue Stone")
    {
        if (silverArmour)
        {
            cout << "Your Silver Armour absorbed the Shadow’s Blue Stone! The demon is yours!" << endl;
            d->decreasePower();
            d->decreaseVisibility();
            increasePower();
            increaseVisibility();
            cin.ignore();
            cout << "What will you name your captured demon? ";
            getline(cin, demonName);
            cout << endl;
            d->setName(demonName);
            addDemon(d);
        }
        else
        {
            cout << "Without Silver Armour, the Blue Stone overwhelms you! The demon escapes." << endl;
            d->increasePower();
            d->increaseVisibility();
            decreasePower();
            decreaseVisibility();
        }
    }
    else if (result == "Golden Cloak")
    {
        if (silverArmour && blueTorch)
        {
            cout << "Your Blue Torch exposed the demon beneath the Golden Cloak! Victory is yours!" << endl;
            d->decreasePower();
            d->decreaseVisibility();
            increasePower();
            increaseVisibility();
            cin.ignore();
            cout << "Give your newly captured demon a name: ";
            getline(cin, demonName);
            cout << endl;
            d->setName(demonName);
            addDemon(d);
        }
        else
        {
            cout << "The Golden Cloak conceals the demon from you. You are defeated!" << endl;
            d->increasePower();
            d->increaseVisibility();
            decreasePower();
            decreaseVisibility();
        }
    }
    else if (result == "Ghostly Weil")
    {
        if (earmuffs)
        {
            cout << "Your Earmuffs blocked the Ghostly Weil's haunting whispers! The demon is subdued!" << endl;
            d->decreasePower();
            d->decreaseVisibility();
            increasePower();
            increaseVisibility();
            cin.ignore();
            cout << "Give your captured demon a fitting name: ";
            getline(cin, demonName);
            cout << endl;
            d->setName(demonName);
            addDemon(d);
        }
        else
        {
            cout << "The Ghostly Weil’s whispers send shivers down your spine. The battle is lost!" << endl;
            d->increasePower();
            d->increaseVisibility();
            decreasePower();
            decreaseVisibility();
        }
    }
}

void Player::print()
{
    string line;
    ifstream in("Player.txt");
    while (getline(in, line))
    {
        cout << line << endl;
    }
    in.close();

    cout << "\n--- PLAYER STATS ---\n";
    cout << "Name: " << name << endl;
    cout << "Visibility: " << visibility << "%" << endl;
    cout << "Power: " << power << "%" << endl;
    cout << "Lives Remaining: " << lives << endl;

    cout << "\n--- EQUIPMENT ---\n";
    if (silverArmour) cout << "- Silver Armour (Shields against dark forces)\n";
    if (earmuffs) cout << "- Earmuffs (Blocks Ghostly Weil whispers)\n";
    if (blueTorch) cout << "- Blue Torch (Exposes hidden demons)\n";
    if (knife) cout << "- Knife (A swift and deadly blade)\n";
    if (sword) cout << "- Sword (A warrior’s trusted weapon)\n";
    cout << endl;
}

Player::~Player()
{
    d.clear();
    w.clear();
    c.clear();
}
