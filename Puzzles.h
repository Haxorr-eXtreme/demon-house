#pragma once
#include <iostream>
#include "Mysteries.h"
#ifndef Puzzles_H
#define Puzzles_H
using namespace std;
class Puzzles : public Mysteries
{
private:
	char bone;
public:
	Puzzles();
	void solveMystery(bool& chk1);
};
#endif