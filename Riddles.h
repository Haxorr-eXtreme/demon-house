#pragma once
#include <iostream>
#include "Mysteries.h"
#ifndef Riddles_H
#define Riddles_H
using namespace std;
class Riddles : public Mysteries
{
private:
	int riddle;
public:
	Riddles();
	void solveMystery(bool& chk1);
};
#endif
