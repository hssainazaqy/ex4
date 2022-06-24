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
    if(player.getAttackStrength() < m_force){
        printLossBattle(player.getName(),"Goblin");
        player.damage(m_force);
    }
    else{
        printWinBattle(player.getName(),"Goblin");
        player.addCoins(m_loot);
        player.levelUp();
    }
}
//-----------------------------------------------------------
