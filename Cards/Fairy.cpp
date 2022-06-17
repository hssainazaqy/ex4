#include "Fairy.h"

//-----------------------------------------------------------
Fairy::Fairy(std::string name) : SpecialCard::SpecialCard(name)
{
}
//-----------------------------------------------------------
void Fairy::applyEncounter(Player& player) const
{
    //NEEDS IMPLEMENTATION
}
//-----------------------------------------------------------
void Fairy::printInfo() const //NEEDS FIXING, NEED TO FIGURE OUT WHAT OS TO SEND
{
    printCardDetails();
    printEndOfCardDetails();
}