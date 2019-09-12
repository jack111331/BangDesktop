//
// Created by edge on 2019-09-10.
//

#include "LargeCardLayer.h"
#include "ResolutionUtil.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

LargeCardLayer::LargeCardLayer()
{

}

bool LargeCardLayer::init()
{
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }
    // 2. cover background image
    auto backgroundImage = Sprite::create("card-orange.png");
    auto backgroundImageFitScale = ResolutionUtil::getCorrespondBackgroundSize(backgroundImage->getContentSize());
    backgroundImage->setScale(backgroundImageFitScale.y, backgroundImageFitScale.y);
    this->setContentSize(backgroundImage->getBoundingBox().size);
    this->addChild(backgroundImage);

    // 3. add card name label
    auto cardNameText = ui::Text::create();
    cardNameText->setText("Roda");
    cardNameText->setFontName("fonts/arial.ttf");
    cardNameText->setFontSize(40);
    cardNameText->setPosition(ResolutionUtil::getCorrespondPosition(0.0f, 0.3f));
    this->addChild(cardNameText);

    // 4. add card image sprite
    auto cardImageSprite = Sprite::create();
    cardImageSprite->setTexture("green-dot.png");
    cardImageSprite->setPosition(ResolutionUtil::getCorrespondPosition(0.0f, 0.1f));
    this->addChild(cardImageSprite);

    // 5. add card description label
    auto cardDescriptionText = ui::Text::create();
    cardDescriptionText->setText("This is description");
    cardDescriptionText->setFontName("fonts/arial.ttf");
    cardDescriptionText->setFontSize(40);
    cardDescriptionText->setPosition(ResolutionUtil::getCorrespondPosition(0.0f, -0.2f));
    this->addChild(cardDescriptionText);

    return true;
}

LargeCardLayer::~LargeCardLayer()
{

}
