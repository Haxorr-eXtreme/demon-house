#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Dungeons.h"
using namespace std;
Dungeons :: Dungeons()
{
	srand(time(0));
	timeDelay = 1 + rand() % 121;
}
int Dungeons :: getTimeDelay()
{
	return timeDelay;
}
void Dungeons :: print()
{
	cout << "Time Delay: " << timeDelay << " s" << endl << endl;
}