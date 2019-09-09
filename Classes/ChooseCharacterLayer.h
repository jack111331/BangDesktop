//
// Created by edge on 2019-09-09.
//

#ifndef BANG_CHOOSECHARACTERLAYER_H
#define BANG_CHOOSECHARACTERLAYER_H

#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include <string>

class ChooseCharacterLayer : public cocos2d::Layer
{

public:
    ChooseCharacterLayer();
    virtual bool init();

    void menuChooseCallback(Ref* pSender, std::string characterName);

    CREATE_FUNC(ChooseCharacterLayer);
    ~ChooseCharacterLayer();

};


#endif //BANG_CHOOSECHARACTERLAYER_H
