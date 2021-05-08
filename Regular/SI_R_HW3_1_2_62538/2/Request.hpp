//
// Created by Tegu on 8.5.2021 г..
//

#ifndef INC_2_REQUEST_HPP
#define INC_2_REQUEST_HPP
#include <string>

using namespace std;

class Request {
protected:
    static int counter;
    string message;
    string sender;
    int ID;
public:
    Request(const string message="", const string sender="");
    string getMessage()const;
    string getSender()const;
    static int getCount();
    int getID()const;
};


#endif //INC_2_REQUEST_HPP
