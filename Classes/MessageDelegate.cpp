//
// Created by edge on 2019-09-29.
//

#include <vo/ChangeNicknameReponse.h>
#include <vo/RegisterAndLoginResponse.h>
#include "MessageDelegate.h"
#include "nlohmann/json.hpp"

using std::string;
using namespace nlohmann;

MessageDelegate::MessageDelegate() {
    this->userMessageDelegate = new User::MessageDelegate();
    this->playerMessageDelegate = new Player::MessageDelegate();
}

void MessageDelegate::onMessage(std::string message) {
    json json = json::parse(message);
    if (json.find("user") != json.end()) {
        userMessageDelegate->onMessage(*json.find("user"));
    } else if (json.find("player") != json.end()) {
        playerMessageDelegate->onMessage(*json.find("player"));
    } else {
        // TODO add log
    }
}

void MessageDelegate::setGameUser(User::GameUser *gameUser) {
    userMessageDelegate->setUser(gameUser);
}

void MessageDelegate::setGamePlayer(Player::GamePlayer *gamePlayer) {
    playerMessageDelegate->setPlayer(gamePlayer);
}

void User::MessageDelegate::onMessage(json message) {
    if (message.find("registerAndLogin") != message.end()) {
        Response::RegisterAndLoginResponse response = message.find(
                "registerAndLogin")->get<Response::RegisterAndLoginResponse>();
        // refactor to function
        GameUser::getInstance()->setToken(response.token);
    } else if (message.find("changeNickname") != message.end()) {
        Response::ChangeNicknameResponse response = message.find(
                "changeNickname")->get<Response::ChangeNicknameResponse>();
        if(!response.success) {

        }
        // TODO check success, if not, resend it
    }
}

void User::MessageDelegate::setUser(GameUser *gameUser) {
    this->gameUser = gameUser;
}


void Player::MessageDelegate::onMessage(json message) {
}

void Player::MessageDelegate::setPlayer(GamePlayer *gamePlayer) {
    this->gamePlayer = gamePlayer;
}
