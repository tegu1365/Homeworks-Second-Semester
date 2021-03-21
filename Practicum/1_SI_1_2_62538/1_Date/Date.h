/**
*	Solution to homework assignment 1
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021
*
*	@author Teodora Dimitrova Petkova
*	@idnumber 62538
*	@task 1
*	@compiler VC
*/

#ifndef INC_1_DATE_DATE_H
#define INC_1_DATE_DATE_H

#include <iostream>
using namespace std;

class Date {
private:
    unsigned short day;
    unsigned short month;
    unsigned int year;
    int numOfTheDay();
    Date numOfTheDayToDate(int days, unsigned int year);
    bool validateDate(unsigned short day,unsigned short month,unsigned int year);
    bool yearIsLeap(unsigned int year);
public:
    Date();
    Date(unsigned short _day,unsigned short _month,unsigned int _year);
    void addDays(int n);
    void removeDays(int n);
    bool isLeapYear();
    int daysToXmas();
    int daysToNewYear();
    int daysToDate(Date _date);
    bool isLaterThen(Date _date);
    void print()const;
};


#endif //INC_1_DATE_DATE_H
