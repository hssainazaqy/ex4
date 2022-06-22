#include <string>

#define A 'A'
#define a 'a'
#define Z 'Z'
#define z 'z'
//----------------------------------------------------------
bool CheckValidJob(std::string name){
    bool valid = false;
    if(name.compare("Fighter") == 0){
        valid = true;
    }
    if(name.compare("Rogue") == 0){
        valid = true;
    }
    if(name.compare("Wizard") == 0){
        valid = true;
    }
    return valid;
}
//----------------------------------------------------------
bool CheckValidName(std::string name){
    int name_len = name.length();
    int valid = true;

    if(name_len == 0){
        valid = false;
    }
    for (int i = 0; i < name_len; ++i) {
        if((name[i]<= A) ||(name[i] >= Z)&&(name[i]<= a)||(name[i] >= Z)){
            valid = false;
            break;
        }
    }
    return valid;
}
//----------------------------------------------------------
#include "Mtmchkin.h"
#include "utilities.h"
#include <ostream>
#include <deque>
#include <memory>
#include <fstream>
#include <string>

#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"

#include "Cards/Card.h"

#include "Cards/BattleCard.h"
#include "Cards/Dragon.h"
#include "Cards/Goblin.h"
#include "Cards/Vampire.h"

#include "Cards/SpecialCard.h"
#include "Cards/Treasure.h"
#include "Cards/Fairy.h"
#include "Cards/Barfight.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"

#include "Exception.h"



#define EMPTY_SPACE ' '

Mtmchkin::Mtmchkin(const std::string &fileName): m_rounds_number(0),m_playing(new deque<std::shared_ptr<Player>>),
                                                 m_winners(new deque<std::shared_ptr<Player>>),
                                                 m_losers(new deque<std::shared_ptr<Player>>),
                                                 m_cards(new deque<std::shared_ptr<Card>>)
{
    int card_number = 0, player_number = 0, team_size = 0;
    std::ifstream card_file;
    std:string curr_line;
    card_file.open(fileName);
    //card deck initialization
    if(card_file.is_open())
    {
        while(getline(card_file, curr_line, EMPTY_SPACE))
        {
            if(curr_line.compare("Fairy") == 0)
            {
                std::shared_ptr<Card> card(new Fairy());
                m_cards.push_back(card);
            }

            if(curr_line.compare("Pitfall") == 0)
            {
                std::shared_ptr<Card> card(new Pitfall());
                m_cards.push_back(card);
            }

            else if(curr_line.compare("Goblin") == 0)
            {
                std::shared_ptr<Card> card(new Goblin());
                m_cards.push_back(card);
            }

            else if(curr_line.compare("Vampire") == 0)
            {
                std::shared_ptr<Card> card(new Vampire());
                m_cards.push_back(card);
            }

            else if(curr_line.compare("Dragon") == 0)
            {
                std::shared_ptr<Card> card(new Dragon());
                m_cards.push_back(card);
            }

            else if(curr_line.compare("Barfight") == 0)
            {
                std::shared_ptr<Card> card(new Barfight());
                m_cards.push_back(card);
            }

            else if(curr_line.compare("Merchant") == 0)
            {
                std::shared_ptr<Card> card(new Merchant());
                m_cards.push_back(card);
            }

            else if(curr_line.compare("Treasure") == 0)
            {
                std::shared_ptr<Card> card(new Treasure());
                m_cards.push_back(card);
            }

            else
            {
                throw DeckFileFormatError(card_number);
            }

            card_number++;
        }
        if(card_number < 5)
        {
            throw DeckFileInvalidSize();
        }
    }
    else
    {
        throw DeckFileNotFound();
    }
    printStartGameMessage();
    printEnterTeamSizeMessage();


    std::string str;
    std::string tmp_str;
    int tmp_int;

    std::cin >> str;
    tmp_int = stoi(str);
    tmp_str = std::to_string(tmp_int);
    while ((team_size > 6 || team_size < 2) || tmp_str.compare(str) != 0)
    {
        printInvalidTeamSize();
        std::cin >> str;
        tmp_int = stoi(str);
        tmp_str = std::to_string(tmp_int);
    }
    team_size = tmp_int;


    printInsertPlayerMessage();
    std::string player_name, player_job;
    player_number = 0;
    while (player_number < team_size)
    {
        std::cin >> player_name >> player_job;
        if(CheckValidName(player_name) && CheckValidJob(player_job))
        {
            if(player_name.compare("Fighter") == 0)
            {
                std::shared_ptr<Player> player(new Fighter(player_name, player_job));
                m_playing.push_back(player);
            }

            else if(player_name.compare("Rogue") == 0)
            {
                std::shared_ptr<Player> player(new Rogue(player_name, player_job));
                m_playing.push_back(player);
            }
            else if(player_name.compare("Wizard") == 0)
            {
                std::shared_ptr<Player> player(new Wizard(player_name, player_job));
                m_playing.push_back(player);
            }
            player_number++;
        }
        else if(!CheckValidName(player_name))
        {
            printInvalidName();
            continue;
        }
        else if(!CheckValidJob(player_job))
        {
            printInvalidClass();
            continue;
        }

    }


}





void Mtmchkin::playRound()
{
    m_rounds_number++;
    printRoundStartMessage(getNumberOfRounds());
    //for(player in game)
    //takes the current player name
    //printTurnStartMessage(curr_player.name);
    //takes the next card from the deck
    //play that card
    //return the card to the end of the deck


    if(isGameOver())
    {
        printGameEndMessage();
    }
}


void Mtmchkin::printLeaderBoard() const
{

}

bool Mtmchkin::isGameOver() const
{

}

int Mtmchkin::getNumberOfRounds() const
{
    return m_rounds_number;
}


