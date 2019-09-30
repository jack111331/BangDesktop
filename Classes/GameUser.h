#ifndef __GAMEUSER_H__
#define __GAMEUSER_H__

#include <string>
namespace User {
    class GameUser {
    public:
        GameUser();

        static GameUser *getInstance();

        //   CPlayer * GetPlayer();
        //   CExclusiveCardInventory * getExclusiveCardInventory() const;
        std::string getName() const;

        void setToken(const std::string &token);

        //   void setPlayer(CPlayer * player);
        void setName(const std::string &name);

        int getMoney() const;

        void setMoney(int money);

        int getWin() const;

        void setWin(int win);

        int getLose() const;

        void setLose(int lose);

        uint32_t getId() const;

        void setId(uint32_t id);

        ~GameUser();

    private:
        static GameUser *instance;
        std::string name;
        std::string token;
        int money;
        int win;
        int lose;
        uint32_t id;
        //   GamePlayer * player = nullptr;
        //   ExclusiveCardInventory * exclusiveCardInventory = nullptr;
    };

}

#endif // __GAMEUSER_H__
