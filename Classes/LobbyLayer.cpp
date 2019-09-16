#include "ui/CocosGUI.h"
#include "LobbyLayer.h"
#include "vo/LoungeInfo.h"
#include "GameScene.h"
#include "ResolutionUtil.h"
#include "LobbyMemberTableView.h"
#include <string>

USING_NS_CC;

LobbyLayer::LobbyLayer() {

}

// on "init" you need to initialize your instance
bool LobbyLayer::init() {
    // 1. super init first
    if (!Layer::init()) {
        return false;
    }

    // 2. cover background image
    auto backgroundImage = Sprite::create("background-layer.png");
    backgroundImage->setContentSize(ResolutionUtil::getCorrespondSize(0.35f, 0.1f));
    backgroundImage->setPosition(ResolutionUtil::getCorrespondPosition(0.7f, 0.95f));
    this->addChild(backgroundImage);

    // 3. add user info
    std::vector<LoungeInfo> loungeInfoList;
    loungeInfoList.push_back(LoungeInfo(1234, false));
    loungeInfoList.push_back(LoungeInfo(12345, true));
    auto lobbyMemberTableView = LobbyMemberTableView::create();
    lobbyMemberTableView->setLoungeInfoList(loungeInfoList);
    lobbyMemberTableView->reloadData();
    lobbyMemberTableView->setPosition(ResolutionUtil::getCorrespondPosition(0.55f, 0.6f));
    this->addChild(lobbyMemberTableView);

    // 4. add ready button item
    this->readyButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");
    if (readyButton == nullptr) {
        log("Can't initialize ready button");
    } else {
        readyButton->setPosition(ResolutionUtil::getCorrespondPosition(0.7f, 0.5f));

        readyButton->setTitleFontSize(40);
        readyButton->setTitleText("Ready");

        readyButton->addClickEventListener(CC_CALLBACK_1(LobbyLayer::menuReadyCallback, this));
    }
    this->addChild(readyButton);

    // 5. add start button
    auto startButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (startButton == nullptr) {
        log("Can't initialize start button");
    } else {
        startButton->setPosition(ResolutionUtil::getCorrespondPosition(0.7f, 0.4f));

        startButton->setTitleFontSize(40);
        startButton->setTitleText("Start");

        startButton->addClickEventListener(CC_CALLBACK_1(LobbyLayer::menuStartCallback, this));
    }
    this->addChild(startButton);

    return true;
}


void LobbyLayer::menuReadyCallback(Ref *pSender) {
    ready = !ready;
    if (ready) {
        readyButton->loadTextureNormal("ready-btn-ready.png");
        readyButton->loadTexturePressed("ready-btn-ready-click.png");
    } else {
        readyButton->loadTextureNormal("ready-btn.png");
        readyButton->loadTexturePressed("ready-btn-click.png");
    }

}

void LobbyLayer::menuStartCallback(Ref *pSender) {
    Director::getInstance()->pushScene(GameScene::createScene());
}

LobbyLayer::~LobbyLayer() {

}