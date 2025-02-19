#pragma once

#include <iostream>
#include "Demons.h"

#ifndef HUNGRY_SKELETON_H
#define HUNGRY_SKELETON_H

using namespace std;

class HungrySkeleton : public Demons
{
private:
    string type;
    string speciality;
    int phantomAttackSpeed;

public:
    // Constructor
    HungrySkeleton();

    // Getters
    string getDemonType();
    string getSpeciality();
    int getPhantomAttackSpeed();

    // Game-related methods
    void phantomAttack(int p, int v, int r, string& res);
    void print();
};

#endif // HUNGRY_SKELETON_H
