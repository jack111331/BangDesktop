//
// Created by edge on 2019-09-29.
//

#ifndef BANG_MESSAGEDELEGATE_H
#define BANG_MESSAGEDELEGATE_H

#include "GameUser.h"
#include "GamePlayer.h"
#include "nlohmann/json.hpp"
#include <string>

namespace User {
    class MessageDelegate {
    public:
        void onMessage(nlohmann::json message);
        void setUser(GameUser *gameUser);
    private:
        GameUser *gameUser;
    };
}
namespace Player {
    class MessageDelegate {
    public:
        void onMessage(nlohmann::json message);
        void setPlayer(Player::GamePlayer *gamePlayer);
    private:
        GamePlayer *gamePlayer;
    };
}

class MessageDelegate {
public:
    MessageDelegate();
    void onMessage(std::string message);

    void setGameUser(User::GameUser *gameUser);

    void setGamePlayer(Player::GamePlayer *gamePlayer);

private:
    User::MessageDelegate *userMessageDelegate = nullptr;
    Player::MessageDelegate *playerMessageDelegate = nullptr;
};

#endif //BANG_MESSAGEDELEGATE_H
