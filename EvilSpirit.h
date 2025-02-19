#pragma once
#include <iostream>
#include "Demons.h"

#ifndef EVILSPIRIT_H
#define EVILSPIRIT_H

using namespace std;

class EvilSpirit : public Demons
{
private:
    string type;
    string speciality;
    int phantomAttackSpeed;
    int cursedElixirIntensity;

public:
    EvilSpirit();
    
    string getDemonType();
    string getSpeciality();
    int getPhantomAttackSpeed();

    void phantomAttack(int p, int v, int r, string& res);
    void print();
};

#endif
