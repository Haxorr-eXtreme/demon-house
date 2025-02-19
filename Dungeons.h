#pragma once
#include <iostream>
#ifndef Dungeons_H
#define Dungeons_H
using namespace std;
class Dungeons
{
private:
	 int timeDelay;
public:
	Dungeons();
	int getTimeDelay();
	virtual void check(bool& chk) = 0;
	virtual void print();
};
#endif
