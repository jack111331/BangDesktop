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
#include "LobbyScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene * MainMenuScene::createScene()
{
    return MainMenuScene::create();

}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    log("visibleSize=(%f, %f)", visibleSize.width, visibleSize.height);
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    log("origin=(%f, %f)", origin.x, origin.y);
    Vector<MenuItem *> menuItemLists;

    // 2. cover background image
    auto backgroundImage = Sprite::create("background.png");
    this->addChild(backgroundImage);

    // 3.a add lobby button item
    auto lobbyButton = MenuItemFont::create(
                                           "Lobby",
                                           CC_CALLBACK_1(MainMenuScene::menuLobbyCallback, this));

    const float menuItemX = 200.0f;
    float menuItemY = 100.0f;

    if (lobbyButton == nullptr)
    {
        log("Can't initialize lobby button");
    }
    else
    {
        log("lobbyButton=(%f, %f)\n", menuItemX, menuItemY);
        lobbyButton->setPosition(Vec2(menuItemX, menuItemY));
        menuItemY -= 30.0f;
    }
    menuItemLists.pushBack(lobbyButton);

    // 3.b add friend button item
    auto friendButton = MenuItemFont::create(
                                           "Friend List",
                                           CC_CALLBACK_1(MainMenuScene::menuFriendCallback, this));

    if (friendButton == nullptr)
    {
        log("Can't initialize friend button");
    }
    else
    {
        log("friendButton=(%f, %f)\n", menuItemX, menuItemY);
        friendButton->setPosition(Vec2(menuItemX, menuItemY));
                menuItemY -= 30.0f;
    }
    menuItemLists.pushBack(friendButton);

    // 3.c add setting button item
    auto settingButton = MenuItemFont::create(
                                           "Setting",
                                           CC_CALLBACK_1(MainMenuScene::menuSettingCallback, this));

    if (settingButton == nullptr)
    {
        log("Can't initialize setting button");
    }
    else
    {
        log("settingButton=(%f, %f)\n", menuItemX, menuItemY);
        settingButton->setPosition(Vec2(menuItemX, menuItemY));
                menuItemY -= 30.0f;
    }
    menuItemLists.pushBack(settingButton);

    // 3.d add log out button item
    auto logoutButton = MenuItemFont::create(
            "Log out",
            CC_CALLBACK_1(MainMenuScene::menuLogoutCallback, this));

    if (logoutButton == nullptr)
    {
        log("Can't initialize exit button");
    }
    else
    {
        log("logoutButton=(%f, %f)\n", menuItemX, menuItemY);
        logoutButton->setPosition(Vec2(menuItemX, menuItemY));
        menuItemY -= 30.0f;
    }
    menuItemLists.pushBack(logoutButton);

    // 3.e add exit button item
    auto exitButton = MenuItemFont::create(
                                           "Exit",
                                           CC_CALLBACK_1(MainMenuScene::menuExitCallback, this));

    if (exitButton == nullptr)
    {
        log("Can't initialize exit button");
    }
    else
    {
        log("exitButton=(%f, %f)\n", menuItemX, menuItemY);
        exitButton->setPosition(Vec2(menuItemX, menuItemY));
    }
    menuItemLists.pushBack(exitButton);

    auto menu = Menu::createWithArray(menuItemLists);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}


void MainMenuScene::menuLobbyCallback(Ref* pSender)
{
    Director::getInstance()->pushScene(LobbyScene::createScene());
}

void MainMenuScene::menuFriendCallback(Ref* pSender)
{
    return;
}

void MainMenuScene::menuSettingCallback(Ref* pSender)
{
    return;
}
void MainMenuScene::menuLogoutCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->popScene();
}
void MainMenuScene::menuExitCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
}