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
        printLossBattle(player.getName(),"Dragon");
        player.damage(player.getHp());
    }
    else{
        printWinBattle(player.getName(),"Dragon");
        player.addCoins(m_loot);
        player.levelUp();
    }
}
//-----------------------------------------------------------
void Dragon::printInfo(ostream& os) const
{
    printMonsterDetails(os,m_force,m_hp_loss,m_loot, true);
}