//
// Created by Tegu on 17.4.2021 г..
//

#ifndef INC_1_OPTIONAL_HPP
#define INC_1_OPTIONAL_HPP
#include "Error.hpp"

template <typename T>
class Optional{
private:
    T value;
    bool flag;
public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;
};

template<typename T>
Optional<T>::Optional() {
    this->value=T();
    flag=true;
}


template<typename T>
Optional<T>::Optional(const T& value) {
    this->value=value;
    flag= false;
}


template<typename T>
bool Optional<T>::is_none() const {
    return flag;
}

template<typename T>
T Optional<T>::get_value() const {
    return value;
}

#endif //INC_1_OPTIONAL_HPP
