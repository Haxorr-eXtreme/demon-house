#pragma once
#include <iostream>
#include "Weapons.h"
#ifndef Rifle_H
#define Rifle_H
using namespace std;
class Rifle : public Weapons
{
private:
	int range;
	int damage;
public:
	Rifle();
	int getRange() const;
	int getDamage() const;
	void print();
};
#endif
