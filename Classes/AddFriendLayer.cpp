//
// Created by edge on 2019-09-07.
//

#include "AddFriendLayer.h"
#include "ResolutionUtil.h"

USING_NS_CC;

AddFriendLayer::AddFriendLayer()
{

}

bool AddFriendLayer::init()
{
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    // 2. cover background image
    auto backgroundImage = Sprite::create("background-layer.png");
    backgroundImage->setScale(0.1);
    this->addChild(backgroundImage);

    // 3. add user id text field
    this->userIdTextField = ui::TextField::create("User Id", "fonts/arial.ttf", 40);
    if (userIdTextField == nullptr)
    {
        log("Can't initialize user id textfield");
    }
    else
    {
        userIdTextField->setPosition(ResolutionUtil::getCorrespondPosition(0.0, 0.1f));
    }
    this->addChild(this->userIdTextField);

    // 4.a Add add button
    auto addButton = ui::Button::create("login-btn.png", "login-btn-click.png");

    if (addButton == nullptr)
    {
        log("Can't initialize login button");
    }
    else
    {
        //Position
        addButton->setPosition(ResolutionUtil::getCorrespondPosition(-0.1, -0.1f));

        addButton->setTitleFontSize(40);
        addButton->setTitleText("Add");

        addButton->addClickEventListener(CC_CALLBACK_1(AddFriendLayer::menuAddCallback, this));
    }
    this->addChild(addButton);

    // 4.b Add cancel button
    auto cancelButton = ui::Button::create("login-btn.png", "login-btn-click.png");

    if (cancelButton == nullptr)
    {
        log("Can't initialize cancel button");
    }
    else
    {
        //Position
        cancelButton->setPosition(ResolutionUtil::getCorrespondPosition(0.1, -0.1f));

        cancelButton->setTitleFontSize(40);
        cancelButton->setTitleText("Cancel");

        cancelButton->addClickEventListener(CC_CALLBACK_1(AddFriendLayer::menuCancelCallback, this));
    }
    this->addChild(cancelButton);
    return true;
}

void AddFriendLayer::menuAddCallback(Ref *pSender)
{
    log("User id=%s", this->userIdTextField->getString().c_str());
}

void AddFriendLayer::menuCancelCallback(Ref *pSender)
{
    this->removeFromParent();
}

AddFriendLayer::~AddFriendLayer()
{

}
