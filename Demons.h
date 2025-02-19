#pragma once
#include <iostream>
#ifndef Demons_H
#define Demons_H
using namespace std;
class Demons
{
private:
	string name;
	int vis;
	static int visibilities[5];
	int power;
	int flyingSpeed;
public:
	Demons();
	void setName(string dn);
	void setFlyingSpeed(int fs);
	string getName();
	int getVisibility();
	int getPower();
	int getFlyingSpeed();
	virtual string getDemonType() = 0;
	virtual int getPhantomAttackSpeed() = 0;
	virtual string getSpeciality() = 0;
	void increasePower();
	void decreasePower();
	void increaseVisibility();
	void decreaseVisibility();
	virtual void phantomAttack(int p, int v, int r, string& res) = 0;
	virtual void print();
};
#endif