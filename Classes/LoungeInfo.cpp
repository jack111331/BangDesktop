//
// Created by edge on 2019-09-05.
//

#include "LoungeInfo.h"

LoungeInfo::LoungeInfo(uint32_t id, bool ready) : id(id), ready(ready)
{

}


uint32_t LoungeInfo::getId() const {
    return id;
}

bool LoungeInfo::isReady() const {
    return ready;
}

void LoungeInfo::setId(uint32_t id) {
    LoungeInfo::id = id;
}

void LoungeInfo::setReady(bool ready) {
    LoungeInfo::ready = ready;
}
