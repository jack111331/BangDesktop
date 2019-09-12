//
// Created by edge on 2019-09-10.
//

#ifndef BANG_LARGECARDLAYER_H
#define BANG_LARGECARDLAYER_H


#include "cocos2d.h"
#include <string>

class LargeCardLayer : public cocos2d::Layer
{

public:
    LargeCardLayer();
    virtual bool init();

    CREATE_FUNC(LargeCardLayer);
    ~LargeCardLayer();

};



#endif //BANG_LARGECARDLAYER_H
