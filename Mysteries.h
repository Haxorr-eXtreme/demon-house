#pragma once
#include <iostream>
#ifndef Mysteries_H
#define Mysteries_H
using namespace std;
class Mysteries
{
private:
	string mysteryType;
public:
	Mysteries();
	void setMysteryType(string mt);
	string getMysteryType();
	virtual void solveMystery(bool& chk1) = 0;
};
#endif
