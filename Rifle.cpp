#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Weapons.h"
#include "Rifle.h"
using namespace std;
Rifle :: Rifle()
{
	srand(time(0));
	setWeaponType("Rifle");
	range = 50 + rand() % 51;
	damage = 50;
}
int Rifle :: getRange() const
{
	return range;
}
int Rifle :: getDamage() const
{
	return damage;
}
void Rifle :: print()
{
	Weapons :: print();
	cout << "Range: " << range << " m" << endl;
	cout << "Damage: " << damage << " %" << endl << endl;
}