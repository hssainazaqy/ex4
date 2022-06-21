#include "Merchant.h"
#include <iostream>

#define HEALTH_POTION 1
#define BOOST 2
#define HEAL 1
#define BUFF 1
#define HEAL_PRICE 5
#define BUFF_PRICE 10

//-----------------------------------------------------------
Merchant::Merchant() : SpecialCard::SpecialCard("Merchant")
{
}
//-----------------------------------------------------------
void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    int paid_coins = 0;
    int purchased = 0;
    bool sale_done = false;
    std::string input;
    while (!sale_done){
        if(!getline(std::cin,input)){
            printInvalidInput();
            continue;
        }

        if(input.compare("0")){
            sale_done = true;
        }

        if(input.compare("1")){
            if(player.pay(HEAL_PRICE)){
                player.heal(HEAL);
                paid_coins = HEAL_PRICE;
            }else{
                printMerchantInsufficientCoins(std::cout);
                purchased = HEALTH_POTION;
            }
            sale_done = true;
        }

        if(input.compare("2")) {
            if (player.pay(BUFF_PRICE)) {
                player.heal(BUFF);
                paid_coins = BUFF_PRICE;
            } else {
                printMerchantInsufficientCoins(std::cout);
                purchased = BOOST;
            }
            sale_done = true;
        }
    }
    printMerchantSummary(std::cout,player.getName(),purchased,paid_coins);
}
//-----------------------------------------------------------