#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "BattleCard.h"
#include "../utilities.h"
#include <iostream>

class Vampire : public BattleCard {
public:
    Vampire();
    //-------------------------Methods---------------------------
    void applyEncounter(Player& player) const override;
    //-----------------------------------------------------------
};

#endif