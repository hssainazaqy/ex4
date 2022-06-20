
#ifndef EX4_ROUGE_H
#define EX4_ROUGE_H

#include "Player.h"

class Rogue : public Player
{
public:
    explicit Rogue(const string name, const string job):
        Player(name, job){}
    void addCoins(const int coins_add) override;

    Rogue(const Rogue&) = default;
    ~Rogue() override = default;
};

#endif