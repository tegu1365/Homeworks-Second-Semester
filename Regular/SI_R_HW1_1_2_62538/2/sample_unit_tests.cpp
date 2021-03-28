#include <assert.h>

#include <cstring>
#include <iostream>

#include "Error.hpp"
#include "TestCase.hpp"
#include "TestSuite.hpp"

void runTests() {
    Error errNone = Error::newNone();
    assert(errNone.getType() == ErrorType::None);
    assert(errNone.hasMessage() == false);

    Error errBuild = Error::newBuildFailed("Failed to build Homework5");
    assert(errBuild.getType() == ErrorType::BuildFailed);
    assert(errBuild.hasMessage() == true);
    assert(strcmp(errBuild.getMessage(), "Failed to build Homework5") == 0);

    Error errTest=Error::newFailedAssertion("");
    assert(errTest.hasMessage()==true);

    TestCase testCaseNone("Passing test", errNone);
    assert(testCaseNone.getErrorType() == ErrorType::None);
    assert(testCaseNone.hasError() == false);
    assert(testCaseNone.isPassing() == true);

    TestCase testCaseFailed("Failing test", Error::newFailedAssertion("Failed on Error::getType"));
    assert(testCaseFailed.getErrorMessage() == std::string("Failed on Error::getType"));
    assert(testCaseFailed.hasError() == true);
    assert(testCaseFailed.isPassing() == false);

    TestSuite suite("Suite 1");
    suite.add(testCaseNone);
    suite.add(testCaseNone);
    suite.add(testCaseFailed);
    assert(suite.filterPassing().size() == 2);
    assert(suite.filterFailing().size() == 1);
    assert(suite.filterByErrorType(ErrorType::None).size() == 2);
    assert(suite.getName() != string("Suite 2"));
}

int main() {
    runTests();
    std::cout << "Success!\n";

//    Error errNone = Error::newNone();
//    Error errBuild = Error::newBuildFailed("Failed to build Homework5");
//
//    TestCase testCaseNone("Passing test", errNone);
//    TestCase testCaseFailed("Failing test", Error::newFailedAssertion("Failed on Error::getType"));
//    TestCase testErrBuild("Failed Build",errBuild);
//    TestSuite suite("Suite 1");
//
//    suite.add(testCaseFailed);
//    suite.add(testErrBuild);
//    suite.add(testCaseNone);
//    suite.add(testCaseNone);
//
//    suite.print();
}