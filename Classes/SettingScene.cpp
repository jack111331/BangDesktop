//
// Created by edge on 2019-09-06.
//

#include "SettingScene.h"
#include "ui/CocosGUI.h"

#include "SimpleAudioEngine.h"
#include "ResolutionUtil.h"

USING_NS_CC;

Scene *SettingScene::createScene() {
    return SettingScene::create();

}

// on "init" you need to initialize your instance
bool SettingScene::init() {
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    // 2. cover background image
    auto backgroundImage = ui::ImageView::create("background.png");
    if(backgroundImage) {
        this->addChild(backgroundImage);
    } else {
        log("[SettingScene] Can't initialize background image.");
    }

    // 3 add back button item
    auto backButton = ui::Button::create("login-btn.png", "login-btn-click.png");
    if (backButton) {
        backButton->setPosition(ResolutionUtil::getCorrespondPosition(0.6f, 0.2f));

        backButton->setTitleFontSize(40);
        backButton->setTitleText("Back");

        backButton->addClickEventListener(CC_CALLBACK_1(SettingScene::menuBackCallback, this));
        this->addChild(backButton);
    } else {
        log("[SettingScene] Can't initialize back button");
    }

    // 4. add background music slider label
    auto backgroundMusicText = ui::Text::create("BGM Volume", "fonts/arial.ttf", 40);
    if (backgroundMusicText) {
        backgroundMusicText->setPosition(ResolutionUtil::getCorrespondPosition(0.3f, 0.7f));
        this->addChild(backgroundMusicText);
    } else {
        log("[SettingScene] Can't initialize background music slider text");
    }

    // 5. add background music slider
    this->backgroundMusicSlider = ui::Slider::create("mute-bg.png", "mute-thumb.png");
    if (backgroundMusicSlider) {
        backgroundMusicSlider->setPercent(
                CocosDenshion::SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() * 100.0);
        backgroundMusicSlider->setPosition(ResolutionUtil::getCorrespondPosition(0.6f, 0.7f));
        backgroundMusicSlider->setScale(0.3f);
        backgroundMusicSlider->addEventListener(CC_CALLBACK_2(SettingScene::sliderCallback, this));
        this->addChild(backgroundMusicSlider);
    } else {
        log("[SettingScene] Can't initialize background music slider");
    }

    return true;
}


void SettingScene::menuBackCallback(Ref *pSender) {
    Director::getInstance()->popScene();
}


void SettingScene::sliderCallback(cocos2d::Ref *ref, ui::Slider::EventType type) {
    switch (type) {
        case ui::Slider::EventType::ON_PERCENTAGE_CHANGED: {
            int percent = backgroundMusicSlider->getPercent();
            auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
            audio->setBackgroundMusicVolume((float) percent / 100.0);
            log("slider percent = %d", percent);
            break;
        }
        default:
            break;
    }

}