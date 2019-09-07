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
#include "FriendScene.h"
#include "LoungeInfo.h"
#include "MainMenuScene.h"
#include "AddFriendLayer.h"
#include "ResolutionUtil.h"
#include <string>

USING_NS_CC;

Scene *FriendScene::createScene()
{
    return FriendScene::create();
}

// on "init" you need to initialize your instance
bool FriendScene::init()
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

    // 3.a add ready button item
    auto backButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (backButton == nullptr)
    {
        log("Can't initialize ready button");
    }
    else
    {
        //Position
        float x = 300.0f;
        float y = 400.0f;
        log("backButton=(%f, %f)\n", x, y);
        backButton->setPosition(Vec2(x, y));

        backButton->setTitleFontSize(40);
        backButton->setTitleText("Back");

        backButton->addClickEventListener(CC_CALLBACK_1(FriendScene::menuBackCallback, this));
    }

    this->addChild(backButton);
    // 3.b add add friend button item
    auto addFriendButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");

    if (addFriendButton == nullptr)
    {
        log("Can't initialize add friend button");
    }
    else
    {
        //Position
        float x = 300.0f;
        float y = 600.0f;
        log("addFriendButton=(%f, %f)\n", x, y);
        addFriendButton->setPosition(Vec2(x, y));

        addFriendButton->setTitleFontSize(40);
        addFriendButton->setTitleText("+");

        addFriendButton->addClickEventListener(CC_CALLBACK_1(FriendScene::menuAddFriendCallback, this));
    }

    this->addChild(addFriendButton);

//    std::vector<LoungeInfo> loungeInfoList;
//    loungeInfoList.push_back(LoungeInfo(1234, false));
//    loungeInfoList.push_back(LoungeInfo(12345, true));
//    for (LoungeInfo loungeInfo : loungeInfoList)
//    {
//        static float iconX = 100.0f;
//        float iconY = 500.0f;
//        Sprite *userIcon = Sprite::create("user-icon.png");
//        userIcon->setPosition(iconX, iconY);
//        iconX += 100.0f;
//        this->addChild(userIcon);
//
//
//        static float usernameX = 100.0f;
//        float usernameY = 450.0f;
//        auto usernameLabel = Label::createWithTTF(std::to_string(loungeInfo.getId()), "fonts/arial.ttf", 40);
//        usernameLabel->setPosition(usernameX, usernameY);
//        usernameX += 100.0f;
//        this->addChild(usernameLabel);
//
//
//        static float readyX = 100.0f;
//        float readyY = 500.0f;
//        auto readyLabel = Label::createWithTTF(loungeInfo.isReady() ? "Ready" : "Not Ready", "fonts/arial.ttf", 40);
//        readyLabel->setPosition(readyX, readyY);
//        readyX += 100.0f;
//        this->addChild(readyLabel);
//
//    }

    auto friendListView = ui::ListView::create();
    if (friendListView == nullptr)
    {
        log("Can't initialize friend list view");
    }
    else
    {
        friendListView->setAnchorPoint(Vec2(0.5, 0.5));
        constexpr float sizeX = 0.4, sizeY = 0.4;
        constexpr float positionX = 0.8, positionY = 0.5;
        friendListView->setContentSize(ResolutionUtil::getCorrespondSize(sizeX, sizeY));
        friendListView->setPosition(ResolutionUtil::getCorrespondPosition(positionX, positionY));
        friendListView->setDirection(ui::ScrollView::Direction::VERTICAL);



        auto trump = Sprite::create("background-layer.png");
        trump->setAnchorPoint(Vec2::ZERO);
        trump->setScale(1.5, 1.5);
        // container
        ui::Layout* listLayout = ui::Layout::create();
        listLayout->addChild(trump);
        listLayout->setContentSize(Size(100, 150));
        // need
        listLayout->setTouchEnabled(true);
        // push item
        friendListView->pushBackCustomItem(listLayout);
    }
    this->addChild(friendListView);

    return true;
}

void FriendScene::menuBackCallback(Ref *pSender)
{
    Director::getInstance()->popScene();
}

void FriendScene::menuAddFriendCallback(Ref *pSender)
{
    auto addFriendLayer = AddFriendLayer::create();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    addFriendLayer->setContentSize(cocos2d::Size(100.0, 100.0));
    addFriendLayer->setAnchorPoint(Size(0.5, 0.5));
    addFriendLayer->setPosition(cocos2d::Vec2(0, visibleSize.height * 0.2));
    this->addChild(addFriendLayer);
}

void FriendScene::menuDeleteFriendCallback(Ref *pSender)
{
    Director::getInstance()->popScene();
}