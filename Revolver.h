#pragma once
#include <iostream>
#include "Weapons.h"
#ifndef Revolver_H
#define Revolver_H
using namespace std;
class Revolver : public Weapons
{
private:
	int range;
	int damage;
public:
	Revolver();
	int getRange() const;
	int getDamage() const;
	void print();
};
#endif
