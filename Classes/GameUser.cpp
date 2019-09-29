#include "GameUser.h"

User::GameUser *User::GameUser::instance = nullptr;
using namespace User;
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

void GameUser::setName(const std::string &name) {
    this->name = name;
}