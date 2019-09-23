#include "ui/CocosGUI.h"
#include "LobbyLayer.h"
#include "vo/LoungeInfo.h"
#include "GameScene.h"
#include "ResolutionUtil.h"
#include "LobbyMemberTableView.h"

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
    if (backgroundImage) {
        backgroundImage->setContentSize(ResolutionUtil::getCorrespondSize(0.35f, 0.1f));
        backgroundImage->setPosition(ResolutionUtil::getCorrespondPosition(0.7f, 0.95f));
        this->addChild(backgroundImage);
    } else {
        log("[LobbyLayer] Can't initialize background image");
    }

    auto lobbyMemberLayout = ui::Layout::create();
    lobbyMemberLayout->setContentSize(ResolutionUtil::getCorrespondSize(0.35f, 0.1f));
    lobbyMemberLayout->setAnchorPoint(Vec2(0.5f, 0.5f));
    lobbyMemberLayout->setPosition(ResolutionUtil::getCorrespondPosition(0.7f, 0.95f));
    lobbyMemberLayout->setTouchEnabled(true);
    lobbyMemberLayout->addClickEventListener(CC_CALLBACK_1(LobbyLayer::layerTouchCallback, this));
    lobbyMemberLayout->setLayoutType(ui::Layout::Type::HORIZONTAL);
    this->addChild(lobbyMemberLayout);

    this->lobbyMemberDetailLayout = ui::Layout::create();
    lobbyMemberDetailLayout->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
    lobbyMemberDetailLayout->setBackGroundColor(Color3B::RED);
    lobbyMemberDetailLayout->setContentSize(ResolutionUtil::getCorrespondSize(0.35f, 0.5f));
    lobbyMemberDetailLayout->setAnchorPoint(Vec2(0.0f, 1.0f));
    lobbyMemberDetailLayout->setPosition(ResolutionUtil::getCorrespondPosition(0.525f, 0.9f));
    lobbyMemberDetailLayout->setLayoutType(ui::Layout::Type::VERTICAL);
    lobbyMemberDetailLayout->setVisible(false);
    this->addChild(lobbyMemberDetailLayout);

    // fake data
    for (int i = 0; i < 2; i++) {
        auto userIcon = ui::ImageView::create("user-icon.png");
        userIcon->ignoreContentAdaptWithSize(false);
        userIcon->setContentSize(ResolutionUtil::getCorrespondSize(0.08f, 0.1f));
        lobbyMemberLayout->addChild(userIcon);
    }

    // fake data
    std::vector<LoungeInfo> loungeInfoList;
    loungeInfoList.push_back(LoungeInfo(1234, false));
    loungeInfoList.push_back(LoungeInfo(12345, true));

    // 3. add user info
    auto lobbyMemberTableView = LobbyMemberTableView::create();
    lobbyMemberTableView->setLoungeInfoList(loungeInfoList);
    lobbyMemberTableView->reloadData();
    lobbyMemberDetailLayout->addChild(lobbyMemberTableView);

    // 4. add ready button item
    this->readyButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");
    if (readyButton) {
        readyButton->setTitleFontSize(40);
        readyButton->setTitleText("Ready");
        readyButton->addClickEventListener(CC_CALLBACK_1(LobbyLayer::menuReadyCallback, this));
        lobbyMemberDetailLayout->addChild(readyButton);
    } else {
        log("[LobbyLayer] Can't initialize ready button");
    }

    // 5. add start button
    auto startButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (startButton) {
        startButton->setTitleFontSize(40);
        startButton->setTitleText("Start");
        startButton->addClickEventListener(CC_CALLBACK_1(LobbyLayer::menuStartCallback, this));
        lobbyMemberDetailLayout->addChild(startButton);
    } else {
        log("[LobbyLayer] Can't initialize start button");
    }

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

void LobbyLayer::layerTouchCallback(Ref *pSender) {
    log("click layer");
    lobbyMemberDetailLayout->setVisible(!lobbyMemberDetailLayout->isVisible());
}

LobbyLayer::~LobbyLayer() {

}