//
// Created by edge on 2019-09-07.
//

#include "AddFriendLayer.h"
#include "ResolutionUtil.h"

USING_NS_CC;

AddFriendLayer::AddFriendLayer() {

}

bool AddFriendLayer::init() {
    // 1. super init first
    if (!Layer::init()) {
        return false;
    }

    // 2. cover background image
    auto backgroundImage = ui::ImageView::create("notification-bg.png");
    if (backgroundImage) {
        backgroundImage->ignoreContentAdaptWithSize(false);
        backgroundImage->setContentSize(ResolutionUtil::getCorrespondSize(0.5f, 0.5f));
        backgroundImage->setPosition(ResolutionUtil::getCorrespondPosition(0.5f, 0.5f));
        this->addChild(backgroundImage);
    } else {
        log("[AddFriendLayer] Can't Initialize background image.");
    }

    // 3. add tip text
    auto tipText = ui::Text::create();
    if (tipText) {
        tipText->setPosition(ResolutionUtil::getCorrespondPosition(0.5f, 0.7f));
        tipText->setFontName("fonts/arial.ttf");
        tipText->setFontSize(20);
        tipText->setTextColor(Color4B::BLACK);
        tipText->setString("Please Enter User ID who you want to add as friend.");
        this->addChild(tipText);
    } else {
        log("[AddFriendLayer] Can't Initialize tip text");
    }

    // 4.a add user id text field background
    auto userIdTextFieldBackground = ui::ImageView::create("username-input.png");
    if (userIdTextFieldBackground) {
        userIdTextFieldBackground->ignoreContentAdaptWithSize(false);
        userIdTextFieldBackground->setContentSize(ResolutionUtil::getCorrespondSize(0.30f, 0.05f));
        userIdTextFieldBackground->setPosition(ResolutionUtil::getCorrespondPosition(0.5f, 0.5f));
        this->addChild(userIdTextFieldBackground);
    } else {
        log("[LoginScene] Can't initialize username textfield background");
    }

    // 4.b add user id text field
    this->userIdTextField = TextFieldTTF::textFieldWithPlaceHolder("User ID", "fonts/arial.ttf", 40);
    if (userIdTextField) {
        userIdTextField->setPosition(ResolutionUtil::getCorrespondPosition(0.5f, 0.5f));
        auto listener = EventListenerTouchOneByOne::create();
        listener->onTouchBegan = [this](Touch *touch, Event *event) {
            if (this->userIdTextField->getBoundingBox().containsPoint(touch->getLocation())) {
                this->userIdTextField->attachWithIME();
            } else {
                this->userIdTextField->detachWithIME();
            }
            return false;
        };
        Director::getInstance()->getEventDispatcher()->
                addEventListenerWithSceneGraphPriority(listener, userIdTextField);
        userIdTextField->setCursorEnabled(true);
        userIdTextField->setTextColor(Color4B::BLACK);
        this->addChild(userIdTextField);
    } else {
        log("[AddFriendLayer] Can't initialize user id textfield");
    }

    // 5.a Add add button
    auto addButton = ui::Button::create("login-btn.png", "login-btn-click.png");
    if (addButton) {
        addButton->setPosition(ResolutionUtil::getCorrespondPosition(0.25f, 0.25f));
        addButton->setTitleFontSize(40);
        addButton->setTitleText("Add");
        addButton->addClickEventListener(CC_CALLBACK_1(AddFriendLayer::menuAddCallback, this));
        this->addChild(addButton);
    } else {
        log("[AddFriendLayer] Can't initialize add button");
    }

    // 5.b Add cancel button
    auto cancelButton = ui::Button::create("login-btn.png", "login-btn-click.png");

    if (cancelButton) {
        cancelButton->setPosition(ResolutionUtil::getCorrespondPosition(0.75, 0.25f));
        cancelButton->setTitleFontSize(40);
        cancelButton->setTitleText("Cancel");
        cancelButton->addClickEventListener(CC_CALLBACK_1(AddFriendLayer::menuCancelCallback, this));
        this->addChild(cancelButton);
    } else {
        log("[AddFriendLayer] Can't initialize cancel button");
    }
    return true;
}

void AddFriendLayer::menuAddCallback(Ref *pSender) {
    log("User id=%s", this->userIdTextField->getString().c_str());
}

void AddFriendLayer::menuCancelCallback(Ref *pSender) {
    this->removeFromParent();
}

AddFriendLayer::~AddFriendLayer() {

}
