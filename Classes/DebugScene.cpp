//
// Created by edge on 2019-09-21.
//

#include "ui/CocosGUI.h"
#include "DebugScene.h"
#include "Network.h"

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
    Network * userNetwork = Network::getInstance();
    log("Hello kind echo server :D");
    userNetwork->send("Hello kind echo server :D");


    return true;
}