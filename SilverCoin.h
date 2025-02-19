#pragma once
#include <iostream>
#include "Coins.h"
#ifndef SilverCoin_H
#define SilverCoin_H
using namespace std;
class SilverCoin : public Coins
{
private:
	int value;
public:
	SilverCoin();
	int getValue();
	void print();
};
#endif
