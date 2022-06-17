#ifndef BAR_FIGHT_H
#define BAR_FIGHT_H

#include "SpecialCard.h"
#include "../utilities.h"
#include <iostream>

class Barfight : public SpecialCard {

public:
    Barfight(std::string name);
    //-------------------------Methods---------------------------
    //needs applyEncounter
    //needs printInfo
    void applyEncounter(Player& player) const override;
    void printInfo() const override;
    //-----------------------------------------------------------
};


#endif