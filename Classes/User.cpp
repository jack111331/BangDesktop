#include "User.h"

User *User::instance = nullptr;

User *User::getInstance() {
    if (instance == nullptr) {
        instance = new User();
    }
    return instance;
}

User::User() : name(""), money(0), win(0), lose(0) {

}

std::string User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    this->name = name;
}