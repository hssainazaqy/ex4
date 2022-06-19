#ifndef GOBLIN_H
#define GOBLIN_H

#include "BattleCard.h"
#include "../utilities.h"
#include <iostream>

class Goblin : public BattleCard {
public:
    Goblin();
    //-------------------------Methods---------------------------
    void applyEncounter(Player& player) const override;
    //-----------------------------------------------------------
};

#endif