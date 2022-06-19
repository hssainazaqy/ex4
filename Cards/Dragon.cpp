#include "Dragon.h"

#define DRAGON_FORCE 25
#define DRAGON_DAMAGE 10000000
#define DRAGON_LOOT 1000

Dragon::Dragon() : BattleCard::BattleCard("Dragon",DRAGON_FORCE,DRAGON_DAMAGE,DRAGON_LOOT)
{
}
//-----------------------------------------------------------
void Dragon::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() < m_force){
        printLossBattle(player.getName(),m_name);
        player.damage(player.getHp());
    }
    else{
        printWinBattle(player.getName(),m_name);
        player.addCoins(m_loot);
        player.levelUp();
    }
}
//-----------------------------------------------------------
void Dragon::printInfo() const
{
    printMonsterDetails(std::cout,DRAGON_FORCE,DRAGON_DAMAGE,DRAGON_LOOT, true);
    printEndOfCardDetails(std::cout);
}