#pragma once
#include "Demons.h"

class BlackDevil : public Demons
{
private:
    std::string type;
    std::string speciality;
    int phantomAttackSpeed;
    int daggerPoisonIntensity;

public:
    BlackDevil();
    
    std::string getDemonType() const;
    std::string getSpeciality() const;
    int getPhantomAttackSpeed() const;

    void phantomAttack(int p, int v, int r, std::string& res);
    void print();
};
