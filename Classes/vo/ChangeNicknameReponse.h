//
// Created by edge on 2019-09-09.
//

#ifndef BANG_CHANGENICKNAMERESPONSE_H
#define BANG_CHANGENICKNAMERESPONSE_H

#include <string>
#include "nlohmann/json.hpp"

namespace Response {
    struct ChangeNicknameResponse {
        bool success;
    };

    void to_json(nlohmann::json &j, const ChangeNicknameResponse &p) {
        j = nlohmann::json{{"success", p.success}};
    }

    void from_json(const nlohmann::json &j, ChangeNicknameResponse &p) {
        j.at("success").get_to(p.success);
    }
}


#endif //BANG_CHANGENICKNAMEREQUEST_H
