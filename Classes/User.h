#ifndef __USER_H__
#define __USER_H__
#include <string>
class User
{
public:
  User();
  static User * getInstance();
//   CPlayer * GetPlayer();
//   CExclusiveCardInventory * getExclusiveCardInventory() const;
  std::string getName() const;
  int getMoney();
  int getWin();
  int getLose();

//   void setPlayer(CPlayer * player);
  void setName(const std::string & name);
  void setMoney(int money);
  void setWin(int win);
  void setLose(int lose);
  void setID(uint32_t ID);
  uint32_t getID();
  ~User();
private:
  static User * instance;
  std::string name;
  int money;
  int win;
  int lose;
  uint32_t ID;
//   Player * player = nullptr;
//   ExclusiveCardInventory * exclusiveCardInventory = nullptr;
};
#endif // __USER_H__
