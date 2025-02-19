#include <iostream>
#include "Coins.h"
#include "GoldCoin.h"
using namespace std;
GoldCoin :: GoldCoin()
{
	setCoinType("Gold");
	value = 5000;
}
int GoldCoin :: getValue()
{
	return value;
}
void GoldCoin :: print()
{
	Coins :: print();
	cout << "Value: " << value << " points" << endl << endl;
}