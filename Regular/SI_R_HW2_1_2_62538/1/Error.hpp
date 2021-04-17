//
// Created by Tegu on 17.4.2021 г..
//

#ifndef INC_1_ERROR_HPP
#define INC_1_ERROR_HPP


#include <string>
using  namespace std;
class Error{
private:
    string message;
public:
    Error(const string& message = "");
    string get_message() const;
};


#endif //INC_1_ERROR_HPP
