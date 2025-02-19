#include <iostream>
#include "Coins.h"
using namespace std;
Coins :: Coins()
{
	coinType = "";
}
void Coins :: setCoinType(string c)
{
	coinType = c;
}
string Coins :: getCoinType()
{
	return coinType;
}
void Coins :: print()
{
	cout << "Coin Type: " << coinType << endl;
}