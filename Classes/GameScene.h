//
// Created by edge on 2019-09-09.
//

#ifndef BANG_GAMESCENE_H
#define BANG_GAMESCENE_H


#include "ui/CocosGUI.h"
#include "cocos2d.h"

class Player;

class ChooseCharacterLayer;

class GameScene : public cocos2d::Scene {
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    void chooseCharacterUpdate(float delay);
    void gameLoopUpdate(float delay);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
    Player *player;
    ChooseCharacterLayer *leftCharacterLayer;
    ChooseCharacterLayer *rightCharacterLayer;
    cocos2d::ui::Layout * handCardLayout;
};

#endif //BANG_GAMESCENE_H
