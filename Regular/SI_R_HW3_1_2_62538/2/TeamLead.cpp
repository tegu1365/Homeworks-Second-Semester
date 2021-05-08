//
// Created by Tegu on 8.5.2021 г..
//

#include "TeamLead.hpp"

TeamLead::TeamLead(const string &name, double salary):Developer(name) {
    this->salary=salary;
    this->setTeamLead(this);
}

vector<Developer *> TeamLead::getTeam() {
    return developers;
}

void TeamLead::addDeveloperToTeam(Developer *developer, double salary) {
    if(this->developerExist(developer)==-1){
        developer->setSalary(salary);
        TeamLead* ptr=this;
        developer->setTeamLead(ptr);
        developers.push_back(developer);
    }
}

int TeamLead::developerExist(Developer *developer) {
    for (unsigned int i = 0; i < this->developers.size(); i++) {
       if(developer==developers[i]){
           return i;
       }
    }
    return -1;
}

bool equal(string a,string b){
    if(a.size()==b.size()){
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

int TeamLead::developerExist(const string &name) {
    for (int i = this->developers.size()-1; i >=0 ; i--) {
        if(equal(name,developers[i]->getName())){
            return i;
        }
    }
    return -1;
}

void TeamLead::removeDeveloperFromTeam(const string &name) {
    int index=this->developerExist(name);
    if(index!=-1){
        developers[index]->removeTeamLead();
        developers.erase(developers.cbegin()+index);
    }
}

void TeamLead::increaseTeamSalariesBy(double amount) {
    for (unsigned int i = 0; i < this->developers.size(); i++) {
        double newSalary=developers[i]->getSalary()+amount;
        developers[i]->setSalary(newSalary);
    }
}

void TeamLead::decreaseTeamSalariesBy(double amount) {
    for (unsigned int i = 0; i < this->developers.size(); i++) {
        double newSalary=developers[i]->getSalary()-amount;
        developers[i]->setSalary(newSalary);
    }
}

void TeamLead::addLeavingRequest(const LeavingRequest &leavingRequest) {
    leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest &promotionRequest) {
    promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests() {
    for(unsigned int i=0;i<leavingRequests.size();i++){
        this->removeDeveloperFromTeam(this->leavingRequests[i].getSender());
    }
    leavingRequests.clear();
}

void TeamLead::fulfillPromotionRequests() {
    for(unsigned int i=0;i<promotionRequests.size();i++){
        int index=developerExist(promotionRequests[i].getSender());
        if(index!=-1){
            double newSalary=developers[i]->getSalary()+promotionRequests[i].getAmount();
            developers[i]->setSalary(newSalary);
  //          cout<<promotionRequests[i].getID()<<endl;
        }
    }
    promotionRequests.clear();
}

