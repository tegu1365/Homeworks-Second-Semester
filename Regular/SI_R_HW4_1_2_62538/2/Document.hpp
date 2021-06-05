//
// Created by Tegu on 5.6.2021 г..
//

#ifndef INC_2_DOCUMENT_HPP
#define INC_2_DOCUMENT_HPP
#include <string>
#include <vector>
#include "Object.hpp"
using namespace std;

class Document: public Object {
private:
    vector<string> lines;
    int lastRead;
public:
    Document(const std::string& name, const std::string& location, const std::string& extension);

    void write_line(const std::string& line);

    std::string read_line();
    std::string read_line(const unsigned line);

    bool operator!=(const Document* other)const;
    bool operator==(const Document* other)const;

    bool operator!=(const Comparable* other)const;
    bool operator==(const Comparable* other)const;
    string to_string()const;
    void from_string(const string& str);
    string debug_print()const;
};


#endif //INC_2_DOCUMENT_HPP
