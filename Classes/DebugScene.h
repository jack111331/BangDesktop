//
// Created by edge on 2019-09-21.
//

#ifndef BANG_DEBUGSCENE_H
#define BANG_DEBUGSCENE_H

#include "cocos2d.h"

class DebugScene : public cocos2d::Scene {
public:
    static cocos2d::Scene *createScene();

    virtual bool init();


    // implement the "static create()" method manually
    CREATE_FUNC(DebugScene);
};

#endif //BANG_DEBUGSCENE_H
