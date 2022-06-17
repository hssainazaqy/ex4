#ifndef Merchant_H
#define Merchant_H

#include "SpecialCard.h"
#include "../utilities.h"
#include <iostream>

class Merchant : public SpecialCard {

public:
    Merchant(std::string name);
    //-------------------------Methods---------------------------
    //needs applyEncounter
    //needs printInfo
    void applyEncounter(Player& player) const override;
    void printInfo() const override;
    //-----------------------------------------------------------
};


#endif