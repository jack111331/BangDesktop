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
#include "LoginScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* LoginScene::createScene()
{
    return LoginScene::create();
}

// on "init" you need to initialize your instance
bool LoginScene::init()
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


    // 2. add a button item
    auto loginButton = MenuItemFont::create(
                                           "Login",
                                           CC_CALLBACK_1(LoginScene::menuLoginCallback, this));

    if (loginButton == nullptr)
    {
        log("Can't initialize login button");
    }
    else
    {
        float x = origin.x + visibleSize.width - loginButton->getContentSize().width/2;
        float y = origin.y + loginButton->getContentSize().height/2;
        log("loginButton=(%f, %f)\n", x, y);
        loginButton->setPosition(Vec2(x,y));
    }
    auto menu = Menu::create(loginButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    // 3. add a textField item
    auto usernameTextField = ui::TextField::create("Username", "fonts/arial.ttf", 40);

    if (usernameTextField == nullptr)
    {
        log("Can't initialize username textfield");
    }
    else
    {
        float x = 200.0f;
        float y = 100.0f;
        log("usernameTextField=(%f, %f)\n", x, y);
        usernameTextField->setPosition(Vec2(x,y));
    }

    this->addChild(usernameTextField);


    return true;
}


void LoginScene::menuLoginCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
