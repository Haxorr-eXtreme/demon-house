#pragma once
#include <iostream>
#include "Coins.h"
#ifndef PlatinumCoin_H
#define PlatinumCoin_H
using namespace std;
class PlatinumCoin : public Coins
{
private:
	int value;
public:
	PlatinumCoin();
	int getValue();
	void print();
};
#endif
