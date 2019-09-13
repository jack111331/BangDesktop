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
#include "MainMenuScene.h"
#include "User.h"
#include "ResolutionUtil.h"

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

    // 2. cover background image
    auto backgroundImage = Sprite::create("background.png");
    this->addChild(backgroundImage);

    // 3. add login button item
    auto loginButton = ui::Button::create("login-btn.png", "login-btn-click.png");

    if (loginButton == nullptr)
    {
        log("Can't initialize login button");
    }
    else
    {
        //Position
        constexpr float x = 0.7f, y = 0.5f;
        log("loginButton=(%f, %f)\n", x, y);
        loginButton->setPosition(ResolutionUtil::getCorrespondPosition(x, y));

        loginButton->setTitleFontSize(40);
        loginButton->setTitleText("Log in");
        auto loginButtonTitleSize = loginButton->getTitleRenderer()->getContentSize();
        loginButton->ignoreContentAdaptWithSize(false);
        loginButton->setContentSize(Size(loginButtonTitleSize.width * 3.0f, loginButtonTitleSize.height * 1.7f));

        loginButton->addClickEventListener(CC_CALLBACK_1(LoginScene::menuLoginCallback, this));
    }
    this->addChild(loginButton);

    // 4. add a textField item
    usernameTextField = ui::TextField::create("Username", "fonts/arial.ttf", 40);

    if (usernameTextField == nullptr)
    {
        log("Can't initialize username textfield");
    }
    else
    {
        constexpr float x = 0.4f, y = 0.55f;
        log("usernameTextField=(%f, %f)\n", x, y);
        usernameTextField->setPosition(ResolutionUtil::getCorrespondPosition(x, y));
    }

    this->addChild(usernameTextField);

    // 5. add Bang! logo

    auto bangLogoText = ui::Text::create("Bang!", "fonts/arial.ttf", 80);

    if(bangLogoText == nullptr)
    {
        log("Can't initialize bang logo");
    }
    else
    {
        constexpr float x = 0.4f, y = 0.8f;
        log("bangLogoText=(%f, %f)\n", x, y);
        bangLogoText->setPosition(ResolutionUtil::getCorrespondPosition(x, y));
        bangLogoText->setFontSize(70);
    }

    this->addChild(bangLogoText);


    return true;
}


void LoginScene::menuLoginCallback(Ref* pSender)
{
    User::getInstance()->setName(usernameTextField->getString());
    log("Username=%s", User::getInstance()->getName().c_str());
    Director::getInstance()->pushScene(MainMenuScene::createScene());

}
