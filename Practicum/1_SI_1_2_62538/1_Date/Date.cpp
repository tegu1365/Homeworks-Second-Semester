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


#include "Date.h"

Date::Date() {
    //01.01.2000
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(unsigned short _day, unsigned short _month, unsigned int _year) {
    if (validateDate(_day, _month, _year)) {
        day = _day;
        month = _month;
        year = _year;
    } else {
        cout << "Unvalide Date";
    }
}

void Date::addDays(int n) {
    int k = this->numOfTheDay();
    int numOfTheNewDay = n + k;
    if(this->isLeapYear()){
        if(numOfTheNewDay-366>0){
            year++;
            numOfTheNewDay-=366;
        }
    }else{
        if(numOfTheNewDay-365>0){
            year++;
            numOfTheNewDay-=365;
        }
    }
    Date newDate=numOfTheDayToDate(numOfTheNewDay,year);
    day=newDate.day;
    month=newDate.month;
    year=newDate.year;
}

void Date::removeDays(int n) {
    int k = this->numOfTheDay();
    int numOfTheNewDay =k-n;
    if(numOfTheNewDay<0){
        year--;
        if(this->isLeapYear()){
            numOfTheNewDay=366+numOfTheNewDay;
        }else {
            numOfTheNewDay=365+numOfTheNewDay;
        }
    }
    Date newDate=numOfTheDayToDate(numOfTheNewDay,year);
    day=newDate.day;
    month=newDate.month;
    year=newDate.year;
}

bool Date::isLeapYear() {
    return yearIsLeap(year);
}

int Date::numOfTheDay() {
    //return which day of the year is
    int num = day;
    for (int i = 1; i < month; i++) {
        switch (i) {
            case 2:
                if (yearIsLeap(year)) {
                    num += 29;
                } else {
                    num += 28;
                }
                break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                num += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                num += 30;
                break;
        }
    }
    //cout<<"Num of the day: "<<num<<endl;
    return num;
}


int Date::daysToXmas() {
    const int numOfDaysBetweenNYandXmas = 7;
    int num = this->daysToNewYear() - numOfDaysBetweenNYandXmas;
    //cout<<"Days in X-mas: "<<num<<endl;
    if (num < 0) {
        Date d = Date(1, 1, year + 1);
        num = d.daysToXmas() + (num + numOfDaysBetweenNYandXmas);
    }
    return num;
}

int Date::daysToNewYear() {
    if (this->isLeapYear()) {
        return 366 - this->numOfTheDay() + 1;
    }
    return 365 - this->numOfTheDay() + 1;
}

int Date::daysToDate(Date _date) {
    int daysLeft = 0;
    if (this->isLaterThen(_date)) {
        //cout<<"The day is already past\n";
        return -1;
    }
    if(year==_date.year){
        daysLeft=_date.numOfTheDay()-this->numOfTheDay();
    }else{
        daysLeft= this->daysToNewYear()+_date.numOfTheDay()-1;//in both func we take the 01.01 of _date.year
        int numOfYearsBetween=_date.year-year;
        for(int i=1;i<numOfYearsBetween;i++){
            if(yearIsLeap(year+i)){
                daysLeft+=366;
            }else{
                daysLeft+=365;
            }
        }
    }
    return daysLeft;
}

bool Date::isLaterThen(Date _date) {
    if (year > _date.year) return true;
    if (year == _date.year) {
        if (month > _date.month)return true;
        if (month == _date.month) {
            if (day > _date.day)return true;
        }
    }
    return false;
}

void Date::print() const {
    if (day < 10) {
        cout << "0";
    }
    cout << day << ".";
    if (month < 10) {
        cout << 0;
    }
    cout << month << "." << year << endl;
}

bool Date::validateDate(unsigned short day, unsigned short month, unsigned int year) {
    switch (month) {
        case 2:
            if (yearIsLeap(year)) {
                //cout<<"Leap Year";
                if (day > 29)return false;
            } else {
                if (day > 28)return false;
            }
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day > 31) return false;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30) return false;
            break;
    }

    return true;
}

bool Date::yearIsLeap(unsigned int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
        } else {
            return true;
        }
    }
    return false;
}

Date Date::numOfTheDayToDate(int days, unsigned int year) {
    Date date = Date(1, 1, year);
    while (days != 0) {
        switch (date.month) {
            case 2:
                if (yearIsLeap(year)) {
                    if (days > 29){
                        days=days-29;
                        date.month++;
                    }else{
                        date.day=days;
                        date.month=2;
                        days=0;
                    }
                } else {
                    if (days > 28){
                        days=days-28;
                        date.month++;
                    }else{
                        date.day=days;
                        days=0;
                    }
                }
                break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (days > 31){
                    days=days-31;
                    date.month++;
                }else{
                    date.day=days;
                    days=0;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (days > 30){
                    days=days-30;
                    date.month++;
                }else{
                    date.day=days;
                    days=0;
                }
                break;
        }

    }
    return date;
}

