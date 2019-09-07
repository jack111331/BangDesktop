//
// Created by edge on 2019-09-07.
//

#ifndef BANG_RESOLUTIONUTIL_H
#define BANG_RESOLUTIONUTIL_H

#include "cocos2d.h"
USING_NS_CC;
class ResolutionUtil
{
public:
    static Vec2 getCorrespondPosition(float x, float y)
    {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        return Vec2(x * visibleSize.width, y * visibleSize.height);
    }
    static Size getCorrespondSize(float x, float y)
    {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        return Size(x * visibleSize.width, y * visibleSize.height);
    }
};


#endif //BANG_RESOLUTIONUTIL_H
