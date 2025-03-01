#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <deque>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"

class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    Mtmchkin(const Mtmchkin&) = delete;
    Mtmchkin& operator=(const Mtmchkin& other) = delete;

private:
    int m_rounds_number;
    deque<std::shared_ptr<Player>> m_playing;
    deque<std::shared_ptr<Player>> m_winners;
    deque<std::shared_ptr<Player>> m_losers;
    deque<std::shared_ptr<Card>> m_cards;

};



#endif /* MTMCHKIN_H_ */
