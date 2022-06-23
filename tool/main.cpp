#include <iostream>
#include "Mtmchkin.h"
#include "Exception.h"

#define MAX_NUM_OF_ROUNDS 100
int main(){

    try{
        Mtmchkin Game("deck.txt");
        while(!Game.isGameOver() && Game.getNumberOfRounds() <MAX_NUM_OF_ROUNDS){
            Game.playRound();
        }
        Game.printLeaderBoard();
    }catch(std::exception &e) {
        std::cout << e.what();
    }
    return 0;
}