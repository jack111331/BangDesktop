#include "ui/CocosGUI.h"
#include "LoginScene.h"
#include "MainMenuScene.h"
#include "DebugScene.h"
#include "GameUser.h"
#include "ResolutionUtil.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace User;

Scene *LoginScene::createScene() {
    return LoginScene::create();

}

// on "init" you need to initialize your instance
bool LoginScene::init() {
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    // 2. cover background image
    auto backgroundImage = ui::ImageView::create("background.png");
    if (backgroundImage) {
        this->addChild(backgroundImage);
    } else {
        log("[LoginScene] Can't initialize background image.");
    }

    // 3. add login button item
    auto loginButton = ui::Button::create("login-btn.png", "login-btn-click.png");
    if (loginButton) {
        loginButton->setPosition(ResolutionUtil::getCorrespondPosition(0.7f, 0.45f));

        loginButton->setTitleFontSize(40);
        loginButton->setTitleText("Log in");

        // Let button match it's word size
        auto loginButtonTitleSize = loginButton->getTitleRenderer()->getContentSize();
        loginButton->ignoreContentAdaptWithSize(false);
        loginButton->setContentSize(Size(loginButtonTitleSize.width * 3.0f, loginButtonTitleSize.height * 1.7f));

        loginButton->addClickEventListener(CC_CALLBACK_1(LoginScene::menuLoginCallback, this));
        this->addChild(loginButton);
    } else {
        log("[LoginScene] Can't initialize login button");
    }

    // 4. add username textField

    // 4.a add username textfield background
    auto usernameTextFieldBackground = ui::ImageView::create("username-input.png");
    if (usernameTextFieldBackground) {
        usernameTextFieldBackground->ignoreContentAdaptWithSize(false);
        usernameTextFieldBackground->setContentSize(ResolutionUtil::getCorrespondSize(0.30f, 0.05f));
        usernameTextFieldBackground->setPosition(ResolutionUtil::getCorrespondPosition(0.4f, 0.55f));
        this->addChild(usernameTextFieldBackground);
    } else {
        log("[LoginScene] Can't initialize username textfield background");
    }

    // 4.b add username textField item
    this->usernameTextField = TextFieldTTF::textFieldWithPlaceHolder("Username", "fonts/arial.ttf", 40);
    if (usernameTextField) {
        usernameTextField->setPosition(ResolutionUtil::getCorrespondPosition(0.4f, 0.55f));
        auto listener = EventListenerTouchOneByOne::create();
        listener->onTouchBegan = [this](Touch *touch, Event *event) {
            if (this->usernameTextField->getBoundingBox().containsPoint(touch->getLocation())) {
                this->usernameTextField->attachWithIME();
            } else {
                this->usernameTextField->detachWithIME();
            }
            return false;
        };
        Director::getInstance()->getEventDispatcher()->
                addEventListenerWithSceneGraphPriority(listener, usernameTextField);
        usernameTextField->setCursorEnabled(true);
        usernameTextField->setTextColor(Color4B::BLACK);
        this->addChild(usernameTextField);
    } else {
        log("[LoginScene] Can't initialize username textfield");
    }

    // 5. add password textField

    // 5.a add password textfield background
    auto passwordTextFieldBackground = ui::ImageView::create("username-input.png");
    if (passwordTextFieldBackground) {
        passwordTextFieldBackground->ignoreContentAdaptWithSize(false);
        passwordTextFieldBackground->setContentSize(ResolutionUtil::getCorrespondSize(0.30f, 0.05f));
        passwordTextFieldBackground->setPosition(ResolutionUtil::getCorrespondPosition(0.4f, 0.45f));
        this->addChild(passwordTextFieldBackground);
    } else {
        log("[LoginScene] Can't initialize password textfield background");
    }

    // 5.b add password textField item
    this->passwordTextField = TextFieldTTF::textFieldWithPlaceHolder("Password", "fonts/arial.ttf", 40);
    if (passwordTextField) {
        passwordTextField->setPosition(ResolutionUtil::getCorrespondPosition(0.4f, 0.45f));
        auto listener = EventListenerTouchOneByOne::create();
        listener->onTouchBegan = [this](Touch *touch, Event *event) {
            if (this->passwordTextField->getBoundingBox().containsPoint(touch->getLocation())) {
                this->passwordTextField->attachWithIME();
            } else {
                this->passwordTextField->detachWithIME();
            }
            return false;
        };
        Director::getInstance()->getEventDispatcher()->
                addEventListenerWithSceneGraphPriority(listener, passwordTextField);
        passwordTextField->setCursorEnabled(true);
        passwordTextField->setTextColor(Color4B::BLACK);
        this->addChild(passwordTextField);
    } else {
        log("[LoginScene] Can't initialize password textfield");
    }

    // 6. add Bang! logo
    auto bangLogoText = ui::Text::create("Bang!", "fonts/arial.ttf", 70);
    if (bangLogoText) {
        bangLogoText->setPosition(ResolutionUtil::getCorrespondPosition(0.4f, 0.8f));
        bangLogoText->setColor(Color3B::BLACK);
        this->addChild(bangLogoText);
    } else {
        log("[LoginScene] Can't initialize bang logo");
    }

    // 7. add debug button item
    auto debugButton = ui::Button::create("login-btn.png", "login-btn-click.png");
    if (debugButton) {
        debugButton->setPosition(ResolutionUtil::getCorrespondPosition(0.7f, 0.1f));

        debugButton->setTitleFontSize(40);
        debugButton->setTitleText("Debug");

        // Let button match it's word size
        auto loginButtonTitleSize = debugButton->getTitleRenderer()->getContentSize();
        debugButton->ignoreContentAdaptWithSize(false);
        debugButton->setContentSize(Size(loginButtonTitleSize.width * 3.0f, loginButtonTitleSize.height * 1.7f));

        debugButton->addClickEventListener(CC_CALLBACK_1(LoginScene::menuDebugCallback, this));
        this->addChild(debugButton);
    } else {
        log("[LoginScene] Can't initialize login button");
    }
    return true;
}


void LoginScene::menuLoginCallback(Ref *pSender) {
    GameUser::getInstance()->setName(usernameTextField->getString());
    log("[LoginScene] Username=%s", GameUser::getInstance()->getName().c_str());
    Director::getInstance()->pushScene(MainMenuScene::createScene());

}
void LoginScene::menuDebugCallback(Ref *pSender) {
    Director::getInstance()->pushScene(DebugScene::createScene());

}

void LoginScene::onEnter() {
    Scene::onEnter();
    Director::getInstance()->setNotificationNode(nullptr);
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    if (audio->isBackgroundMusicPlaying()) {
        audio->stopBackgroundMusic(true);
    }

}
