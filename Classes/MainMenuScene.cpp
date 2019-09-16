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

    Vector<MenuItem *> menuItemLists;

    // 2. cover background image
    auto backgroundImage = Sprite::create("background.png");
    this->addChild(backgroundImage);

    const float menuItemX = 0.5f;
    float menuItemY = 0.7f;

    // 3.a add friend button item
    auto friendButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (friendButton == nullptr) {
        log("Can't initialize friend button");
    } else {
        //Position
        log("friendButton=(%f, %f)\n", menuItemX, menuItemY);
        friendButton->setPosition(ResolutionUtil::getCorrespondPosition(menuItemX, menuItemY));
        menuItemY -= 0.15f;

        friendButton->setTitleFontSize(40);
        friendButton->setTitleText("Friend List");

        friendButton->addClickEventListener(CC_CALLBACK_1(MainMenuScene::menuFriendCallback, this));
    }

    this->addChild(friendButton);

    // 3.b add setting button item
    auto settingButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (settingButton == nullptr) {
        log("Can't initialize setting button");
    } else {
        //Position
        log("settingButton=(%f, %f)\n", menuItemX, menuItemY);
        settingButton->setPosition(ResolutionUtil::getCorrespondPosition(menuItemX, menuItemY));
        menuItemY -= 0.15f;

        settingButton->setTitleFontSize(40);
        settingButton->setTitleText("Setting");

        settingButton->addClickEventListener(CC_CALLBACK_1(MainMenuScene::menuSettingCallback, this));
    }

    this->addChild(settingButton);
    // 3.c add log out button item
    auto logoutButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (logoutButton == nullptr) {
        log("Can't initialize logout button");
    } else {
        //Position
        log("logoutButton=(%f, %f)\n", menuItemX, menuItemY);
        logoutButton->setPosition(ResolutionUtil::getCorrespondPosition(menuItemX, menuItemY));
        menuItemY -= 0.15f;

        logoutButton->setTitleFontSize(40);
        logoutButton->setTitleText("Log out");

        logoutButton->addClickEventListener(CC_CALLBACK_1(MainMenuScene::menuLogoutCallback, this));
    }

    this->addChild(logoutButton);
    // 3.d add exit button item
    auto exitButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (exitButton == nullptr) {
        log("Can't initialize exit button");
    } else {
        //Position
        log("logoutButton=(%f, %f)\n", menuItemX, menuItemY);
        exitButton->setPosition(ResolutionUtil::getCorrespondPosition(menuItemX, menuItemY));

        exitButton->setTitleFontSize(40);
        exitButton->setTitleText("Exit");

        exitButton->addClickEventListener(CC_CALLBACK_1(MainMenuScene::menuExitCallback, this));
    }

    this->addChild(exitButton);
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