//
// Created by edge on 2019-09-10.
//

#include "SmallCardLayer.h"
#include "ResolutionUtil.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

SmallCardLayer::SmallCardLayer() {

}

bool SmallCardLayer::init() {
    // 1. super init first
    if (!Layer::init()) {
        return false;
    }
    // 2. cover background image
    auto backgroundImage = Sprite::create("card-orange.png");
    if (backgroundImage) {
        auto backgroundImageFitScale = ResolutionUtil::getCorrespondBackgroundSize(backgroundImage->getContentSize());
        backgroundImage->setScale(backgroundImageFitScale.y, backgroundImageFitScale.y);
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
        cardNameText->setPosition(ResolutionUtil::getCorrespondPosition(0.0f, 0.3f));
        this->addChild(cardNameText);
    } else {
        log("[SmallCardLayer] Can't initialize card name text.");
    }

    // 4. add card image sprite
    this->cardImageSprite = Sprite::create();
    if (cardImageSprite) {
        cardImageSprite->setTexture(cardImagePath);
        cardImageSprite->setPosition(ResolutionUtil::getCorrespondPosition(0.0f, 0.1f));
        this->addChild(cardImageSprite);
    } else {
        log("[SmallCardLayer] Can't initialize card image.");
    }

    return true;
}

void SmallCardLayer::setCardName(const std::string &cardName) {
    this->cardName = cardName;
    cardNameText->setString(cardName);
}

void SmallCardLayer::setCardImagePath(const std::string &cardImagePath) {
    this->cardImagePath = cardImagePath;
    cardImageSprite->setTexture(cardImagePath);
}

SmallCardLayer::~SmallCardLayer() {

}

