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

bool Object::operator!=(const Comparable *other) const {
    return false;
}

bool Object::operator==(const Comparable *other) const {
    return false;
}

string Object::to_string() const {
    return std::string();
}

void Object::from_string(const string& str) {

}

string Object::debug_print() const {
    return std::string();
}
