
#ifndef EX4_ROUGE_H
#define EX4_ROUGE_H

#include "Player.h"

class Rouge : public Player
{
public:
    explicit Rouge(const string name, const string job):
        Player(name, job){}
    void addCoins(const int coins_add) const;
    Rouge(const Rouge&) = default;
    ~Rouge() = default;
    Rouge& operator=(const Rouge& other) = default;
};

#endif