//
// Created by edge on 2019-09-13.
//

#include "HandCard.h"
#include "SmallCardLayer.h"

USING_NS_CC;

HandCard::HandCard() {
    this->smallCardLayer = SmallCardLayer::create();
    this->setAnchorPoint(Vec2::ZERO);
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto eventListener = EventListenerTouchOneByOne::create();
    eventListener->onTouchBegan = CC_CALLBACK_2(HandCard::onTouchBegan, this);
    eventListener->onTouchMoved = CC_CALLBACK_2(HandCard::onTouchMoved, this);
    eventListener->onTouchEnded = CC_CALLBACK_2(HandCard::onTouchEnded, this);
    eventListener->setSwallowTouches(true);
    eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
    this->ignoreContentAdaptWithSize(false);
    this->setContentSize(smallCardLayer->getBoundingBox().size);
    this->addChild(smallCardLayer);
}

bool HandCard::onTouchBegan(Touch *touch, Event *event) {
    auto target = smallCardLayer;

    //Get the position of the current point relative to the button
    auto touchLocation = smallCardLayer->convertTouchToNodeSpace(touch);
    log("touchLocation=(%f, %f)", touchLocation.x, touchLocation.y);

    // Because of layer is middle aligned, so we need to adjust bounding box
    auto boundingBoxSize = target->getBoundingBox().size;
    auto rect = Rect(target->getPosition().x - boundingBoxSize.width / 2.0f,
                     target->getPosition().y - boundingBoxSize.height / 2.0f, boundingBoxSize.width,
                     boundingBoxSize.height);
    log("targetPosition=(%f, %f)", target->getPosition().x, target->getPosition().y);
    //Check the click area
    if (rect.containsPoint(touchLocation)) {
        log("touched layer began");
        return true;
    }
    return false;
}

void HandCard::onTouchMoved(Touch *touch, Event *event) {
    this->setPosition(touch->getLocation());
}

void HandCard::onTouchEnded(Touch *touch, Event *event) {
    if (touch->getLocation().y >= Director::getInstance()->getVisibleSize().height * 0.25) {
        this->onPlayCardCallback(event->getCurrentTarget());
    } else {
        // back to its original position
        // this->setPosition(touch->getLocation());
    }
}

void HandCard::onPlayCardCallback(Ref *pSender) {
    // inform parent scene to play card animation
    this->removeFromParent();
}

HandCard::~HandCard() {

}