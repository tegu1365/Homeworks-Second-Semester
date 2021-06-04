//
// Created by Tegu on 4.6.2021 г..
//

#ifndef INC_1_BACKLOGPUBLISHER_HPP
#define INC_1_BACKLOGPUBLISHER_HPP
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"

class BacklogPublisher {
private:
    vector<Subscribers*> subs;
    vector<Message> signals;
    void oldSignals(Subscribers* sub);
public:
    void subscribe(Averager *);
    void subscribe(MovingAverager *);
    void subscribe(PeriodicSampler *);

    void unsubscribe(Averager *);
    void unsubscribe(MovingAverager *);
    void unsubscribe(PeriodicSampler *);

    void signal(Message);

//    BacklogPublisher& operator=(const BacklogPublisher& rhs);
//    ~BacklogPublisher();
};


#endif //INC_1_BACKLOGPUBLISHER_HPP
