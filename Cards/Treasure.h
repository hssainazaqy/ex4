#ifndef TREASURE_H
#define TREASURE_H

#include "SpecialCard.h"
#include "../utilities.h"
#include <iostream>

class Treasure : public SpecialCard {

public:
    Treasure(std::string name);
    //-------------------------Methods---------------------------
    //needs applyEncounter
    //needs printInfo
    void applyEncounter(Player& player) const override;
    void printInfo() const override;
    //-----------------------------------------------------------
};

#endif