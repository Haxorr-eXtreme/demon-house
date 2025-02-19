#pragma once
#include <iostream>
#ifndef Coins_H
#define Coins_H
using namespace std;
class Coins
{
private:
	string coinType;
public:
	Coins();
	void setCoinType(string c);
	virtual int getValue() = 0;
	string getCoinType();
	virtual void print();
};
#endif
