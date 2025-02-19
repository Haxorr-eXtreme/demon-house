#include <iostream>
#include <cstdlib>
#include <ctime>
#include "WeepingWell.h"
#include "Dungeons.h"
using namespace std;
WeepingWell :: WeepingWell()
{
	srand(time(0));
	dungeonName = "Weeping Well";
	key = 'a' + rand() % 26;
}
void WeepingWell :: check(bool& chk)
{
	char finding;
	cout << "Find The Correct Key (a-z) To Escape The Bloody Creepy Weeping Well: ";
	cin >> finding;
	cout << endl;
	if (finding == key)
	{
		cout << "->Correct Key Found, Escaped The Dungeon With Increase In Power & Visibility<-" << endl << endl;
		chk = true;
	}
	else
	{
		cout << "->Incorrect Key Found, Escaped The Dungeon With Fatal Injuries Decreasing Power & Visibility<-" << endl << endl;
	    chk = false;
	}
}
void WeepingWell :: print()
{
	cout << "Dungeon Name: " << dungeonName << endl;
	Dungeons :: print();
}
