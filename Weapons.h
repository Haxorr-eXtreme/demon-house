#pragma once
#include <iostream>
#ifndef Weapons_H
#define Weapons_H
using namespace std;
class Weapons
{
private:
	string weaponType;
	int ammo;
public:
	Weapons();
	void setWeaponType(string w);
	string getWeaponType() const;
	int getAmmo() const;
	virtual int getRange() const = 0;
	virtual int getDamage() const = 0;
	virtual void print();
};
#endif
