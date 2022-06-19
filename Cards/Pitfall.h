#ifndef PITFALL_H
#define PITFALL_H

#include "SpecialCard.h"
#include "../utilities.h"
#include <iostream>

class Pitfall : public SpecialCard {

public:
    Pitfall();
    //-------------------------Methods---------------------------
    void applyEncounter(Player& player) const override;
    //-----------------------------------------------------------
};

#endif