//
// Created by Tegu on 5.6.2021 г..
//

#ifndef INC_2_DOCUMENT_HPP
#define INC_2_DOCUMENT_HPP
#include <string>
using namespace std;

class Document {
public:
    Document(const std::string& name, const std::string& location, const std::string& extension);

    void write_line(const std::string& line);

    std::string read_line();
    std::string read_line(const unsigned line);
};


#endif //INC_2_DOCUMENT_HPP
