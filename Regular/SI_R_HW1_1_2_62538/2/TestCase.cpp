//
// Created by Tegu on 28.3.2021 г..
//

#include "TestCase.hpp"

string TestCase::getName() const {
    return name;
}

bool TestCase::isPassing() const {
    return (error.getType() == ErrorType::Warning || error.getType() == ErrorType::None);
}

bool TestCase::hasError() const {
    return (error.getType() != ErrorType::None);
}

ErrorType TestCase::getErrorType() const {
    return error.getType();
}

string TestCase::getErrorMessage() const {
    return error.getMessage();
}

//____________________________________

TestCase::TestCase() {
    name = "";
    error = Error::newNone();
}

TestCase::TestCase(const string &name, const Error &error) {
    this->name = name;
    this->error = error;
}

void TestCase::print() const {
    cout << "Name of Test Case: " << name << endl;
    error.print();
}
