#include "Fairy.h"

#define FAIRY_HEAL 10
//-----------------------------------------------------------
Fairy::Fairy(const std::string name) : SpecialCard::SpecialCard("Fairy")
{
}
//-----------------------------------------------------------
void Fairy::applyEncounter(Player& player) const
{
    if(player.getJob().compare("Wizard") == 0){
        player.heal(FAIRY_HEAL);
    }
}
//-----------------------------------------------------------