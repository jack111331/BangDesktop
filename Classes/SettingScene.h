//
// Created by edge on 2019-09-06.
//

#ifndef BANG_SETTINGSCENE_H
#define BANG_SETTINGSCENE_H

#include "ui/CocosGUI.h"
#include "cocos2d.h"

class SettingScene : public cocos2d::Scene {
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    // back button click callback
    void menuBackCallback(cocos2d::Ref *pSender);

    void sliderCallback(cocos2d::Ref *ref, cocos2d::ui::Slider::EventType type);

    // implement the "static create()" method manually
    CREATE_FUNC(SettingScene);
private:
    cocos2d::ui::Slider *backgroundMusicSlider;
};


#endif //BANG_SETTINGSCENE_H
