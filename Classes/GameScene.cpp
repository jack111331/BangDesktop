//
// Created by edge on 2019-09-09.
//

#include "GameScene.h"
#include "ChooseCharacterLayer.h"

#include "ui/CocosGUI.h"
#include "ResolutionUtil.h"
#include "HandCard.h"

#include "Player.h"

USING_NS_CC;


Scene *GameScene::createScene() {
    return GameScene::create();
}

// on "init" you need to initialize your instance
bool GameScene::init() {
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }
    this->player = new Player();
    this->handCardLayout = ui::Layout::create();
    handCardLayout->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
    handCardLayout->setBackGroundColor(Color3B::RED);
    handCardLayout->setLayoutType(ui::Layout::Type::HORIZONTAL);
    handCardLayout->setContentSize(ResolutionUtil::getCorrespondSize(0.5f, 0.5f));
    handCardLayout->setPosition(ResolutionUtil::getCorrespondPosition(0.5f, 0.5f));

    // 2. cover background image
    auto backgroundImage = ui::ImageView::create("background.png");
    if (backgroundImage) {
        this->addChild(backgroundImage);

    } else {
        log("[GameScene] Can't initialize background image.");
    }


    // 3.a add left choose character layer
    this->leftCharacterLayer = ChooseCharacterLayer::create();
    leftCharacterLayer->setPosition(ResolutionUtil::getCorrespondPosition(0.25f, 0.5f));
    leftCharacterLayer->setScale(0.6f);
    this->addChild(leftCharacterLayer);

    // 3.b add right choose character layer
    this->rightCharacterLayer = ChooseCharacterLayer::create();
    rightCharacterLayer->setPosition(ResolutionUtil::getCorrespondPosition(0.75f, 0.5f));
    rightCharacterLayer->setScale(0.6f);
    this->addChild(rightCharacterLayer);

    this->schedule(schedule_selector(GameScene::chooseCharacterUpdate), 0.1f);

    this->addChild(handCardLayout);



    Director::getInstance()->setNotificationNode(nullptr);

    return true;
}

void GameScene::chooseCharacterUpdate(float delay) {
    if (leftCharacterLayer->isChosen() || rightCharacterLayer->isChosen()) {
        if (leftCharacterLayer->isChosen()) {
            player->setCharacterName(leftCharacterLayer->getCharacterName());
        } else {
            player->setCharacterName(rightCharacterLayer->getCharacterName());
        }
        log("chooseLeft=%d, chooseRight=%d", (int) leftCharacterLayer->isChosen(),
            (int) rightCharacterLayer->isChosen());
        leftCharacterLayer->removeFromParent();
        rightCharacterLayer->removeFromParent();
        this->unschedule(schedule_selector(GameScene::chooseCharacterUpdate));
        // schedule gaming scene
        this->schedule(schedule_selector(GameScene::gameLoopUpdate), 2.0f);
    }
}
void GameScene::gameLoopUpdate(float delay) {
    static bool updated = false;
    if(!updated) {
        for(int i = 0;i < 1;i++) {
            auto cardLayer = HandCard::create();
            cardLayer->setScale(0.2f, 0.2f);
            handCardLayout->addChild(cardLayer);
        }
        updated = true;
    }
}