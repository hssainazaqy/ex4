#include "Fighter.h"

int Fighter::getAttackStrength() const{
    return (2*m_force + m_level);
}
