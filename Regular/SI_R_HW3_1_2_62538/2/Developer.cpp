//
// Created by Tegu on 8.5.2021 г..
//

#include "Developer.hpp"

Developer::Developer(const string &name):Worker(name){
    this->salary=0;
    this->teamLead= nullptr;
}

TeamLead *Developer::getTeamLead() const {
    return teamLead;
}

void Developer::sendLeavingRequest() {
    LeavingRequest l=LeavingRequest(this->name);
    teamLead->addLeavingRequest(l);
}

void Developer::sendPromotionRequest(double amount) {
    PromotionRequest p=PromotionRequest(this->name,amount);
    teamLead->addPromotionRequest(p);
}

void Developer::setTeamLead(TeamLead *teamLead) {
    delete this->teamLead;
    this->teamLead = teamLead;
}

//Developer::~Developer() {
//    delete this->teamLead;
//}
