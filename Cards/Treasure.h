#ifndef TREASURE_H
#define TREASURE_H

#include "SpecialCard.h"
#include "../utilities.h"
#include <iostream>

class Treasure : public SpecialCard {

public:
    Treasure();
    ~Treasure() override = default;
    //-------------------------Methods---------------------------
    void applyEncounter(Player& player) const override;
    //-----------------------------------------------------------
};

#endif