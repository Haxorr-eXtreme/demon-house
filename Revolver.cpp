#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Weapons.h"
#include "Revolver.h"
using namespace std;
Revolver :: Revolver()
{
	srand(time(0));
	setWeaponType("Revolver");
	range = 30 + rand() % 121;
	damage = 40;
}
int Revolver :: getRange() const
{
	return range;
}
int Revolver :: getDamage() const
{
	return damage;
}
void Revolver :: print()
{
	Weapons :: print();
	cout << "Range: " << range << " m" << endl;
	cout << "Damage: " << damage << " %" << endl << endl;
}