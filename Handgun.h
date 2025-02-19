#pragma once
#include <iostream>
#include "Weapons.h"
#ifndef Handgun_H
#define Handgun_H
using namespace std;
class Handgun : public Weapons
{
private:
	int range;
	int damage;
public:
	Handgun();
	int getRange() const;
	int getDamage() const;
	void print();
};
#endif
