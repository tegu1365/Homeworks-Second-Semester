//
// Created by Tegu on 17.4.2021 г..
//

#include "Error.hpp"

Error::Error(const string &message) {
    this->message=message;
}

string Error::get_message() const {
    return message;
}
