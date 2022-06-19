#ifndef FAIRY_H
#define FAIRY_H

#include "SpecialCard.h"
#include "../utilities.h"
#include <iostream>

class Fairy : public SpecialCard {

public:
    Fairy();
    //-------------------------Methods---------------------------
    void applyEncounter(Player& player) const override;
    //-----------------------------------------------------------
};

#endif