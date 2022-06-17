#ifndef DRAGON_H
#define DRAGON_H

#include "BattleCard.h"
#include "../utilities.h"
#include <iostream>

class Dragon : public BattleCard {
    Dragon();
    //-------------------------Methods---------------------------
    void applyEncounter(Player& player) const override;
    void printInfo() const override;
    //-----------------------------------------------------------
};

#endif