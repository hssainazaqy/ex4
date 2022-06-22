#include "SpecialCard.h"

//-----------------------------------------------------------
SpecialCard::SpecialCard(const std::string name) : Card(name,CardType::Special)
{
}
//-----------------------------------------------------------
void SpecialCard::printInfo(ostream& os) const
{
    printCardDetails(os,m_name);
    printEndOfCardDetails(os);
}