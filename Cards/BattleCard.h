#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H

#include "Card.h"

#define DEFAULT_FORCE 5
#define DEFAULT_LOOT 2
#define DEFAULT_HP_LOSS 10

class BattleCard : public Card {

public:
    BattleCard(std::string name,int force =DEFAULT_FORCE,int hp_loss= DEFAULT_HP_LOSS,int loot =DEFAULT_LOOT);
    //-------------------------Methods---------------------------

    //-----------------------------------------------------------
protected:
    int m_force;
    int m_hp_loss;
    int m_loot;
};

#endif