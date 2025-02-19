#include <iostream>
#include "Coins.h"
#include "SilverCoin.h"
using namespace std;
SilverCoin :: SilverCoin()
{
	setCoinType("Silver");
	value = 1000;
}
int SilverCoin :: getValue()
{
	return value;
}
void SilverCoin :: print()
{
	Coins :: print();
	cout << "Value: " << value << " points" << endl << endl;
}