#include "Merchant.h"

//-----------------------------------------------------------
Merchant::Merchant(std::string name) : SpecialCard::SpecialCard(name)
{
}
//-----------------------------------------------------------
void Merchant::applyEncounter(Player& player) const
{
    //NEEDS IMPLEMENTATION
}
//-----------------------------------------------------------
void Merchant::printInfo() const //NEEDS FIXING, NEED TO FIGURE OUT WHAT OS TO SEND
{
    printCardDetails();
    printEndOfCardDetails();
}