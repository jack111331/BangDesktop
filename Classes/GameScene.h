//
// Created by edge on 2019-09-09.
//

#ifndef BANG_GAMESCENE_H
#define BANG_GAMESCENE_H


#include "ui/CocosGUI.h"
#include "cocos2d.h"
class Player;
class ChooseCharacterLayer;

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuLoginCallback(cocos2d::Ref* pSender);

    void chooseCharacterUpdate(float delay);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
    Player *player;
    ChooseCharacterLayer * leftCharacterLayer;
    ChooseCharacterLayer * rightCharacterLayer;
};

#endif //BANG_GAMESCENE_H
