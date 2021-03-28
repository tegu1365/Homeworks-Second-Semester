//
// Created by Tegu on 28.3.2021 г..
//

#ifndef INC_2_TESTCASE_HPP
#define INC_2_TESTCASE_HPP


#pragma once
#include <string>

#include "Error.hpp"

/// TestCase represents the result of a test that has been
/// executed. It may be passing or failing and in the case
/// of a failing test, there's some Error different from None
class TestCase {
    /// Feel free to add additional private/public methods/fields
    string name;
    Error error;
public:
    /// Constructor we'll need to create a new TestCase
    TestCase();
    TestCase(const string& name, const Error& error);

    /// Retrieve the name of the TestCase
    string getName() const;

    /// Check if the test is passing or failing. A test is passing if
    /// its Error is None or Warning
    bool isPassing() const;

    /// Check if the test has an Error. A test has an error if its
    /// Error is different from None. This is a method intended to be
    /// used before calling getErrorType() or getErrorMessage()
    bool hasError() const;

    /// Retrieve the type of Error this test has (it could be None)
    ErrorType getErrorType() const;

    /// Retrieve the message of the error if Error has one,
    /// otherwise return an empty string
    string getErrorMessage() const;

    void print()const;
};

#endif //INC_2_TESTCASE_HPP
