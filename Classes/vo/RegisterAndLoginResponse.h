//
// Created by edge on 2019-09-08.
//

#ifndef BANG_REGISTERANDLOGINRESPONSE_H
#define BANG_REGISTERANDLOGINRESPONSE_H

#include <stdint.h>
#include "nlohmann/json.hpp"
#include <string>
namespace User {
    namespace Response
    {
        struct RegisterAndLoginResponse
        {
            std::string token;
        };

        void to_json(nlohmann::json &j, const RegisterAndLoginResponse &p)
        {
            j = nlohmann::json{{"token", p.token}};
        }

        void from_json(const nlohmann::json &j, RegisterAndLoginResponse &p)
        {
            j.at("token").get_to(p.token);
        }
    }

}

#endif //BANG_REGISTERANDLOGINRESPONSE_H
