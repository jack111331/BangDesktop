//
// Created by edge on 2019-09-06.
//

#include "SettingScene.h"
#include "ui/CocosGUI.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene *SettingScene::createScene()
{
    return SettingScene::create();

}

// on "init" you need to initialize your instance
bool SettingScene::init()
{
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    Vector<MenuItem *> menuItemLists;

    // 2. cover background image
    auto backgroundImage = Sprite::create("background.png");
    this->addChild(backgroundImage);

    // 3 add back button item
    auto backButton = ui::Button::create("login-btn.png", "login-btn-click.png");

    if (backButton == nullptr)
    {
        log("Can't initialize back button");
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

        backButton->addClickEventListener(CC_CALLBACK_1(SettingScene::menuBackCallback, this));
    }

    this->addChild(backButton);

    // 4. add background music slider
    this->backgroundMusicSlider = ui::Slider::create("mute-bg.png", "mute-thumb.png");

    if(backgroundMusicSlider == nullptr)
    {
        log("Can't initialize background Music Slider");
    }
    else
    {
        //Position
        float x = 500.0f;
        float y = 400.0f;
        auto audio = CocosDenshion::SimpleAudioEngine::getInstance();

        backgroundMusicSlider->setPercent(audio->getBackgroundMusicVolume()*100.0);
        backgroundMusicSlider->setPosition((Vec2){x, y});

        backgroundMusicSlider->addEventListener(CC_CALLBACK_2(SettingScene::sliderCallback, this));
    }

    this->addChild(backgroundMusicSlider);

    return true;
}


void SettingScene::menuBackCallback(Ref *pSender)
{
    Director::getInstance()->popScene();
}


void SettingScene::sliderCallback(cocos2d::Ref * ref, ui::Slider::EventType type)
{
    switch (type)
    {
        case ui::Slider::EventType::ON_PERCENTAGE_CHANGED:
        {
            int percent = backgroundMusicSlider->getPercent();
            auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
            audio->setBackgroundMusicVolume((float)percent/100.0);
            log("slider percent = %d", percent);
        }
            break;
        default:
            break;
    }

}