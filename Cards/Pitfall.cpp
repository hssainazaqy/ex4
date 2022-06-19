#include "Pitfall.h"

#define PITFALL_DAMAGE 10
//-----------------------------------------------------------
Pitfall::Pitfall() : SpecialCard::SpecialCard("Pitfall")
{
}
//-----------------------------------------------------------
void Pitfall::applyEncounter(Player& player) const
{
    bool isRogue = false;
    if(player.getJob().compare("Rogue") == 0){
        isRogue = true;
    }

    if(!isRogue){
        player.damage(PITFALL_DAMAGE);
    }
    printPitfallMessage(isRogue);
}
//-----------------------------------------------------------

