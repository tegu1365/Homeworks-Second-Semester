//
// Created by Tegu on 8.5.2021 г..
//

#ifndef INC_2_TEAMLEAD_HPP
#define INC_2_TEAMLEAD_HPP
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include "Worker.hpp"

#include <vector>
using namespace std;

class Developer;

class TeamLead: public Worker{
private:
    TeamLead* teamLead;
    vector<Developer*> developers;
    vector<LeavingRequest> leavingRequests;
    vector<PromotionRequest> promotionRequests;
public:
    TeamLead(const string& name="", double salary=0);

    TeamLead* getTeamLead()const;
    void sendLeavingRequest();
    void sendPromotionRequest(double amount);

    vector<Developer*> getTeam();
    void addDeveloperToTeam(Developer * developer, double salary);
    void removeDeveloperFromTeam(const string& name);
    void increaseTeamSalariesBy(double amount);
    void decreaseTeamSalariesBy(double amount);

    void addLeavingRequest(const LeavingRequest& leavingRequest);
    void addPromotionRequest(const PromotionRequest& promotionRequest);
    void fulfillLeavingRequests();
    void fulfillPromotionRequests();

    int developerExist(Developer * developer);
    int developerExist(const string& name);
   // ~TeamLead();
};


#endif //INC_2_TEAMLEAD_HPP
