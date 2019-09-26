//
// Created by edge on 2019-09-07.
//

#ifndef BANG_ADDFRIENDLAYER_H
#define BANG_ADDFRIENDLAYER_H

#include "ui/CocosGUI.h"
#include "cocos2d.h"

class AddFriendLayer : public cocos2d::Layer {

public:
    AddFriendLayer();

    virtual bool init();

    void menuAddCallback(Ref *pSender);

    void menuCancelCallback(Ref *pSender);

    CREATE_FUNC(AddFriendLayer);

    ~AddFriendLayer();

private:
    cocos2d::TextFieldTTF *userIdTextField;
};


#endif //BANG_ADDFRIENDLAYER_H
