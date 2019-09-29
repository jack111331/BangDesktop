//
// Created by edge on 2019-09-08.
//

#ifndef BANG_REGISTERANDLOGINREQUEST_H
#define BANG_REGISTERANDLOGINREQUEST_H

#include <stdint.h>
#include "nlohmann/json.hpp"

namespace Request {
    struct RegisterAndLoginRequest {
        uint32_t userId;
    };

    void to_json(nlohmann::json &j, const RegisterAndLoginRequest &p) {
        j = nlohmann::json{{"userId", p.userId}};
    }

    void from_json(const nlohmann::json &j, RegisterAndLoginRequest &p) {
        j.at("userId").get_to(p.userId);
    }
}

#endif //BANG_REGISTERANDLOGINREQUEST_H
