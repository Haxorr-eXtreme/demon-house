#pragma once
#include <iostream>
#include "Demons.h"
#ifndef Vampire_H
#define Vampire_H
using namespace std;
class Vampire : public Demons
{
private:
	string type;
	string speciality1;
	string speciality2;
	int phantomAttackSpeed;
	int frequency;
	static int ghostlyWeils[5];
public:
	Vampire();
	string getDemonType();
	string getSpeciality();
	int getPhantomAttackSpeed();
	void phantomAttack(int p, int v, int r, string& res);
	void print();
};
#endif
