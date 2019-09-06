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
#include "LobbyScene.h"
#include "LoungeInfo.h"
#include "MainMenuScene.h"
#include <string>

USING_NS_CC;

Scene *LobbyScene::createScene()
{
    return LobbyScene::create();
}

// on "init" you need to initialize your instance
bool LobbyScene::init()
{
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    log("visibleSize=(%f, %f)", visibleSize.width, visibleSize.height);
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    log("origin=(%f, %f)", origin.x, origin.y);

    // 2. cover background image
    auto backgroundImage = Sprite::create("background.png");
    this->addChild(backgroundImage);

    // 3. add ready button item
    this->readyButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (readyButton == nullptr)
    {
        log("Can't initialize ready button");
    }
    else
    {
        //Position
        float x = 300.0f;
        float y = 400.0f;
        log("readyButton=(%f, %f)\n", x, y);
        readyButton->setPosition(Vec2(x, y));

        readyButton->setTitleFontSize(40);
        readyButton->setTitleText("Ready");

        readyButton->addClickEventListener(CC_CALLBACK_1(LobbyScene::menuReadyCallback, this));
    }

    this->addChild(readyButton);


    std::vector<LoungeInfo> loungeInfoList;
    loungeInfoList.push_back(LoungeInfo(1234, false));
    loungeInfoList.push_back(LoungeInfo(12345, true));
    for (LoungeInfo loungeInfo : loungeInfoList)
    {
        static float iconX = 100.0f;
        float iconY = 500.0f;
        Sprite *userIcon = Sprite::create("user-icon.png");
        userIcon->setPosition(iconX, iconY);
        iconX += 100.0f;
        this->addChild(userIcon);


        static float usernameX = 100.0f;
        float usernameY = 450.0f;
        Label *usernameLabel = Label::create(std::to_string(loungeInfo.getId()), "fonts/arial.ttf", 40);
        usernameLabel->setPosition(usernameX, usernameY);
        usernameX += 100.0f;
        this->addChild(usernameLabel);


        static float readyX = 100.0f;
        float readyY = 500.0f;
        Label *readyLabel = Label::create(loungeInfo.isReady() ? "Ready" : "Not Ready", "fonts/arial.ttf", 40);
        readyLabel->setPosition(readyX, readyY);
        readyX += 100.0f;
        this->addChild(readyLabel);

    }


    auto exitButton = ui::Button::create("login-btn.png", "login-btn-click.png");

    if (exitButton == nullptr)
    {
        log("Can't initialize exit button");
    }
    else
    {
        //Position
        float x = 500.0f;
        float y = 600.0f;
        log("exitButton=(%f, %f)\n", x, y);
        exitButton->setPosition(Vec2(x, y));

        exitButton->setTitleFontSize(40);
        exitButton->setTitleText("Exit");

        exitButton->addClickEventListener(CC_CALLBACK_1(LobbyScene::menuExitCallback, this));
    }
    this->addChild(exitButton);


    return true;
}


void LobbyScene::menuReadyCallback(Ref *pSender)
{
    ready = !ready;
    if (ready)
    {
        readyButton->loadTextureNormal("ready-btn-ready.png");
        readyButton->loadTexturePressed("ready-btn-ready-click.png");
    }
    else
    {
        readyButton->loadTextureNormal("ready-btn.png");
        readyButton->loadTexturePressed("ready-btn-click.png");
    }

}
void LobbyScene::menuExitCallback(Ref *pSender)
{
    Director::getInstance()->popScene();
}