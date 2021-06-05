#include <iostream>
#include "Document.hpp"
#include "KeyValueDatabase.hpp"
void test1(){
    Document temp("temp", "/tmp", "doc");

    temp.write_line("This is an example doc");
    temp.write_line("This is another example line");
    temp.write_line("This is a third example line");
    temp.write_line("This is a forth example line");

    std::cout << temp.read_line() << std::endl; //This is an example doc
    std::cout << temp.read_line() << std::endl; //This is another example line

    std::cout << temp.read_line(3) << std::endl; //This is a third example line
    std::cout << temp.read_line() << std::endl; //This is a forth example line

    std::cout << temp.read_line(1) << std::endl; //This is an example doc
    std::cout << temp.read_line() << std::endl; //This is another example line

}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    test1();
    return 0;
}
