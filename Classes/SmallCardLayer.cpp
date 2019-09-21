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
    auto backgroundImage = ui::ImageView::create("card-orange.png");
    if (backgroundImage) {
        backgroundImage->ignoreContentAdaptWithSize(false);
        backgroundImage->setContentSize(ResolutionUtil::getCorrespondSize(0.24f, 0.4f));
        backgroundImage->ignoreAnchorPointForPosition(true);
        this->setContentSize(backgroundImage->getBoundingBox().size);
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

    return true;
}

void SmallCardLayer::setCardName(const std::string &cardName) {
    this->cardName = cardName;
    cardNameText->setString(cardName);
}

void SmallCardLayer::setCardImagePath(const std::string &cardImagePath) {
    this->cardImagePath = cardImagePath;
    cardImage->loadTexture(cardImagePath);
}

SmallCardLayer::~SmallCardLayer() {

}

