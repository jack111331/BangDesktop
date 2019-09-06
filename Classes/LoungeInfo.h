//
// Created by edge on 2019-09-05.
//

#ifndef BANG_LOUNGEINFO_H
#define BANG_LOUNGEINFO_H


#include <cstdint>

class LoungeInfo {
public:

private:
    uint32_t id;
    bool ready;
public:
    LoungeInfo(uint32_t id, bool ready);
    uint32_t getId() const;
    bool isReady() const;
    void setId(uint32_t id);
    void setReady(bool ready);
};


#endif //BANG_LOUNGEINFO_H
