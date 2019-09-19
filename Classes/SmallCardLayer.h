//
// Created by edge on 2019-09-10.
//

#ifndef BANG_SMALLCARDLAYER_H
#define BANG_SMALLCARDLAYER_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <string>

class SmallCardLayer : public cocos2d::Layer {

public:
    SmallCardLayer();

    virtual bool init();

    CREATE_FUNC(SmallCardLayer);

    void setCardName(const std::string &cardName);

    void setCardImagePath(const std::string &cardImagePath);

    ~SmallCardLayer();

private:
    std::string cardName = "Roda";
    std::string cardImagePath = "green-dot.png";
    cocos2d::ui::Text *cardNameText;
    cocos2d::Sprite *cardImageSprite;
};


#endif //BANG_SMALLCARDLAYER_H
