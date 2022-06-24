#include "Wizard.h"
void Wizard::heal(const int add_hp){
    if(add_hp < 0){
        return;
    }

    if((m_hp + 2*add_hp) > (m_max_hp)){
        m_hp = m_max_hp;
    }
    else{
        m_hp += 2*add_hp;
    }
}
//---------------------------------------------------------
void Wizard::printPlayerInfo(ostream &os) const {
    printPlayerDetails(os, m_name, "Wizard", m_level,m_force, m_hp, m_coins);
}