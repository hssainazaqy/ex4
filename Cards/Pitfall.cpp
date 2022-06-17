#include "Pitfall.h"

//-----------------------------------------------------------
Pitfall::Pitfall(std::string name) : SpecialCard::SpecialCard(name)
{
}
//-----------------------------------------------------------
void Pitfall::applyEncounter(Player& player) const
{
    //NEEDS IMPLEMENTATION
}
//-----------------------------------------------------------
void Pitfall::printInfo() const //NEEDS FIXING, NEED TO FIGURE OUT WHAT OS TO SEND
{
    printCardDetails();
    printEndOfCardDetails();
}