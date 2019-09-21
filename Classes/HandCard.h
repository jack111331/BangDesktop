//
// Created by edge on 2019-09-13.
//

#ifndef BANG_HANDCARD_H
#define BANG_HANDCARD_H

#include "cocos2d.h"
#include "SmallCardLayer.h"

class HandCard : public cocos2d::ui::Widget{
public:
    HandCard();

    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);

    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);

    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

    void onPlayCardCallback(Ref *pSender);

    CREATE_FUNC(HandCard);

    ~HandCard();
private:
    SmallCardLayer * smallCardLayer;

};


#endif //BANG_HANDCARD_H
