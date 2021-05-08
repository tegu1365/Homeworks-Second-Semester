//
// Created by Tegu on 8.5.2021 г..
//

#include "Developer.hpp"


Developer::Developer(const string &name){
    this->name=name;
    this->salary=0;
    this->teamLead= nullptr;
}

string Developer::getName() const {
    return name;
}

double Developer::getSalary() const {
    return salary;
}

void Developer::setInitialSalary(const double amount) {
    if(salary==0){
        salary=amount;
    }
}

void Developer::setSalary(const double salary) {
    this->salary=salary;
}


TeamLead *Developer::getTeamLead() const {
    return teamLead;
}

void Developer::sendLeavingRequest() {
    LeavingRequest l=LeavingRequest(this->name);
    this->teamLead->addLeavingRequest(l);
}

void Developer::sendPromotionRequest(double amount) {
    PromotionRequest p=PromotionRequest(this->name,amount);
    this->teamLead->addPromotionRequest(p);
}

void Developer::setTeamLead(TeamLead *teamLead) {
 //   delete this->teamLead;
    this->teamLead = teamLead;
}

void Developer::removeTeamLead() {
    this->teamLead= nullptr;
}
