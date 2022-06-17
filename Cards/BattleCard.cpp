#include "BattleCard.h"

BattleCard::BattleCard(std::string name,int force,int hp_loss,int loot ):
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

