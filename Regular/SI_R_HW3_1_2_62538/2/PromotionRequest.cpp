//
// Created by Tegu on 8.5.2021 г..
//

#include "PromotionRequest.hpp"

PromotionRequest::PromotionRequest(const string &sender, const double amount):Request("I want a raise!",sender) {
    this->amount=amount;
}

double PromotionRequest::getAmount() const {
    return amount;
}
