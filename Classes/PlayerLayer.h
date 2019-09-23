//
// Created by edge on 2019-09-23.
//

#ifndef BANG_PLAYERLAYER_H
#define BANG_PLAYERLAYER_H


#include "ui/CocosGUI.h"
#include "cocos2d.h"

class PlayerLayer : public cocos2d::Layer {
public:
    PlayerLayer();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(PlayerLayer);

    void setHp(int hp);
    void updateHealthIcon();

    ~PlayerLayer();

private:
    cocos2d::ui::ImageView *characterImage;
    cocos2d::ui::Layout *healthLayout;
    int hp = 3;
};


#endif //BANG_PLAYERLAYER_H
