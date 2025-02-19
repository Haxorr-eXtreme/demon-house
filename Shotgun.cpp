#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Weapons.h"
#include "Shotgun.h"
using namespace std;
Shotgun :: Shotgun()
{
	srand(time(0));
	setWeaponType("Shotgun");
	range = 50 + rand() % 226;
	damage = 70;
}
int Shotgun :: getRange() const
{
	return range;
}
int Shotgun :: getDamage() const
{
	return damage;
}
void Shotgun :: print()
{
	Weapons :: print();
	cout << "Range: " << range << " m" << endl;
	cout << "Damage: " << damage << " %" << endl << endl;
}