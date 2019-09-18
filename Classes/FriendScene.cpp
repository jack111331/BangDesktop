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
#include "MainMenuScene.h"
#include "AddFriendLayer.h"
#include "ResolutionUtil.h"
#include "FriendTableView.h"
#include "vo/FriendInfo.h"
#include <vector>

USING_NS_CC;

Scene *FriendScene::createScene() {
    return FriendScene::create();
}

// on "init" you need to initialize your instance
bool FriendScene::init() {
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    // 2. cover background image
    auto backgroundImage = ui::ImageView::create("background.png");
    if (backgroundImage) {
        this->addChild(backgroundImage);
    } else {
        log("[FriendScene] Can't Initialize background image.");
    }

    //    Fake Data
    std::vector<FriendInfo> friendInfoList;
    friendInfoList.push_back(FriendInfo(0, "jack"));
    friendInfoList.push_back(FriendInfo(1, "Edge"));

    auto friendTableView = FriendTableView::create();
    if (friendTableView) {
        friendTableView->setFriendInfoList(friendInfoList);
        // After data update, we must reload data to keep it new
        friendTableView->reloadData();
        this->addChild(friendTableView);
    } else {
        log("[FriendScene] Cant' create friend table view.");
    }

    // 3.a add add friend button item
    auto addFriendButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");
    if (addFriendButton) {
        addFriendButton->setPosition(ResolutionUtil::getCorrespondPosition(0.8f, 0.9f));
        addFriendButton->setTitleFontSize(40);
        addFriendButton->setTitleText("+");
        addFriendButton->addClickEventListener(CC_CALLBACK_1(FriendScene::menuAddFriendCallback, this));
        this->addChild(addFriendButton);
    } else {
        log("[FriendScene] Can't initialize add friend button");
    }

    // 3.b add back button item
    auto backButton = ui::Button::create("ready-btn.png", "ready-btn-click.png");
    if (backButton) {
        backButton->setPosition(ResolutionUtil::getCorrespondPosition(0.2f, 0.2f));
        backButton->setTitleFontSize(40);
        backButton->setTitleText("Back");
        backButton->addClickEventListener(CC_CALLBACK_1(FriendScene::menuBackCallback, this));
        this->addChild(backButton);
    } else {
        log("[FriendScene] Can't initialize back button");
    }

    return true;
}

void FriendScene::menuBackCallback(Ref *pSender) {
    Director::getInstance()->popScene();
}

void FriendScene::menuAddFriendCallback(Ref *pSender) {
    auto addFriendLayer = AddFriendLayer::create();
    this->addChild(addFriendLayer);
}

void FriendScene::menuDeleteFriendCallback(Ref *pSender) {
}