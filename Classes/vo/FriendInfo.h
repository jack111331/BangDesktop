//
// Created by edge on 2019-09-15.
//

#ifndef BANG_FRIENDINFO_H
#define BANG_FRIENDINFO_H

#include <string>

class FriendInfo {
public:
    FriendInfo(int state, const std::string &username) : state(state), username(username) { }
    const std::string &getUsername() const {
        return username;
    }

    void setUsername(const std::string &username) {
        this->username = username;
    }

    int getState() const {
        return state;
    }

    void setState(int state) {
        this->state = state;
    }

private:
    int state;

    std::string username;
};

#endif //BANG_FRIENDINFO_H
