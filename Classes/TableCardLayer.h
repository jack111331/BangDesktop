//
// Created by edge on 2019-09-14.
//

#ifndef BANG_TABLECARDLAYER_H
#define BANG_TABLECARDLAYER_H


#include "cocos2d.h"
#include "SmallCardLayer.h"

class TableCardLayer : public SmallCardLayer {
public:
    TableCardLayer();

    virtual bool init();

    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);

    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);

    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);


    CREATE_FUNC(TableCardLayer);

    ~TableCardLayer();
};


#endif //BANG_TABLECARDLAYER_H
