//
// Created by edge on 2019-09-23.
//
#include "ui/CocosGUI.h"
#include "PlayerLayer.h"
#include "ResolutionUtil.h"
#include "LobbyMemberTableView.h"

USING_NS_CC;
USING_NS_CC_EXT;

PlayerLayer::PlayerLayer() {

}

// on "init" you need to initialize your instance
bool PlayerLayer::init() {
    // 1. super init first
    if (!Layer::init()) {
        return false;
    }

    // 2. character image
    this->characterImage = ui::ImageView::create("user-icon.png");
    if (characterImage) {
        characterImage->ignoreContentAdaptWithSize(false);
        characterImage->setContentSize(ResolutionUtil::getCorrespondSize(0.13f, 0.2f));
        characterImage->setPosition(ResolutionUtil::getCorrespondPosition(0.5f, 0.5f));
        this->addChild(characterImage);
    } else {
        log("[PlayerLayer] Can't initialize character image");
    }

    this->healthLayout = ui::Layout::create();
    // TODO middle align health icon

    //    healthLayout->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
    //    healthLayout->setBackGroundColor(Color3B::RED);
    healthLayout->setContentSize(ResolutionUtil::getCorrespondSize(0.35f, 0.1f));
    healthLayout->setAnchorPoint(Vec2(0.5f, 0.5f));
    healthLayout->setPosition(ResolutionUtil::getCorrespondPosition(0.5f, 0.35f));
    healthLayout->setLayoutType(ui::Layout::Type::HORIZONTAL);
    this->addChild(healthLayout);

    this->updateHealthIcon();

    return true;
}

PlayerLayer::~PlayerLayer() {

}

void PlayerLayer::setHp(int hp) {
    PlayerLayer::hp = hp;
    this->updateHealthIcon();
}

void PlayerLayer::updateHealthIcon() {
    healthLayout->removeAllChildrenWithCleanup(true);
    for (int i = 0; i < hp; i++) {
        auto healthIcon = ui::ImageView::create("hp-logo.png");
        if (healthIcon) {
            healthIcon->ignoreContentAdaptWithSize(false);
            healthIcon->setContentSize(ResolutionUtil::getCorrespondSize(0.06f, 0.06f));
            healthLayout->addChild(healthIcon);
        } else {
            log("[PlayerLayer] Can't initialize healthIcon image");
        }
    }
}
