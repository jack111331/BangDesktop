//
// Created by edge on 2019-09-09.
//

#include "GameScene.h"
#include "ChooseCharacterLayer.h"

#include "ui/CocosGUI.h"
#include "ResolutionUtil.h"

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

    // 3. add choose character layer
    auto chooseCharacterLayer = ChooseCharacterLayer::create();
    chooseCharacterLayer->setAnchorPoint(Size(0.5, 0.5));
    chooseCharacterLayer->setPosition(ResolutionUtil::getCorrespondPosition(0.5, 0.5));
    this->addChild(chooseCharacterLayer);

    return true;
}

