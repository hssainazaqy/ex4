
#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"
#include "utilities.h"
class Fighter : public Player
{
public:
    explicit Fighter(const string name, const string job):
                Player(name, job){}
    
    Fighter(const Fighter&) = default;
    ~Fighter() override = default;

    void printPlayerInfo(ostream &os) const override;
    int getAttackStrength() const override;


};
#endif