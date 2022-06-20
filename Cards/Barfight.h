#ifndef BAR_FIGHT_H
#define BAR_FIGHT_H

#include "SpecialCard.h"
#include "../utilities.h"
#include <iostream>

class Barfight : public SpecialCard {

public:
    Barfight();
    ~Barfight() override = default ;
    //-------------------------Methods---------------------------
    void applyEncounter(Player& player) const override;
    //-----------------------------------------------------------
};


#endif