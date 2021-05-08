//
// Created by Tegu on 8.5.2021 г..
//

#ifndef INC_2_TEAMLEAD_HPP
#define INC_2_TEAMLEAD_HPP

//This is the ugliest code that I have wrote for the last 2 years
//WHY?

#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

#include <iostream>
#include <vector>
using namespace std;

class TeamLead;

class Developer{
protected:
    string name;
    double salary;
    TeamLead *teamLead;
public:
    Developer(const string& name="");
    TeamLead* getTeamLead()const;
    void setTeamLead(TeamLead* teamLead);
    void removeTeamLead();
    void sendLeavingRequest();
    void sendPromotionRequest(double amount);
    string getName()const;
    double getSalary()const;
    void setSalary(const double salary);
    void setInitialSalary(const double amount);
};

class TeamLead: public Developer{
private:
    vector<Developer*> developers;
    vector<LeavingRequest> leavingRequests;
    vector<PromotionRequest> promotionRequests;
    int developerExist(Developer * developer);
    int developerExist(const string& name);
public:
    TeamLead(const string& name="",const double salary=0);

//    TeamLead* getTeamLead()const;
//    void sendLeavingRequest();
//    void sendPromotionRequest(double amount);

    vector<Developer*> getTeam();
    void addDeveloperToTeam(Developer * developer, double salary);
    void removeDeveloperFromTeam(const string& name);
    void increaseTeamSalariesBy(double amount);
    void decreaseTeamSalariesBy(double amount);

    void addLeavingRequest(const LeavingRequest& leavingRequest);
    void addPromotionRequest(const PromotionRequest& promotionRequest);
    void fulfillLeavingRequests();
    void fulfillPromotionRequests();
};


#endif //INC_2_TEAMLEAD_HPP
