#pragma once
#include <iostream>
#include "Weapons.h"
#ifndef Shotgun_H
#define Shotgun_H
using namespace std;
class Shotgun : public Weapons
{
private:
	int range;
	int damage;
public:
	Shotgun();
	int getRange() const;
	int getDamage() const;
	void print();
};
#endif
