//
// Created by Tegu on 5.6.2021 г..
//

#include <stdexcept>
#include "Document.hpp"

Document::Document(const string &name, const string &location, const string &extension) : Object(name, location,
                                                                                                 extension) {
lastRead=-1;
}

void Document::write_line(const string &line) {
    lines.push_back(line);
}

std::string Document::read_line() {
    int lineToBeReadNow=lastRead+1;
    int size=lines.size();
    if(lineToBeReadNow<size){
        lastRead++;
        return lines[lineToBeReadNow];
    }
    throw out_of_range("");
}

std::string Document::read_line(const unsigned int line) {
    if(line-1<lines.size()&&line!=0){
        lastRead=line-1;
        return lines[line-1];
    }
    throw out_of_range("");
}

bool Document::operator!=(const Document *other) const {
    return !(this==other);
}

bool Document::operator==(const Document *other) const {
    if(this->lines.size()==other->lines.size()){
        for(size_t i=0;i<lines.size();i++){
            if(this->lines[i]!=other->lines[i]){
                return false;
            }
        }
    } else{
        return false;
    }
    return true;
}

bool Document::operator!=(const Comparable *other) const {
    return Document::operator!=((Document*)other);
}

bool Document::operator==(const Comparable *other) const {
    return Document::operator!=((Document*)other);
}

string Document::to_string() const {
    string result=name+"\n"+location+"\n"+extension+"\n";
    for(auto x:lines){
        result.append(x+"\n");
    }
    return result;
}

void Document::from_string(const string& str) {
    vector<string> lines;
    string current = "";
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '\n') {
            lines.push_back(current);
            current = "";
        } else {
            char a = str[i];
            current.push_back(a);
        }
    }
    this->location=lines[1];
    this->name=lines[0];
    this->extension=lines[2];
    for (size_t i = 3; i < lines.size(); i++) {
        this->lines.push_back(lines[i]);
    }
}

string Document::debug_print() const {
    string result="";
    int i=1;
    for(auto x:lines){
        result.append("Line "+std::to_string(i)+":"+x+"\n");
        i++;
    }
    return result;
}
