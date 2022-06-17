
#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter : public Player
{
public:
    explicit Fighter(const string name, const string job):
                Player(name, job){}
    
    Fighter(const Fighter&) = default;
    ~Fighter() = default;
    
    int getAttackStrength() const override;


};
#endif