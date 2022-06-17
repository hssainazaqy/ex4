#ifndef PITFALL_H
#define PITFALL_H

#include "SpecialCard.h"
#include "../utilities.h"
#include <iostream>

class Pitfall : public SpecialCard {

public:
    Pitfall(std::string name);
    //-------------------------Methods---------------------------
    //needs applyEncounter
    //needs printInfo
    void applyEncounter(Player& player) const override;
    void printInfo() const override;
    //-----------------------------------------------------------
};

#endif