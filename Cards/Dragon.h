#ifndef DRAGON_H
#define DRAGON_H

#include "BattleCard.h"
#include "../utilities.h"
#include <iostream>

class Dragon : public BattleCard {

public:
    Dragon();
    ~Dragon() override =default;
    //-------------------------Methods---------------------------
    void applyEncounter(Player& player) const override;
    void printInfo(ostream& os) const override;
    //-----------------------------------------------------------


};

#endif