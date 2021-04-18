//
// Created by Tegu on 18.4.2021 г..
//

#include "SectionVotes.hpp"

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes) {
    this->party1Votes = party1Votes;
    this->party2Votes = party2Votes;
    this->party3Votes = party3Votes;
}

int SectionVotes::votesForParty(Party party) const {
    switch (party) {
        case PARTY1:
            return party1Votes;
        case PARTY2:
            return party2Votes;
        case PARTY3:
            return party3Votes;
        default:
            return 0;
    }
}

ostream &operator<<(ostream &out, const SectionVotes &rhs) {
    out<<rhs.party1Votes<<" "<<rhs.party2Votes<<" "<<rhs.party3Votes<<"\n";
    return out;
}

istream &operator>>(istream &in, SectionVotes &rhs) {
    in>> rhs.party1Votes>> rhs.party2Votes>> rhs.party3Votes;
    return in;
}

SectionVotes::SectionVotes() {
    party1Votes=0;
    party2Votes=0;
    party3Votes=0;
}
