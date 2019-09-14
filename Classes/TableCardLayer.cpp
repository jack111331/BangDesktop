//
// Created by edge on 2019-09-14.
//

#include "TableCardLayer.h"
#include "SmallCardLayer.h"

USING_NS_CC;

TableCardLayer::TableCardLayer() {

}

bool TableCardLayer::init() {
    // 1. super init first
    if (!SmallCardLayer::init()) {
        return false;
    }
    this->setAnchorPoint(Vec2::ZERO);
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto eventListener = EventListenerTouchOneByOne::create();
    eventListener->onTouchBegan = CC_CALLBACK_2(TableCardLayer::onTouchBegan, this);
    eventListener->onTouchMoved = CC_CALLBACK_2(TableCardLayer::onTouchMoved, this);
    eventListener->onTouchEnded = CC_CALLBACK_2(TableCardLayer::onTouchEnded, this);
    eventListener->setSwallowTouches(true);
    eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

    return true;
}

bool TableCardLayer::onTouchBegan(Touch *touch, Event *event) {
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
    if (rect.containsPoint(locationInNode)) {
        log("touched layer began");
        return true;
    }
    return false;
}

void TableCardLayer::onTouchMoved(Touch *touch, Event *event) {
    // Show card info in left side
}

void TableCardLayer::onTouchEnded(Touch *touch, Event *event) {
    // Hude card info
}


TableCardLayer::~TableCardLayer() {

}