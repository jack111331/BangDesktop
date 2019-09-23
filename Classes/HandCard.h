//
// Created by edge on 2019-09-13.
//

#ifndef BANG_HANDCARD_H
#define BANG_HANDCARD_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class HandCard : public cocos2d::ui::Widget{
public:
    HandCard();

    void cardCallback(Ref *pSender);

    void setCardName(const std::string &cardName);

    void setCardImagePath(const std::string &cardImagePath);

    CREATE_FUNC(HandCard);

    ~HandCard();
private:
    std::string cardName = "Roda";
    std::string cardImagePath = "green-dot.png";
    cocos2d::ui::Text *cardNameText;
    cocos2d::ui::ImageView *cardImage;
};


#endif //BANG_HANDCARD_H
