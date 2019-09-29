//
// Created by edge on 2019-09-13.
//

#include "GamePlayer.h"

using std::string;
using namespace User;
using namespace Player;

GameUser *GamePlayer::getUser() const {
    return user;
}

void GamePlayer::setUser(GameUser *gameUser) {
    this->user = gameUser;
}

Team GamePlayer::getIdentity() const {
    return identity;
}

void GamePlayer::setIdentity(Team identity) {
    this->identity = identity;
}

const string &GamePlayer::getCharacterName() const {
    return characterName;
}

void GamePlayer::setCharacterName(const string &characterName) {
    this->characterName = characterName;
}

int GamePlayer::getHp() const {
    return hp;
}

void GamePlayer::setHp(int hp) {
    this->hp = hp;
}

int GamePlayer::getMaxHp() const {
    return maxHP;
}

void GamePlayer::setMaxHp(int maxHp) {
    this->maxHP = maxHp;
}

int GamePlayer::getPosition() const {
    return position;
}

void GamePlayer::setPosition(int position) {
    this->position = position;
}

bool GamePlayer::isDead() const {
    return dead;
}

void GamePlayer::setDead(bool dead) {
    this->dead = dead;
}

bool GamePlayer::isHasMultiAttack() const {
    return hasMultiAttack;
}

void GamePlayer::setHasMultiAttack(bool hasMultiAttack) {
    this->hasMultiAttack = hasMultiAttack;
}

int GamePlayer::getAttackRange() const {
    return attackRange;
}

void GamePlayer::setAttackRange(int attackRange) {
    this->attackRange = attackRange;
}

int GamePlayer::getAddRange() const {
    return addRange;
}

void GamePlayer::setAddRange(int addRange) {
    this->addRange = addRange;
}

int GamePlayer::getMinusRange() const {
    return minusRange;
}

void GamePlayer::setMinusRange(int minusRange) {
    this->minusRange = minusRange;
}


