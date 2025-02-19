#pragma once
#include <iostream>
#include "Demons.h"
#ifndef Shadow_H
#define Shadow_H
using namespace std;
class Shadow : public Demons
{
private:
	string type;
	string speciality;
	int phantomAttackSpeed;
public:
	Shadow();
	string getDemonType();
	string getSpeciality();
	int getPhantomAttackSpeed();
	void phantomAttack(int p, int v, int r, string& res);
	void print();
};
#endif
