//
// Created by edge on 2019-09-29.
//

#include "Network.h"
#include "cocos2d.h"

USING_NS_CC;

Network *Network::instance = nullptr;

Network::Network() {
    this->webSocket = new network::WebSocket();
    webSocket->init(*this, serverAddress);
}
Network *Network::getInstance() {
    if(Network::instance == nullptr) {
        Network::instance = new Network();
    }
    return Network::instance;
}
void Network::send(const std::string & message) {
    webSocket->send(message.c_str());
}

void Network::onOpen(cocos2d::network::WebSocket *ws) {
    if (ws == this->webSocket) {
        log("Connect to server");
    }
}

void Network::onMessage(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::Data &data) {
    if (ws == this->webSocket) {
        log("%s", data.bytes);
    }
}

void Network::onClose(cocos2d::network::WebSocket *ws) {
    if (ws == this->webSocket) {
        this->webSocket = nullptr;
    }
}

void Network::onError(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::ErrorCode &error) {
    log("Error was fired, error code: %d", error);
    if (ws == webSocket) {
        log("an error was fired, code: %d", error);
    }
}