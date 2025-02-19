#include <iostream>
#include "Coins.h"
#include "PlatinumCoin.h"
using namespace std;
PlatinumCoin :: PlatinumCoin()
{
	setCoinType("Platinum");
	value = 10000;
}
int PlatinumCoin :: getValue()
{
	return value;
}
void PlatinumCoin :: print()
{
	Coins :: print();
	cout << "Value: " << value << " points" << endl << endl;
}