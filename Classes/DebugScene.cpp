//
// Created by edge on 2019-09-21.
//

#include "ui/CocosGUI.h"
#include "DebugScene.h"
#include "HandCard.h"
#include "ResolutionUtil.h"

USING_NS_CC;

Scene *DebugScene::createScene() {
    return DebugScene::create();

}

// on "init" you need to initialize your instance
bool DebugScene::init() {
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }
    auto layout = ui::Layout::create();
    layout->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
    layout->setBackGroundColor(Color3B::RED);
    layout->setLayoutType(ui::Layout::Type::HORIZONTAL);
    layout->setContentSize(ResolutionUtil::getCorrespondSize(0.8f, 0.3f));
    layout->setPosition(ResolutionUtil::getCorrespondPosition(0.5f, 0.5f));
    layout->setAnchorPoint(Vec2(0.5f,0.5f));
    auto handCard = HandCard::create();
    layout->addChild(handCard);
    auto handCard1 = HandCard::create();
    layout->addChild(handCard1);
    auto loginButton = ui::Button::create("login-btn.png", "login-btn-click.png");
    layout->addChild(loginButton);
    //    auto loginButton1 = ui::Button::create("login-btn.png", "login-btn-click.png");
    //    layout->addChild(loginButton1);
    this->addChild(layout);

    return true;
}