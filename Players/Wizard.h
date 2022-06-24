
#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H


#include "Player.h"
#include "utilities.h"

class Wizard : public Player
{
public:
    explicit Wizard(const string name, const string job):
        Player(name, job){}

    void printPlayerInfo(ostream &os) const override;
    void heal(const int add_hp) override;


    Wizard(const Wizard&) = default;
    ~Wizard() override = default;

};

#endif