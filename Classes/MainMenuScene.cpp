/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "ui/CocosGUI.h"
#include "MainMenuScene.h"

#include "FriendScene.h"
#include "SettingScene.h"

#include "SimpleAudioEngine.h"
#include "ResolutionUtil.h"

#include "LobbyLayer.h"

USING_NS_CC;

Scene *MainMenuScene::createScene() {
    return MainMenuScene::create();

}

// on "init" you need to initialize your instance
bool MainMenuScene::init() {
    // 1.a super init first
    if (!Scene::init()) {
        return false;
    }

    // 1.b init background music
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->preloadBackgroundMusic("music/bg.mp3");
    if (!audio->isBackgroundMusicPlaying()) {
        audio->playBackgroundMusic("music/bg.mp3");
    }

    // 2. cover background image
    auto backgroundImage = ui::ImageView::create("background.png");
    if(backgroundImage) {
        this->addChild(backgroundImage);

    } else {
        log("[MainMenuScene] Can't initialize background image.");
    }


    auto menuButtonLayout = ui::Layout::create();


    // 3.a add friend button item
    auto friendButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");
    if (friendButton) {
        friendButton->setAnchorPoint(Vec2(0.5f, 0.5f));
        friendButton->setTitleFontSize(40);
        friendButton->setTitleText("Friend List");

        friendButton->addClickEventListener(CC_CALLBACK_1(MainMenuScene::menuFriendCallback, this));
        menuButtonLayout->addChild(friendButton);
    } else {
        log("[MainMenuScene] Can't initialize friend button.");
    }

    // 3.b add setting button item
    auto settingButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");
    if (settingButton) {
        settingButton->setTitleFontSize(40);
        settingButton->setTitleText("Setting");

        settingButton->addClickEventListener(CC_CALLBACK_1(MainMenuScene::menuSettingCallback, this));
        menuButtonLayout->addChild(settingButton);
    } else {
        log("[MainMenuScene] Can't initialize setting button");
    }

    // 3.c add log out button item
    auto logoutButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");
    if (logoutButton) {

        logoutButton->setTitleFontSize(40);
        logoutButton->setTitleText("Log out");

        logoutButton->addClickEventListener(CC_CALLBACK_1(MainMenuScene::menuLogoutCallback, this));
        menuButtonLayout->addChild(logoutButton);
    } else {
        log("[MainMenuScene] Can't initialize logout button");
    }
    // 3.d add exit button item
    auto exitButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (exitButton) {
        exitButton->setTitleFontSize(40);
        exitButton->setTitleText("Exit");

        exitButton->addClickEventListener(CC_CALLBACK_1(MainMenuScene::menuExitCallback, this));
        menuButtonLayout->addChild(exitButton);
    } else {
        log("[mainMenuScene] Can't initialize exit button");
    }

    menuButtonLayout->setContentSize(ResolutionUtil::getCorrespondSize(0.4f, 0.6f));
    menuButtonLayout->setLayoutType(ui::Layout::Type::VERTICAL);
    menuButtonLayout->setAnchorPoint(Vec2(0.5f, 0.5f));
    menuButtonLayout->setPosition(ResolutionUtil::getCorrespondPosition(0.5f, 0.5f));
    this->addChild(menuButtonLayout);

    // TODO optimize creation of lobby layer
    auto lobbyLayer = LobbyLayer::create();
    Director::getInstance()->setNotificationNode(lobbyLayer);

    return true;
}


void MainMenuScene::menuFriendCallback(Ref *pSender) {
    Director::getInstance()->pushScene(FriendScene::createScene());
}

void MainMenuScene::menuSettingCallback(Ref *pSender) {
    Director::getInstance()->pushScene(SettingScene::createScene());
}

void MainMenuScene::menuLogoutCallback(Ref *pSender) {
    Director::getInstance()->popScene();
}

void MainMenuScene::menuExitCallback(Ref *pSender) {
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
}