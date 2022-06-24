
#include "Mtmchkin.h"
#include "utilities.h"
#include <ostream>
#include <iostream>
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


#define MAX_NAME_LENGTH 15
#define TEN 10
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

    if(name_len == 0 || name_len > MAX_NAME_LENGTH){
        valid = false;
        return valid;
    }
    for (int i = 0; i < name_len; ++i) {
        if(((name[i]< A) ||(name[i] > Z))&&((name[i]< a)||(name[i] > z))){
            valid = false;
            break;
        }
    }
    return valid;
}
//----------------------------------------------------------

Mtmchkin::Mtmchkin(const std::string &fileName): m_rounds_number(0),m_playing(),m_winners(),m_losers(),
                                                 m_cards()
{
    int card_number = 0;
    std::ifstream card_file;
    std::string curr_line;
    card_file.open(fileName);

    //card deck initialization
    if(card_file.is_open())
    {
        while(getline(card_file, curr_line))
        {
            if(curr_line.compare("Fairy") == 0)
            {
                std::shared_ptr<Card> card(new Fairy());
                m_cards.push_back(card);
            }
            else if(curr_line.compare("Pitfall") == 0)
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

    //----------------------------------------------------------
    std::string num_of_players;
    std::string tmp_str;
    int tmp_int;
    int team_size = 0;
    std::cin >> num_of_players;
    tmp_int = stoi(num_of_players);
    tmp_str = std::to_string(tmp_int);
    team_size = tmp_int;
    while ((team_size > 6 || team_size < 2) || tmp_str.compare(num_of_players) != 0)
    {
        printInvalidTeamSize();
        std::cin >> num_of_players;
        tmp_int = stoi(num_of_players);
        tmp_str = std::to_string(tmp_int);
    }
    team_size = tmp_int;
    //----------------------------------------------------------

    std::string player_name, player_job;
    int player_number = 0;
    while (player_number < team_size)
    {
        printInsertPlayerMessage();
        std::cin >> player_name >> player_job;
        if(CheckValidName(player_name) && CheckValidJob(player_job))
        {
            if(player_job.compare("Fighter") == 0)
            {
                std::shared_ptr<Player> player(new Fighter(player_name, player_job));
                m_playing.push_back(player);
            }
            else if(player_job.compare("Rogue") == 0)
            {
                std::shared_ptr<Player> player(new Rogue(player_name, player_job));
                m_playing.push_back(player);
            }
            else if(player_job.compare("Wizard") == 0)
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
    int deque_len = m_playing.size();

    for (int i = 0; i < deque_len; ++i) {
        printTurnStartMessage(m_playing.front()->getName());
        m_cards.front()->applyEncounter(*m_playing.front());

        if(m_playing.front()->isKnockedOut()){
            m_losers.push_back(m_playing.front());
            m_playing.pop_front();
        }
        else if(m_playing.front()->getLevel() == TEN){
            m_winners.push_back(m_playing.front());
            m_playing.pop_front();
        }
        else{
            m_playing.push_back(m_playing.front());
            m_playing.pop_front();
        }
        m_cards.push_back(m_cards.front());
        m_cards.pop_front();
    }
    if(isGameOver())
    {
        printGameEndMessage();
        return;
    }
}


void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int rank = 1;
    int num_of_winners = m_winners.size();
    int num_of_playing = m_playing.size();
    int num_of_losers = m_losers.size();

    for (int i = 0; i < num_of_winners; ++i) {
        printPlayerLeaderBoard(rank,*m_winners[i]);
        rank ++;
    }

    for (int i = 0; i < num_of_playing; ++i) {
        printPlayerLeaderBoard(rank,*m_playing[i]);
        rank ++;
    }

    for (int i = 0; i < num_of_losers; i++) {
        printPlayerLeaderBoard(rank,*m_losers[i]);
        rank ++;
    }
}

bool Mtmchkin::isGameOver() const
{
    bool over = false;
    if(m_playing.size() == 0){
        over = true;
    }
    return  over;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_rounds_number;
}


