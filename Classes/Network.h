//
// Created by edge on 2019-09-29.
//

#ifndef BANG_NETWORK_H
#define BANG_NETWORK_H

#include "network/WebSocket.h"
#include <string>

class Network : public cocos2d::network::WebSocket::Delegate {
public:
    Network();

    static Network *getInstance();

    void send(const std::string &message);

    virtual void onOpen(cocos2d::network::WebSocket *ws);

    virtual void onMessage(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::Data &data);

    virtual void onClose(cocos2d::network::WebSocket *ws);

    virtual void onError(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::ErrorCode &error);

private:
    static Network *instance;
    cocos2d::network::WebSocket *webSocket;
    const std::string serverAddress = "ws://echo.websocket.org"; // ws://127.0.0.1
};


#endif //BANG_NETWORK_H
