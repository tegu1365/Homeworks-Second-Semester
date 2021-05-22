//
// Created by Tegu on 8.5.2021 г..
//

#ifndef INC_2_PROMOTIONREQUEST_HPP
#define INC_2_PROMOTIONREQUEST_HPP
#include "Request.hpp"

class PromotionRequest: public Request {
private:
    double amount;
public:
    PromotionRequest(const double  amount);
    PromotionRequest(const string& sender= "",const double amount=0);
    double getAmount()const;
};


#endif //INC_2_PROMOTIONREQUEST_HPP
