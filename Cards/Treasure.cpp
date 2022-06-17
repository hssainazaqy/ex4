#include "Treasure.h"

//-----------------------------------------------------------
Treasure::Treasure(std::string name) : SpecialCard::SpecialCard(name)
{
}
//-----------------------------------------------------------
void Treasure::applyEncounter(Player& player) const
{
    //NEEDS IMPLEMENTATION
}
//-----------------------------------------------------------
void Treasure::printInfo() const //NEEDS FIXING, NEED TO FIGURE OUT WHAT OS TO SEND
{
    printCardDetails();
    printEndOfCardDetails();
}