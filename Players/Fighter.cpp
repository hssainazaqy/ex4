#include "Fighter.h"

int Fighter::getAttackStrength() const{
    return (2*m_force + m_level);
}
//---------------------------------------------------------
void Fighter::printPlayerInfo(ostream &os) const {
    printPlayerDetails(os, m_name, "Fighter", m_level,m_force, m_hp, m_coins);
}