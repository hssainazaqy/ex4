#include "BattleCard.h"

BattleCard::BattleCard(const std::string name,int force,int hp_loss,int loot ):
            Card(name,CardType::Battle),m_force(force),m_hp_loss(hp_loss),m_loot(DEFAULT_LOOT)
{
    if(force < 0){
        m_force = DEFAULT_FORCE;
    }
    if(hp_loss < 0){
        m_hp_loss = DEFAULT_HP_LOSS;
    }
    if(loot < 0){
        m_loot = DEFAULT_LOOT;
    }
}
//----------------------------------------------------------
void BattleCard::printInfo(ostream& os) const
{
    bool isDragon = false;
    if(m_name.compare("Dragon") == 0){
        isDragon = true;
    }
    printCardDetails(os,m_name);
    printMonsterDetails(os,m_force,m_hp_loss,m_loot,isDragon);
    printEndOfCardDetails(os);
}
//----------------------------------------------------------