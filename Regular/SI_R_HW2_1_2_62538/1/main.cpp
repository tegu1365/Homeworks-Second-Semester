#include <iostream>
#include <assert.h>
#include "Result.hpp"
using namespace std;

Result<int> divide(const int first, const int second) {
    if (second == 0) {
        return Result<int>("Division by zero !");
    }
    return Result<int>(first / second);
}

void runTest(){
    Error er=Error();
    assert(er.get_message()=="");

    Error er1=Error("Fail");
    assert(er1.get_message()=="Fail");

    Optional<int> null_withInt=Optional<int>();
    assert(null_withInt.is_none()==true);

    Optional<int> withInt=Optional<int>(23);
    assert(withInt.is_none()==false);
    assert(withInt.get_value()==23);

    Optional<Error> null_withError=Optional<Error>();
    assert(null_withError.is_none()==true);
    assert(null_withError.get_value().get_message()=="");

    Optional<Error> withError=Optional<Error>(er1.get_message());
    assert(withError.is_none()== false);
    assert(withError.get_value().get_message()==er1.get_message());

    Result<int> k=Result<int>(23);
    assert(k.get_result().is_none()== false);
    assert(k.get_result().get_value()==23);
    assert(k.get_error().is_none()==true);
    assert(k.get_error().get_value().get_message()=="");
    assert(!(k==Error()));
    assert(k==double());

    Result<int> reEr=Result<int>("Fail");
    assert(reEr.get_result().is_none()== true);
    assert(reEr.get_result().get_value()==int());
    assert(reEr.get_error().is_none()== false);
    assert(reEr.get_error().get_value().get_message()=="Fail");
    assert(reEr==Error());
    assert(!(reEr==int()));

}

int main() {
    runTest();
    cout<<"End"<<endl;
    Result<int> first = divide(5, 2);

    cout << "5 / 2 = ";
    if (first == Error()) {
        Error error = first.get_error().get_value();
        cout << error.get_message() << endl;
    }
    else {
        cout << first.get_result().get_value() << endl;
    }

    Result<int> second = divide(8, 0);
    cout << "8 / 0 = ";
    if (second == Error()) {
        Error error = second.get_error().get_value();
        cout << error.get_message() << std::endl;
    }
    else {
        cout << second.get_result().get_value() << std::endl;
    }

    if(second==int()) {
        cout << second.get_result().get_value() << std::endl;
    }else{
        Error error = second.get_error().get_value();
        cout << error.get_message() << std::endl;
    }
}