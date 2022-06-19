#include "Card.h"

//-----------------------constructor-------------------------
Card::Card(std::string name ,CardType type):
        m_name(name),m_cardType(type)
{
}
//-----------------------------------------------------------
ostream& operator<<(ostream& os, const Card& card)
{
    card.printInfo(os);
    return os;
}
//-----------------------------------------------------------
void Card::printInfo(ostream& os) const
{
    printCardDetails(os,m_name);
    printEndOfCardDetails(os);
}


