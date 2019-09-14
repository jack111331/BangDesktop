//
// Created by edge on 2019-09-13.
//

#ifndef BANG_HANDCARDLAYER_H
#define BANG_HANDCARDLAYER_H

#include "cocos2d.h"
#include "SmallCardLayer.h"

class HandCardLayer : public SmallCardLayer {
public:
    HandCardLayer();
    virtual bool init();

    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

    void onPlayCardCallback(Ref *pSender);

    CREATE_FUNC(HandCardLayer);

    ~HandCardLayer();
};


#endif //BANG_HANDCARDLAYER_H
