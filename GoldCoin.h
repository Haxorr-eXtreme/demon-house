#pragma once
#include <iostream>
#include "Coins.h"
#ifndef GoldCoin_H
#define GoldCoin_H
using namespace std;
class GoldCoin : public Coins
{
private:
	int value;
public:
	GoldCoin();
	int getValue();
	void print();
};
#endif
