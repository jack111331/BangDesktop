//
// Created by edge on 2019-09-13.
//

#include "HandCard.h"
#include "ResolutionUtil.h"

USING_NS_CC;

HandCard::HandCard() {
    // 2. cover background image
    auto backgroundImage = Sprite::create("card-orange.png");
    if (backgroundImage) {
        backgroundImage->setAnchorPoint(Vec2(0.0f, 0.0f));
        backgroundImage->setContentSize(ResolutionUtil::getCorrespondSize(0.24f, 0.4f));
        this->addChild(backgroundImage);
    } else {
        log("[SmallCardLayer] Can't initialize background image.");
    }

    // 3. add card name text
    this->cardNameText = ui::Text::create();
    if (cardNameText) {
        cardNameText->setString(cardName);
        cardNameText->setFontName("fonts/arial.ttf");
        cardNameText->setFontSize(40);
        //FIXME should use relative position according to background image
        cardNameText->setPosition(ResolutionUtil::getCorrespondPosition(0.12f, 0.33f));
        this->addChild(cardNameText);
    } else {
        log("[SmallCardLayer] Can't initialize card name text.");
    }

    // 4. add card image sprite
    this->cardImage = ui::ImageView::create();
    if (cardImage) {
        cardImage->loadTexture(cardImagePath);
        //FIXME should use relative position according to background image
        cardImage->setPosition(ResolutionUtil::getCorrespondPosition(0.12f, 0.15f));
        this->addChild(cardImage);
    } else {
        log("[SmallCardLayer] Can't initialize card image.");
    }

    // 5. add button
    auto fakeButton = ui::Button::create("", "");
    fakeButton->addClickEventListener(CC_CALLBACK_1(HandCard::cardCallback, this));
    fakeButton->setAnchorPoint(Vec2(0.0f, 0.0f));
    fakeButton->ignoreContentAdaptWithSize(false);
    fakeButton->setContentSize(backgroundImage->getBoundingBox().size);
    this->addChild(fakeButton);

    this->ignoreContentAdaptWithSize(false);
    this->setContentSize(backgroundImage->getBoundingBox().size);

}

void HandCard::cardCallback(Ref *pSender) {
    // inform parent scene to play card animation
    log("touched layer");
}

void HandCard::setCardName(const std::string &cardName) {
    this->cardName = cardName;
    cardNameText->setString(cardName);
}

void HandCard::setCardImagePath(const std::string &cardImagePath) {
    this->cardImagePath = cardImagePath;
    cardImage->loadTexture(cardImagePath);
}

HandCard::~HandCard() {

}