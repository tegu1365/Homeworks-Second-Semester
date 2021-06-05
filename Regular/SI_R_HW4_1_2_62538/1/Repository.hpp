//
// Created by Tegu on 4.6.2021 г..
//

#ifndef INC_1_REPOSITORY_HPP
#define INC_1_REPOSITORY_HPP
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <string>

class Repository {
private:
    vector<Subscribers*> subs;
public:
    Repository()=default;
    void add(Averager *);
    void add(MovingAverager *);
    void add(PeriodicSampler *);

    Subscribers *get(std::string id);
    Repository(const Repository& other);
    Repository& operator=(const Repository& rhs);
    ~Repository();
};


#endif //INC_1_REPOSITORY_HPP
