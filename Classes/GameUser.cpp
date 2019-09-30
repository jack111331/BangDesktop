#include "GameUser.h"
using namespace User;
GameUser *GameUser::instance = nullptr;

GameUser *GameUser::getInstance() {
    if (instance == nullptr) {
        instance = new GameUser();
    }
    return instance;
}

GameUser::GameUser() : name(""), money(0), win(0), lose(0) {

}

std::string GameUser::getName() const {
    return name;
}
void GameUser::setToken(const std::string &token) {
    GameUser::token = token;
}

void GameUser::setName(const std::string &name) {
    this->name = name;
}

int GameUser::getMoney() const {
    return money;
}

void GameUser::setMoney(int money) {
    GameUser::money = money;
}

int GameUser::getWin() const {
    return win;
}

void GameUser::setWin(int win) {
    GameUser::win = win;
}

int GameUser::getLose() const {
    return lose;
}

void GameUser::setLose(int lose) {
    GameUser::lose = lose;
}

uint32_t GameUser::getId() const {
    return id;
}

void GameUser::setId(uint32_t id) {
    GameUser::id = id;
}

