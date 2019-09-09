//
// Created by edge on 2019-09-09.
//

#ifndef BANG_CHANGENICKNAMEREQUEST_H
#define BANG_CHANGENICKNAMEREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request
{
    struct ChangeNicknameRequest
    {
        static constexpr int action = 1;
        std::string nickname;
    };

    void to_json(nlohmann::json &j, const ChangeNicknameRequest &p)
    {
        j = nlohmann::json{{"Nick Name", p.nickname},
                           {"Action",  p.action}};
    }

    void from_json(const nlohmann::json &j, ChangeNicknameRequest &p)
    {
        j.at("Nick Name").get_to(p.nickname);
    }
}


#endif //BANG_CHANGENICKNAMEREQUEST_H
