//
// Created by edge on 2019-09-10.
//

#ifndef BANG_SMALLCARDLAYER_H
#define BANG_SMALLCARDLAYER_H

#include "cocos2d.h"
#include <string>

class SmallCardLayer : public cocos2d::Layer
{

public:
    SmallCardLayer();
    virtual bool init();

    CREATE_FUNC(SmallCardLayer);
    ~SmallCardLayer();

};


#endif //BANG_SMALLCARDLAYER_H
