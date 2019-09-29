//
// Created by edge on 2019-09-09.
//

#ifndef BANG_CHANGENICKNAMEREQUEST_H
#define BANG_CHANGENICKNAMEREQUEST_H

#include <string>
#include "nlohmann/json.hpp"
namespace User {
    namespace Request {
        struct ChangeNicknameRequest {
            std::string token;
            std::string nickname;
        };

        void to_json(nlohmann::json &j, const ChangeNicknameRequest &p) {
            j = nlohmann::json{{"token",    p.token},
                               {"nickname", p.nickname}};
        }

        void from_json(const nlohmann::json &j, ChangeNicknameRequest &p) {
            j.at("token").get_to(p.token);
            j.at("nickname").get_to(p.nickname);
        }
    }

}


#endif //BANG_CHANGENICKNAMEREQUEST_H
