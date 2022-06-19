#include "Treasure.h"
#define TREASURE_COINS 10
//-----------------------------------------------------------
Treasure::Treasure() : SpecialCard::SpecialCard("Treasure")
{
}
//-----------------------------------------------------------
void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(TREASURE_COINS);
    printTreasureMessage();
}
//-----------------------------------------------------------