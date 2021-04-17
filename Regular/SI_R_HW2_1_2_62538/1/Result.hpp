//
// Created by Tegu on 17.4.2021 г..
//

#ifndef INC_1_RESULT_HPP
#define INC_1_RESULT_HPP


#include "Error.hpp"
#include "Optional.hpp"

template<typename T>
class Result {
private:
    Optional<T> result;
    Optional<Error> error;
    bool is_error;
public:
    Result();
    Result(const T &result);
    Result(const std::string &error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;
    bool operator==(const Error& _rhs) const;
    bool operator==(const T& _rhs) const;
};

template<typename T>
Result<T>::Result() {
    result=Optional<T>();
    error=Optional<Error>();
    is_error= false;
}

template<typename T>
Result<T>::Result(const T &result) {
    this->result=Optional<T>(result);
    error=Optional<Error>();
    is_error=false;
}

template<typename T>
Result<T>::Result(const string &error_message) {
    error=Optional<Error>(Error(error_message));
    result=Optional<T>();
    is_error=true;
}

template<typename T>
Optional<T> Result<T>::get_result() const {
   return result;
}

template<typename T>
Optional<Error> Result<T>::get_error() const {
    return error;
}


template<typename T>
bool Result<T>::operator==(const Error &_rhs) const {
    return this->is_error;
}

template<typename T>
bool Result<T>::operator==(const T &_rhs) const {
    return !(this->is_error);
};

#endif //INC_1_RESULT_HPP
