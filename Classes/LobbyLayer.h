#ifndef __LOBBY_LAYER_H__
#define __LOBBY_LAYER_H__

#include "ui/CocosGUI.h"
#include "cocos2d.h"

class LobbyLayer : public cocos2d::Layer {
public:
    LobbyLayer();

    virtual bool init();

    // ready button click callback
    void menuReadyCallback(cocos2d::Ref *pSender);

    // exit button click callback
    void menuStartCallback(cocos2d::Ref *pSender);

    // layer touch callback
    void layerTouchCallback(cocos2d::Ref * pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(LobbyLayer);

    ~LobbyLayer();

private:
    cocos2d::ui::Button *readyButton;
    bool ready = false;
};

#endif // __LOBBY_LAYER_H__
