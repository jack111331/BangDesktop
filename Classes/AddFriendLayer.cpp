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
    auto backgroundImage = Sprite::create("background-layer.png");
    auto backgroundImageFitScale = ResolutionUtil::getCorrespondBackgroundSize(backgroundImage->getContentSize());
    backgroundImage->setScale(backgroundImageFitScale.x, backgroundImageFitScale.y);
    this->addChild(backgroundImage);

    // 3. add tip text
    auto tipText = ui::Text::create();
    tipText->setText("Please Enter User Id who you want to add as friend.");
    tipText->setFontName("fonts/arial.ttf");
    tipText->setFontSize(40);
    tipText->setPosition(ResolutionUtil::getCorrespondPosition(0.0f, 0.25f));
    this->addChild(tipText);


    // 4. add user id text field
    this->userIdTextField = ui::TextField::create("User Id", "fonts/arial.ttf", 60);
    if (userIdTextField == nullptr) {
        log("Can't initialize user id textfield");
    } else {
        userIdTextField->setPosition(ResolutionUtil::getCorrespondPosition(0.0f, 0.1f));
    }
    this->addChild(this->userIdTextField);

    // 5.a Add add button
    auto addButton = ui::Button::create("login-btn.png", "login-btn-click.png");

    if (addButton == nullptr) {
        log("Can't initialize add button");
    } else {
        //Position
        addButton->setPosition(ResolutionUtil::getCorrespondPosition(-0.25, -0.2f));

        addButton->setTitleFontSize(40);
        addButton->setTitleText("Add");

        addButton->addClickEventListener(CC_CALLBACK_1(AddFriendLayer::menuAddCallback, this));
    }
    this->addChild(addButton);

    // 5.b Add cancel button
    auto cancelButton = ui::Button::create("login-btn.png", "login-btn-click.png");

    if (cancelButton == nullptr) {
        log("Can't initialize cancel button");
    } else {
        //Position
        cancelButton->setPosition(ResolutionUtil::getCorrespondPosition(0.25, -0.2f));

        cancelButton->setTitleFontSize(40);
        cancelButton->setTitleText("Cancel");

        cancelButton->addClickEventListener(CC_CALLBACK_1(AddFriendLayer::menuCancelCallback, this));
    }
    this->addChild(cancelButton);
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
