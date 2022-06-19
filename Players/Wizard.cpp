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
