#include "Goblin.h"

#define GOBLIN_FORCE 6
#define GOBLIN_DAMAGE 10
#define GOBLIN_LOOT 2

Goblin::Goblin() : BattleCard::BattleCard("Goblin",GOBLIN_FORCE,GOBLIN_DAMAGE,GOBLIN_LOOT)
{
}
//-----------------------------------------------------------
void Goblin::applyEncounter(Player& player) const
{
    //NEEDS IMPLEMENTATION
}
//-----------------------------------------------------------
void Goblin::printInfo() const //NEEDS FIXING, NEED TO FIGURE OUT WHAT OS TO SEND
{
    printCardDetails();
    printEndOfCardDetails();
}