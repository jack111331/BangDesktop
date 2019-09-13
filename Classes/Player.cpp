//
// Created by edge on 2019-09-13.
//

#include "Player.h"
using std::string;
User *Player::getUser() const
{
    return user;
}

void Player::setUser(User *user)
{
    this->user = user;
}

Team Player::getIdentity() const
{
    return identity;
}

void Player::setIdentity(Team identity)
{
    this->identity = identity;
}

const string &Player::getCharacterName() const
{
    return characterName;
}

void Player::setCharacterName(const string &characterName)
{
    this->characterName = characterName;
}

int Player::getHp() const
{
    return hP;
}

void Player::setHp(int hP)
{
    this->hP = hP;
}

int Player::getMaxHp() const
{
    return maxHP;
}

void Player::setMaxHp(int maxHp)
{
    this->maxHP = maxHp;
}

int Player::getPosition() const
{
    return position;
}

void Player::setPosition(int position)
{
    this->position = position;
}

bool Player::isDead() const
{
    return dead;
}

void Player::setDead(bool dead)
{
    this->dead = dead;
}

bool Player::isHasMultiAttack() const
{
    return hasMultiAttack;
}

void Player::setHasMultiAttack(bool hasMultiAttack)
{
    this->hasMultiAttack = hasMultiAttack;
}

int Player::getAttackRange() const
{
    return attackRange;
}

void Player::setAttackRange(int attackRange)
{
    this->attackRange = attackRange;
}

int Player::getAddRange() const
{
    return addRange;
}

void Player::setAddRange(int addRange)
{
    this->addRange = addRange;
}

int Player::getMinusRange() const
{
    return minusRange;
}

void Player::setMinusRange(int minusRange)
{
    this->minusRange = minusRange;
}


