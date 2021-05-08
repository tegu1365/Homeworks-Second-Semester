//
// Created by Tegu on 8.5.2021 г..
//

#ifndef INC_2_DEVELOPER_HPP
#define INC_2_DEVELOPER_HPP
#include "TeamLead.hpp"
#include "Worker.hpp"
using namespace std;

class Developer: public Worker {
private:
    TeamLead *teamLead;
public:
    Developer(const string& name="");
    TeamLead* getTeamLead()const;
    void setTeamLead(TeamLead* teamLead);
    void sendLeavingRequest();
    void sendPromotionRequest(double amount);
};


#endif //INC_2_DEVELOPER_HPP
