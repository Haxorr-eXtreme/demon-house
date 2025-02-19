#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Demons.h"
using namespace std;
int Demons :: visibilities[5] = {20, 40, 60, 80, 100};
Demons :: Demons()
{
	srand(time(0));
	int r;
	r = 0 + rand() % 5;
	vis = visibilities[r];
	name = "Unknown";
	power = 50;
}
void Demons :: setName(string dn)
{
	name = dn;
}
void Demons :: setFlyingSpeed(int fs)
{
	flyingSpeed = fs;
}
string Demons :: getName()
{
	return name;
}
int Demons :: getVisibility()
{
	return vis;
}
int Demons :: getPower()
{
	return power;
}
int Demons :: getFlyingSpeed()
{
	return flyingSpeed;
}
void Demons :: increasePower()
{
	power = power + 10;
}
void Demons :: decreasePower()
{
	power = power - 10;
}
void Demons :: increaseVisibility()
{
	vis = vis + 10;
}
void Demons :: decreaseVisibility()
{
	vis = vis - 10;
}
void Demons :: print()
{
	cout << " Demon's Name: " << name << endl;
	cout << " Demon's Power: " << power << " %" << endl;
	cout << " Demon's Visibility: " << vis << " %" << endl;
	cout << "Demon's Flying Speed: " << flyingSpeed << " m/s" << endl;
}
