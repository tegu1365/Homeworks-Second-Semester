//
// Created by Tegu on 28.3.2021 г..
//

#include "TestSuite.hpp"

TestSuite::TestSuite() {
    name= nullptr;
}

TestSuite::TestSuite(const string name) {
    this->name=name;
}

void TestSuite::add(const TestCase &_test) {
    testCases.push_back(_test);
}

vector<TestCase> TestSuite::filterPassing() const {
    vector<TestCase> passingTests;
    for(int i=0;i<testCases.size();i++){
        if(testCases[i].isPassing()){
            passingTests.push_back(testCases[i]);
        }
    }
    return passingTests;
}

vector<TestCase> TestSuite::filterFailing() const {
    vector<TestCase> failingTests;
    for(int i=0;i<testCases.size();i++){
        if(!testCases[i].isPassing()){
            failingTests.push_back(testCases[i]);
        }
    }
    return failingTests;
}

vector<TestCase> TestSuite::filterByErrorType(ErrorType _type) const {
    vector<TestCase> thisTypeTests;
    for(int i=0;i<testCases.size();i++){
        if(testCases[i].getErrorType()==_type){
            thisTypeTests.push_back(testCases[i]);
        }
    }
    return thisTypeTests;
}

void TestSuite::removeByErrorType(ErrorType _type) {
    for(int i=0;i<testCases.size();i++){
        if(testCases[i].getErrorType()==_type){
            testCases.erase(testCases.begin()+i);
        }
    }
}

string TestSuite::getName() const {
    return name;
}

void TestSuite::setName(const string & _name) {
    name=_name;
}

void TestSuite::print() const {
    cout<<"Name of Test Suite: "<<name<<endl<<"________________________________________\n";
    for(int i=0;i<testCases.size();i++) {
        testCases[i].print();
        cout<<endl;
    }
}

