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
    if(player.getAttackStrength() < m_force){
        printLossBattle(player.getName(),m_name);
        player.damage(m_force);
        player.setForce(player.getForce()-1);
    }
    else{
        printWinBattle(player.getName(),m_name);
        player.addCoins(m_loot);
        player.levelUp();
    }
}
//-----------------------------------------------------------
void Vampire::printInfo() const
{
    printMonsterDetails(std::cout,VAMPIRE_FORCE,VAMPIRE_DAMAGE,VAMPIRE_LOOT, false);
    printEndOfCardDetails(std::cout);
}