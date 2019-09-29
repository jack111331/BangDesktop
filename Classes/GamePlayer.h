//
// Created by edge on 2019-09-13.
//

#ifndef BANG_GAMEPLAYER_H
#define BANG_GAMEPLAYER_H

#include "GameUser.h"
#include <string>


enum class Team {
    Sergeant = 0, //警長
    ChiefSergeant = 1, //副警長
    BadAss = 2, //歹徒
    Traitor = 3 //叛徒
};
namespace Player {
    class GamePlayer {
    public:
        // getter and setter
        User::GameUser *getUser() const;

        void setUser(User::GameUser *user);

        Team getIdentity() const;

        void setIdentity(Team identity);

        const std::string &getCharacterName() const;

        void setCharacterName(const std::string &characterName);

        int getHp() const;

        void setHp(int hp);

        int getMaxHp() const;

        void setMaxHp(int maxHp);

        int getPosition() const;

        void setPosition(int position);

        bool isDead() const;

        void setDead(bool dead);

        bool isHasMultiAttack() const;

        void setHasMultiAttack(bool hasMultiAttack);

        int getAttackRange() const;

        void setAttackRange(int attackRange);

        int getAddRange() const;

        void setAddRange(int addRange);

        int getMinusRange() const;

        void setMinusRange(int minusRange);

    private:
        User::GameUser *user;
        Team identity;
        std::string characterName;
        int hp;
        int maxHP;
        int position;
        bool dead = false; //是否處於死亡狀態
        bool hasMultiAttack = false;
        int attackRange = 1;
        int addRange = 0; //別人看自己的距離
        int minusRange = 0; //自己看別人的距離
    };

}


#endif //BANG_GAMEPLAYER_H
