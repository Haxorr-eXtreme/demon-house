#pragma once
#include "Dungeons.h"

class DarkDungeon : public Dungeons
{
private:
    std::string dungeonName;
    char ancientRune;  

public:
    DarkDungeon();
    void check(bool& chk);
    void print() const; 
};
