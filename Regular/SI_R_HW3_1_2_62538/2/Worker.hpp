//
// Created by Tegu on 8.5.2021 г..
//

#ifndef INC_2_WORKER_HPP
#define INC_2_WORKER_HPP
#include <string>
using  namespace std;

class Worker {
protected:
    string name;
    double salary;
public:
    Worker(const string& name= nullptr ,const double salary=0.0);
    string getName()const;
    double getSalary()const;
    void setInitialSalary(const double amount);

};


#endif //INC_2_WORKER_HPP
