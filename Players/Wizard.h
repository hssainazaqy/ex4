
#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H


#include "Player.h"


class Wizard : public Player
{
public:
    explicit Wizard(const string name, const string job):
        Player(name, job){}

    void heal(const int add_hp) override;


    Wizard(const Wizard&) = default;
    ~Wizard() = default;
    Wizard& operator=(const Wizard& other) = default;
};

#endif