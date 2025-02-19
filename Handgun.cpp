#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Weapons.h"
#include "Handgun.h"
using namespace std;
Handgun :: Handgun()
{
	srand(time(0));
	setWeaponType("Handgun");
	range = 20 + rand() % 131;
	damage = 60;
}
int Handgun :: getRange() const
{
	return range;
}
int Handgun :: getDamage() const
{
	return damage;
}
void Handgun :: print()
{
	Weapons :: print();
	cout << "Range: " << range << " m" << endl;
	cout << "Damage: " << damage << " %" << endl << endl;
}