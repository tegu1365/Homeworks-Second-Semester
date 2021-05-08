//
// Created by Tegu on 8.5.2021 г..
//

#include "Request.hpp"

int Request::counter=0;

Request::Request(const string& message, const string& sender) {
    this->message=message;
    this->sender=sender;
    Request::counter++;
    this->ID=counter;
}

string Request::getMessage() const {
    return message;
}

string Request::getSender() const {
    return sender;
}

int Request::getID() const {
    return ID;
}

int Request::getCount() {
    return counter;
}
