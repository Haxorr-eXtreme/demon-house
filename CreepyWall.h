#pragma once
#include "Dungeons.h"

class CreepyWall : public Dungeons
{
private:
    std::string dungeonName;
    char mysteryRune; 

public:
    CreepyWall();
    void check(bool& chk);
    void print() const; 
};
