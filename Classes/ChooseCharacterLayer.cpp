//
// Created by edge on 2019-09-09.
//

#include "ChooseCharacterLayer.h"
#include "LargeCardLayer.h"

USING_NS_CC;

ChooseCharacterLayer::ChooseCharacterLayer()
{

}

bool ChooseCharacterLayer::init()
{
    // 1. super init first
    if (!LargeCardLayer::init())
    {
        return false;
    }
    this->setAnchorPoint(Vec2::ZERO);
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto eventListener = EventListenerTouchOneByOne::create();
    eventListener->onTouchBegan = CC_CALLBACK_2(ChooseCharacterLayer::onTouchBegan, this);
    eventListener->onTouchEnded = CC_CALLBACK_2(ChooseCharacterLayer::onTouchEnded, this);
    eventListener->setSwallowTouches(true);
    eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

    return true;
}

bool ChooseCharacterLayer::onTouchBegan(Touch *touch, Event *event)
{
    auto target = event->getCurrentTarget();

    //Get the position of the current point relative to the button
    auto locationInNode = touch->getLocation();
    log("locationInNode=(%f, %f)", locationInNode.x, locationInNode.y);

    // Because of layer is middle aligned, so we need to adjust bounding box
    auto boundingBoxSize = target->getBoundingBox().size;
    auto rect = Rect(target->getPosition().x - boundingBoxSize.width / 2.0f,
                     target->getPosition().y - boundingBoxSize.height / 2.0f, boundingBoxSize.width,
                     boundingBoxSize.height);

    //Check the click area
    if (rect.containsPoint(locationInNode))
    {
        log("touched layer began");
        return true;
    }
    return false;
}

void ChooseCharacterLayer::onTouchEnded(Touch *touch, Event *event)
{
    log("touched layer ended");
    this->onClickCallback(event->getCurrentTarget());
}

void ChooseCharacterLayer::onClickCallback(Ref *pSender)
{
    this->chosen = true;
}

const std::string &ChooseCharacterLayer::getCharacterName() const
{
    return characterName;
}

void ChooseCharacterLayer::setCharacterName(const std::string &characterName)
{
    this->characterName = characterName;
}

bool ChooseCharacterLayer::isChosen() const
{
    return chosen;
}

ChooseCharacterLayer::~ChooseCharacterLayer()
{

}

