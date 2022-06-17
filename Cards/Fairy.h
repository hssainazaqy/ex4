#ifndef FAIRY_H
#define FAIRY_H

#include "SpecialCard.h"
#include "../utilities.h"
#include <iostream>

class Fairy : public SpecialCard {

public:
    Fairy(std::string name);
    //-------------------------Methods---------------------------
    //needs applyEncounter
    //needs printInfo
    void applyEncounter(Player& player) const override;
    void printInfo() const override;
    //-----------------------------------------------------------
};

#endif