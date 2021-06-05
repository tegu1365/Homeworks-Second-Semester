//
// Created by Tegu on 5.6.2021 г..
//

#ifndef INC_2_OBJECT_HPP
#define INC_2_OBJECT_HPP
#include <string>
#include "Serializable.hpp"
#include "Debug.hpp"
#include "Comparable.hpp"
using namespace std;

class Object: public Debug, public Comparable, public Serializable {
private:
    string name;
    string location;
    string extension;
public:
    Object(const std::string& name, const std::string& location, const std::string& extension);

    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;

    bool operator!=(const Comparable* other)const;
    virtual bool operator==(const Comparable* other)const;
    string to_string()const;
    virtual void from_string(const string str);
    string debug_print()const;

    Object* clone();
};


#endif //INC_2_OBJECT_HPP
