#include "Player.h"
#include <iostream>
#include "../utilities.h"

Player::Player(const string name, const string job):
            m_name(name), m_job(job), m_level(STARTING_LEVEL), m_force(STARTING_FORCE),
            m_max_hp(DEFAULT_MAX_HP),m_hp(DEFAULT_MAX_HP),m_coins(STARTING_COINS){}
//--------------------------------------------------------------------------
void Player::printInfo() const{
    printPlayerDetails(std::cout, m_name, m_job, m_level, m_force, m_hp, m_coins);
}
//--------------------------------------------------------------------------
void Player::levelUp(){
    if(m_level < MAX_LEVEL){
        m_level++;
    }
}
//--------------------------------------------------------------------------
int Player::getLevel() const{
    return m_level;
}
//--------------------------------------------------------------------------
void Player::buff(const int add_force){
    if (add_force < 0 ){
        return;
    }
    m_force += add_force;
}
//--------------------------------------------------------------------------
void Player::heal(const int add_hp){
    if(add_hp < 0){
        return;
    }

    if((m_hp + add_hp) > (m_max_hp)){
        m_hp = m_max_hp;
    }
    else{
        m_hp += add_hp;
    }
}
//--------------------------------------------------------------------------
void Player::damage(const int remove_hp){
    if(remove_hp < 0){
        return;
    }

    if(m_hp - remove_hp < 0){
        m_hp = 0;
    }
    else{
        m_hp -= remove_hp;
    }
}
//--------------------------------------------------------------------------
bool Player::isKnockedOut() const{
    return(!m_hp);
}
//--------------------------------------------------------------------------
void Player::addCoins(const int coins_add){
    if (coins_add < 0 ){
        return;
    }
    m_coins += coins_add;
}
//--------------------------------------------------------------------------
bool Player::pay(int coins_remove){
    if(coins_remove > m_coins){
        return false;
    }
    else{
        m_coins -= coins_remove;
        return true;
    }
}
//--------------------------------------------------------------------------
int Player::getAttackStrength() const{
    return (m_level + m_force);
}
//--------------------------------------------------------------------------
const string& Player::getName() const{
   return m_name;
}
//--------------------------------------------------------------------------
const string& Player::getJob() const {
    return m_job;
}
//--------------------------------------------------------------------------
int Player::getForce() const{
    return m_force;
}
//--------------------------------------------------------------------------
void Player::setForce(int force){
    if(force >=0){
        m_force = force;
    }
    else{
        m_force = 0;
    }
}
//--------------------------------------------------------------------------
int Player::getHp() const{
    return m_hp;
}