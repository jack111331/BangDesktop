//
// Created by edge on 2019-09-09.
//

#include "ChooseCharacterLayer.h"
#include "ResolutionUtil.h"

USING_NS_CC;

ChooseCharacterLayer::ChooseCharacterLayer()
{

}

bool ChooseCharacterLayer::init()
{
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    // 2.a Add left button
    auto leftButton = ui::Button::create("choose-bg-orange.png", "choose-bg-orange-click.png");

    if (leftButton == nullptr)
    {
        log("Can't initialize left button");
    }
    else
    {
        //Position
        leftButton->setPosition(ResolutionUtil::getCorrespondPosition(-0.1, -0.1f));

        leftButton->setTitleFontSize(40);
        leftButton->setTitleText("Jotaro");

        leftButton->addClickEventListener(CC_CALLBACK_1(ChooseCharacterLayer::menuChooseCallback, this, "Jotaro"));
    }
    this->addChild(leftButton);

    // 2.b Add right button
    auto rightButton = ui::Button::create("choose-bg-purple.png", "choose-bg-purple-click.png");

    if (rightButton == nullptr)
    {
        log("Can't initialize right button");
    }
    else
    {
        rightButton->setPosition(ResolutionUtil::getCorrespondPosition(0.3f, 0.0f));
        rightButton->setScale(0.25f, 0.25f);
        rightButton->setTitleFontSize(100);
        rightButton->setTitleText("Dio");

        rightButton->addClickEventListener(CC_CALLBACK_1(ChooseCharacterLayer::menuChooseCallback, this, "Dio"));
    }
    this->addChild(rightButton);
    return true;
}

void ChooseCharacterLayer::menuChooseCallback(Ref *pSender, std::string characterName)
{
    log("characterName=%s", characterName.c_str());
}


ChooseCharacterLayer::~ChooseCharacterLayer()
{

}
