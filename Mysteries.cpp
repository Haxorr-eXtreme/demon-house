#include <iostream>
#include "Mysteries.h"
using namespace std;
Mysteries :: Mysteries()
{
	mysteryType = "";
}
void Mysteries :: setMysteryType(string mt)
{
	mysteryType = mt;
}
string Mysteries :: getMysteryType()
{
	return mysteryType;
}