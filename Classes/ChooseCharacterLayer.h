//
// Created by edge on 2019-09-09.
//

#ifndef BANG_CHOOSECHARACTERLAYER_H
#define BANG_CHOOSECHARACTERLAYER_H

#include "LargeCardLayer.h"
#include "cocos2d.h"
#include "Player.h"
#include <string>

class ChooseCharacterLayer : public LargeCardLayer
{

public:
    ChooseCharacterLayer();
    virtual bool init();

    bool onCharacterTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    bool onCharacterTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    bool onCharacterTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

    void onClickCallback(Ref *pSender);

    CREATE_FUNC(ChooseCharacterLayer);

    const std::string &getCharacterName() const;

    void setCharacterName(const std::string &characterName);

    bool isChosen() const;

    ~ChooseCharacterLayer();
private:
    std::string characterName;
    bool chosen = false;

};


#endif //BANG_CHOOSECHARACTERLAYER_H
