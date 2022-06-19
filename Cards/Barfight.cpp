#include "Barfight.h"

#define BARFIGHT_DAMAGE 10
//-----------------------------------------------------------
Barfight::Barfight() : SpecialCard::SpecialCard("BarFight")
{
}
//-----------------------------------------------------------
void Barfight::applyEncounter(Player& player) const
{
    bool isFighter = false;
    if(player.getJob().compare("Fighter") == 0){
        isFighter = true;
    }

    if(!isFighter){
        player.damage(BARFIGHT_DAMAGE);
    }
    printBarfightMessage(isFighter);
}
//-----------------------------------------------------------