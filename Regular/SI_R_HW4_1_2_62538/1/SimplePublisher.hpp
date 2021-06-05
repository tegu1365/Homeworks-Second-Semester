//
// Created by Tegu on 4.6.2021 г..
//

#ifndef INC_1_SIMPLEPUBLISHER_HPP
#define INC_1_SIMPLEPUBLISHER_HPP
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <vector>

class SimplePublisher {
public:
    vector<Subscribers*> subs;
   // void subscribeSub(Subscribers* sub);
  //  void unsubscribeSub(Subscribers* sub);
public:
    void subscribe(Averager *);
    void subscribe(MovingAverager *);
    void subscribe(PeriodicSampler *);

    void unsubscribe(Averager *);
    void unsubscribe(MovingAverager *);
    void unsubscribe(PeriodicSampler *);

    void signal(Message);

//    SimplePublisher& operator=(const SimplePublisher& rhs);
//    ~SimplePublisher();
};


#endif //INC_1_SIMPLEPUBLISHER_HPP