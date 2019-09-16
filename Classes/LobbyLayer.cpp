#include "ui/CocosGUI.h"
#include "LobbyLayer.h"
#include "vo/LoungeInfo.h"
#include "GameScene.h"
#include "ResolutionUtil.h"
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
    auto backgroundImage = Sprite::create("background.png");

    this->addChild(backgroundImage);

    // 3. add ready button item
    this->readyButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (readyButton == nullptr) {
        log("Can't initialize ready button");
    } else {
        //Position
        float x = 300.0f;
        float y = 400.0f;
        log("readyButton=(%f, %f)\n", x, y);
        readyButton->setPosition(Vec2(x, y));

        readyButton->setTitleFontSize(40);
        readyButton->setTitleText("Ready");

        readyButton->addClickEventListener(CC_CALLBACK_1(LobbyLayer::menuReadyCallback, this));
    }

    this->addChild(readyButton);

    // 4. add user info
    std::vector<LoungeInfo> loungeInfoList;
    loungeInfoList.push_back(LoungeInfo(1234, false));
    loungeInfoList.push_back(LoungeInfo(12345, true));
    for (LoungeInfo loungeInfo : loungeInfoList) {
        static float iconX = 0.2f;
        float iconY = 0.7f;
        Sprite *userIcon = Sprite::create("user-icon.png");
        userIcon->setScale(0.1f, 0.1f);
        userIcon->setPosition(ResolutionUtil::getCorrespondPosition(iconX, iconY));
        iconX += 0.2f;
        this->addChild(userIcon);


        static float usernameX = 0.2f;
        float usernameY = 0.5f;
        Label *usernameLabel = Label::create(std::to_string(loungeInfo.getId()), "fonts/arial.ttf", 40);
        usernameLabel->setPosition(ResolutionUtil::getCorrespondPosition(usernameX, usernameY));
        usernameX += 0.2f;
        this->addChild(usernameLabel);


        static float readyX = 0.2f;
        float readyY = 0.4f;
        auto readyText = ui::Text::create(loungeInfo.isReady() ? "Ready" : "Not Ready", "fonts/arial.ttf", 40);
        readyText->setPosition(ResolutionUtil::getCorrespondPosition(readyX, readyY));
        readyX += 0.2f;
        this->addChild(readyText);

    }

    // 5. add start button
    auto startButton = ui::Button::create("login-btn.png", "login-btn-click.png");

    if (startButton == nullptr) {
        log("Can't initialize start button");
    } else {
        //Position
        float startButtonX = 0.5f;
        float startButtonY = 0.2f;
        log("startButton=(%f, %f)\n", startButtonX, startButtonY);
        startButton->setPosition(ResolutionUtil::getCorrespondPosition(startButtonX, startButtonY));

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
        readyButton->setTitleText("Ready");
    } else {
        readyButton->loadTextureNormal("ready-btn.png");
        readyButton->loadTexturePressed("ready-btn-click.png");
        readyButton->setTitleText("Not Ready");
    }

}

void LobbyLayer::menuStartCallback(Ref *pSender) {
    Director::getInstance()->pushScene(GameScene::createScene());
}

LobbyLayer::~LobbyLayer() {

}