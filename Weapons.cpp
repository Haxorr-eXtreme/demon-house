#include <iostream>
#include "Weapons.h"
using namespace std;
Weapons :: Weapons()
{
	weaponType = "";
	ammo = 10;
}
void Weapons :: setWeaponType(string w)
{
	weaponType = w;
}
string Weapons :: getWeaponType() const
{
	return weaponType;
}
int Weapons :: getAmmo() const
{
	return ammo;
}
void Weapons :: print()
{
	cout << "Weapon Type: " << weaponType << endl;
	cout << "Ammo: " << ammo << endl;
}