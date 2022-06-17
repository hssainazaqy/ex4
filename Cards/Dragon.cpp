#include "Dragon.h"

#define DRAGON_FORCE 25
#define DRAGON_DAMAGE 10000000
#define DRAGON_LOOT 2

Dragon::Dragon() : BattleCard::BattleCard("Dragon",DRAGON_FORCE,DRAGON_DAMAGE,DRAGON_LOOT)
{
}
//-----------------------------------------------------------
void Dragon::applyEncounter(Player& player) const
{
    //NEEDS IMPLEMENTATION
}
//-----------------------------------------------------------
void Dragon::printInfo() const //NEEDS FIXING, NEED TO FIGURE OUT WHAT OS TO SEND
{
    printCardDetails();
    printEndOfCardDetails();
}