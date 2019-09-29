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

        int getMoney();

        int getWin();

        int getLose();

        //   void setPlayer(CPlayer * player);
        void setName(const std::string &name);

        void setMoney(int money);

        void setWin(int win);

        void setLose(int lose);

        void setID(uint32_t ID);

        uint32_t getID();

        ~GameUser();

    private:
        static GameUser *instance;
        std::string name;
        int money;
        int win;
        int lose;
        uint32_t id;
        //   GamePlayer * player = nullptr;
        //   ExclusiveCardInventory * exclusiveCardInventory = nullptr;
    };

}

#endif // __GAMEUSER_H__
