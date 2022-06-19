#ifndef EX4_Player_H
#define EX4_Player_H


#include <string>

using namespace std;

#define STARTING_FORCE 5
#define MAX_LEVEL 10
#define DEFAULT_MAX_HP 100
#define STARTING_LEVEL 1
#define STARTING_COINS 0

class Player {
public:
    /*
     * C'tor of player class
     *
     * @param m_name - The name of the player.
     * @param m_job - The job of the player.
     * @return
     *      A new instance of Player.
    */
    explicit Player(const string name, const string job);

    /*
     * Prints the player info:
     *
     * @return
     *      void
    */
    void printInfo() const;

    
    /*
     * Levels up the player 1 level:
     *
     * @return
     *      void
    */
    void levelUp();
    
    
    /*
     * Gets the player's level:
     *
     * @return
     *      current level of the player
    */
    int getLevel() const;


    
    /*
     * Adds to the force the given parameter:
     * 
     * @param add_force -the force added to the player
     * @return
     *      void
    */
    void buff(const int add_force);

    
    /*
     * Adds hp by parameter until reaches max_hp:
     *
     * @param add_hp -the hp added to the player
     * @return
     *      void
    */
    virtual void heal(const int add_hp);


    
    /*
     * Lowers the hp by parameter until reaches 0:
     *
     * @param remove_hp -the hp removed to the player
     * @return
     *      void
    */
    void damage(const int remove_hp);


    
    /*
     * Checks if hp = 0:
     *
     * @return
     *      false if hp != 0 and true if hp = 0
    */
    bool isKnockedOut() const;


    /*
     * Adds coins to the player:
     *
     * @param coins_add -the coins added to the player
     * @return
     *      void
    */
    virtual void addCoins(const int coins_add);


    
    /*
     * Remove coins from the player:
     *
     * @param coins_remove -the coins removed to the player
     * @return
     *      true if the pay was successful and false otherwise
    */
    bool pay(int coins_remove);


    /*
     * Returns the attack strength:
     *
     * @return
     *      current level + current force
    */
    virtual int getAttackStrength() const;

    /*
     * Getters:
     *      Player name
     *      Player job
     *      Player force
     *      Player Hp
     * Setters:
     *      Player force
     */
    const string& getName() const;
    const string& getJob() const;

    int getHp() const;
    int getForce() const;
    void setForce(int force);
    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = delete;


protected:
    const string m_name;
    const string m_job;
    int m_level;
    int m_force;
    int m_max_hp;
    int m_hp;
    int m_coins;
};


#endif //EX4_Player_H