//
// Created by Tegu on 28.3.2021 г..
//

#include "Error.hpp"

bool Error::hasMessage() const {
    bool flag=0;
    if(message!= nullptr){
        flag=1;
    }
    return flag;
}

const char *Error::getMessage() const {
    return message;
}

ErrorType Error::getType() const {
    return type;
}

Error Error::newNone() {
    Error error=Error();
    return error;
}

Error Error::newBuildFailed(const char *message) {
    Error error=Error(message,ErrorType::BuildFailed);
    return error;
}

Error Error::newWarning(const char *message) {
    Error error=Error(message,ErrorType::Warning);
    return error;
}

Error Error::newFailedAssertion(const char *message) {
    Error error=Error(message,ErrorType::FailedAssertion);
    return error;
}

//_________________________________________

Error::Error() {
    message= nullptr;
    type=ErrorType::None;
}

//Error::~Error() {
//    delete[] message;
//}

Error::Error(const char *_message, ErrorType _type) {
    type=_type;
   // cout<<_message<<endl;
    message=new char[strlen(_message)+1];
    strcpy(message,_message);
  //  cout<<"--"<<message<<endl;
}
