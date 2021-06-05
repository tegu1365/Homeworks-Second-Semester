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
    cout<<"__________________________________\n";
    Document temp2=Document();
    string str="temp\n/tmp\ndoc\nThis is an example doc\nThis is another example line\nThis is a third example line\nThis is a forth example line\n";
    temp2.from_string(str);

    std::cout << temp2.read_line() << std::endl; //This is an example doc
    std::cout << temp2.read_line() << std::endl; //This is another example line

    if(temp!=&temp2){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}

void test2(){
    KeyValueDatabase key=KeyValueDatabase("temp", "/tmp", "doc");
    key.add_entry({"jsu",2});
    key.add_entry({"dre",4});
    key.add_entry({"fre",3});
    key.add_entry({"hyt",5});
    cout<<key.to_string()<<endl;
    string str="temp\n/tmp\ndoc\njsu:2\ndre:4\nfre:3\nhyt:5\n";
    KeyValueDatabase key2=KeyValueDatabase();
    key2.from_string(str);
    cout<<key2.get_value("fre")<<endl;

    if(key!=&key2){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    test1();
    cout<<"____________________________________________________________\n";
    test2();
    return 0;
}
