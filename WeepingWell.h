#pragma once
#include <iostream>
#include "Dungeons.h"
#ifndef WeepingWell_H
#define WeepingWell_H
using namespace std;
class WeepingWell : public Dungeons
{
private:
	string dungeonName;
	char key;
public:
	WeepingWell();
	void check(bool& chk);
	void print();
};
#endif
