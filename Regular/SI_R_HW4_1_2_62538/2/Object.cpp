//
// Created by Tegu on 5.6.2021 г..
//

#include "Object.hpp"

Object::Object(const string &name, const string &location, const string &extension) {
    this->name=name;
    this->location=location;
    this->extension=extension;
}

std::string Object::get_name() const {
    return name;
}

std::string Object::get_location() const {
    return location;
}

std::string Object::get_extension() const {
    return extension;
}

std::string Object::get_fullpath() const {
    return location+"/"+name+"."+extension;
}

Object *Object::clone() const {
    return new Object(*this);
}
