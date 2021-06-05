//
// Created by Tegu on 5.6.2021 г..
//

#ifndef INC_2_OBJECT_HPP
#define INC_2_OBJECT_HPP
#include <string>

using namespace std;

class Object {
public:
    Object(const std::string& name, const std::string& location, const std::string& extension);

    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;
};


#endif //INC_2_OBJECT_HPP
