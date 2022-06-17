#include "Barfight.h"

//-----------------------------------------------------------
Barfight::Barfight(std::string name) : SpecialCard::SpecialCard(name)
{
}
//-----------------------------------------------------------
void Barfight::applyEncounter(Player& player) const
{
    //NEEDS IMPLEMENTATION
}
//-----------------------------------------------------------
void Barfight::printInfo() const //NEEDS FIXING, NEED TO FIGURE OUT WHAT OS TO SEND
{
    printCardDetails();
    printEndOfCardDetails();
}