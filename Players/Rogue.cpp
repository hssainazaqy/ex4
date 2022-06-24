#include "Rogue.h"

void Rogue::addCoins (const int coins_add){
    m_coins += 2*coins_add;
}
//---------------------------------------------------------
void Rogue::printPlayerInfo(ostream &os) const {
    printPlayerDetails(os, m_name, "Rogue", m_level,m_force, m_hp, m_coins);
}