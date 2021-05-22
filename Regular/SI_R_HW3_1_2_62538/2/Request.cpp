//
// Created by Tegu on 8.5.2021 г..
//

#include "Request.hpp"

unsigned int Request::counter = 0;

Request::Request(const string &message, const string &sender) {
    this->message = message;
    this->sender = sender;
    counter++;
    this->ID = counter;
}

string Request::getMessage() const {
    return message;
}

string Request::getSender() const {
    return sender;
}

unsigned int Request::getID() const {
    return ID;
}

unsigned int Request::getCount() {
    return counter;
}
