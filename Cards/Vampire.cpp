#include "Vampire.h"

#define VAMPIRE_FORCE 10
#define VAMPIRE_DAMAGE 10
#define VAMPIRE_LOOT 2

Vampire::Vampire() : BattleCard::BattleCard("Vampire",VAMPIRE_FORCE,VAMPIRE_DAMAGE,VAMPIRE_LOOT)
{
}
//-----------------------------------------------------------
void Vampire::applyEncounter(Player& player) const
{

}
//-----------------------------------------------------------
void Vampire::printInfo() const //NEEDS FIXING, NEED TO FIGURE OUT WHAT OS TO SEND
{
    printCardDetails();
    printEndOfCardDetails();
}