//
// Created by Tegu on 18.4.2021 г..
//

#ifndef INC_2_SECTIONVOTES_HPP
#define INC_2_SECTIONVOTES_HPP
#include <iostream>
using namespace std;
enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{
     int party1Votes;
     int party2Votes;
     int party3Votes;

public:
    SectionVotes();
    SectionVotes(int party1Votes, int party2Votes, int party3Votes);

    int votesForParty(Party) const;

    friend ostream& operator<<(ostream& out, const SectionVotes& rhs);
    friend istream & operator>>(istream& in, SectionVotes& rhs);


};


#endif //INC_2_SECTIONVOTES_HPP
