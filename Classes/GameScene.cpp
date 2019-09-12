//
// Created by edge on 2019-09-09.
//

#include "GameScene.h"
#include "ChooseCharacterLayer.h"

#include "ui/CocosGUI.h"
#include "ResolutionUtil.h"
#include "SmallCardLayer.h"

USING_NS_CC;


Scene* GameScene::createScene()
{

    return GameScene::create();

}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    log("visibleSize=(%f, %f)", visibleSize.width, visibleSize.height);
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    log("origin=(%f, %f)", origin.x, origin.y);

    // 2. cover background image
    auto backgroundImage = Sprite::create("background.png");

    this->addChild(backgroundImage);

    // 3.a add leftchoose character layer
    auto leftChooseCharacterLayer = ChooseCharacterLayer::create();
    leftChooseCharacterLayer->setPosition(ResolutionUtil::getCorrespondPosition(0.25f, 0.5f));
    leftChooseCharacterLayer->setScale(0.6f);
    this->addChild(leftChooseCharacterLayer);

    // 3.b add right choose character layer
    auto rightChooseCharacterLayer = ChooseCharacterLayer::create();
    rightChooseCharacterLayer->setPosition(ResolutionUtil::getCorrespondPosition(0.75f, 0.5f));
    rightChooseCharacterLayer->setScale(0.6f);
    this->addChild(rightChooseCharacterLayer);

    // 4. add card layer
//    auto cardLayer = SmallCardLayer::create();
//    cardLayer->setPosition(ResolutionUtil::getCorrespondPosition(0.5f, 0.5f));
//    cardLayer->setScale(0.2f, 0.2f);
//    this->addChild(cardLayer);

    return true;
}

