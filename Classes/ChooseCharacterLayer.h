//
// Created by edge on 2019-09-09.
//

#ifndef BANG_CHOOSECHARACTERLAYER_H
#define BANG_CHOOSECHARACTERLAYER_H

#include "LargeCardLayer.h"
#include "cocos2d.h"
#include <string>

class ChooseCharacterLayer : public LargeCardLayer {
public:
    ChooseCharacterLayer();

    virtual bool init();

    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);

    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

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
