#ifndef Merchant_H
#define Merchant_H

#include "SpecialCard.h"
#include "../utilities.h"
#include <iostream>

class Merchant : public SpecialCard {

public:
    Merchant();
    ~Merchant() override = default;
    //-------------------------Methods---------------------------
    void applyEncounter(Player& player) const override;
    //-----------------------------------------------------------

};


#endif