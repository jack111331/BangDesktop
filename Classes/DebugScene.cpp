//
// Created by edge on 2019-09-21.
//

#include "ui/CocosGUI.h"
#include "DebugScene.h"
#include "PlayerLayer.h"
#include "ResolutionUtil.h"

USING_NS_CC;

Scene *DebugScene::createScene() {
    return DebugScene::create();

}

// on "init" you need to initialize your instance
bool DebugScene::init() {
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    return true;
}