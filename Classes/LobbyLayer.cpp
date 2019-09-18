#include "ui/CocosGUI.h"
#include "LobbyLayer.h"
#include "vo/LoungeInfo.h"
#include "GameScene.h"
#include "ResolutionUtil.h"
#include "LobbyMemberTableView.h"
#include <string>

USING_NS_CC;
USING_NS_CC_EXT;

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

    auto lobbyMemberLayout = ui::Layout::create();

    auto userIcon = ui::ImageView::create("user-icon.png");
    userIcon->ignoreContentAdaptWithSize(false);
    userIcon->setContentSize(ResolutionUtil::getCorrespondSize(0.08f, 0.1f));
    lobbyMemberLayout->addChild(userIcon);
    auto userIcon1 = ui::ImageView::create("user-icon.png");
    userIcon1->ignoreContentAdaptWithSize(false);
    userIcon1->setContentSize(ResolutionUtil::getCorrespondSize(0.08f, 0.1f));
    lobbyMemberLayout->addChild(userIcon1);

    lobbyMemberLayout->setBackGroundColorType(ui::LAYOUT_COLOR_SOLID);
    lobbyMemberLayout->setBackGroundColor(Color3B::RED);
    lobbyMemberLayout->setContentSize(ResolutionUtil::getCorrespondSize(0.35f, 0.1f));
    lobbyMemberLayout->setAnchorPoint(Vec2(0.5f, 0.5f));
    lobbyMemberLayout->setPosition(ResolutionUtil::getCorrespondPosition(0.7f, 0.95f));
    lobbyMemberLayout->setTouchEnabled(true);
    lobbyMemberLayout->addClickEventListener(CC_CALLBACK_1(LobbyLayer::layerTouchCallback, this));
    lobbyMemberLayout->setLayoutType(ui::LAYOUT_LINEAR_HORIZONTAL);
    this->addChild(lobbyMemberLayout);


    this->lobbyMemberDetailLayout = ui::Layout::create();

    // 3. add user info
    std::vector<LoungeInfo> loungeInfoList;
    loungeInfoList.push_back(LoungeInfo(1234, false));
    loungeInfoList.push_back(LoungeInfo(12345, true));
    auto lobbyMemberTableView = LobbyMemberTableView::create();
    lobbyMemberTableView->setLoungeInfoList(loungeInfoList);
    lobbyMemberTableView->reloadData();
    lobbyMemberDetailLayout->addChild(lobbyMemberTableView);

    // 4. add ready button item
    this->readyButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");
    if (readyButton == nullptr) {
        log("Can't initialize ready button");
    } else {

        readyButton->setTitleFontSize(40);
        readyButton->setTitleText("Ready");

        readyButton->addClickEventListener(CC_CALLBACK_1(LobbyLayer::menuReadyCallback, this));
    }
    lobbyMemberDetailLayout->addChild(readyButton);

    // 5. add start button
    auto startButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (startButton == nullptr) {
        log("Can't initialize start button");
    } else {

        startButton->setTitleFontSize(40);
        startButton->setTitleText("Start");

        startButton->addClickEventListener(CC_CALLBACK_1(LobbyLayer::menuStartCallback, this));
    }
    lobbyMemberDetailLayout->addChild(startButton);

    lobbyMemberDetailLayout->setBackGroundColorType(ui::LAYOUT_COLOR_SOLID);
    lobbyMemberDetailLayout->setBackGroundColor(Color3B::RED);
    lobbyMemberDetailLayout->setContentSize(ResolutionUtil::getCorrespondSize(0.35f, 0.5f));
    lobbyMemberDetailLayout->setAnchorPoint(Vec2(0.5f, 0.5f));
    lobbyMemberDetailLayout->setPosition(ResolutionUtil::getCorrespondPosition(0.7f, 0.6f));
    lobbyMemberDetailLayout->setLayoutType(ui::LAYOUT_LINEAR_VERTICAL);
    this->addChild(lobbyMemberDetailLayout);

    lobbyMemberDetailLayout->setVisible(false);

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
void LobbyLayer::layerTouchCallback(Ref * pSender){
    log("click layer");
    lobbyMemberDetailLayout->setVisible(!lobbyMemberDetailLayout->isVisible());
}

LobbyLayer::~LobbyLayer() {

}