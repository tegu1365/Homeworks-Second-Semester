//
// Created by Tegu on 8.5.2021 г..
//

#ifndef INC_2_LEAVINGREQUEST_HPP
#define INC_2_LEAVINGREQUEST_HPP
#include "Request.hpp"

class LeavingRequest: public Request {
public:
    LeavingRequest(const string& sender);
};


#endif //INC_2_LEAVINGREQUEST_HPP
