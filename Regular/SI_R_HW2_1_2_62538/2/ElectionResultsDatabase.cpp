//
// Created by Tegu on 18.4.2021 г..
//

#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char *filename) {
    fstream infile;
    infile.open(filename);
    int party1, party2, party3;
    while (infile >> party1 >> party2 >> party3) {
        totalVotesForParty1 += party1;
        totalVotesForParty2 += party2;
        totalVotesForParty3 += party3;
        sections.push_back(SectionVotes(party1, party2, party3));
        numOfSections++;
    }
}

int ElectionResultsDatabase::numberOfSections() const {
    return numOfSections;
}

int ElectionResultsDatabase::votesForParty(Party party) const {

    switch (party) {
        case PARTY1:
            return totalVotesForParty1;
        case PARTY2:
            return totalVotesForParty2;
        case PARTY3:
            return totalVotesForParty3;
        default:
            return 0;
    }
}

Party ElectionResultsDatabase::winningParty() const {
    if(totalVotesForParty1>=totalVotesForParty2 && totalVotesForParty1>=totalVotesForParty3){
        return PARTY1;
    }
    if(totalVotesForParty2>=totalVotesForParty1 && totalVotesForParty2>=totalVotesForParty3){
        return PARTY2;
    }
    if(totalVotesForParty3>=totalVotesForParty2 && totalVotesForParty3>=totalVotesForParty1){
        return PARTY3;
    }
}

ostream &operator<<(ostream &out, const ElectionResultsDatabase &rhs) {
    for(int i=0;i<rhs.numOfSections;i++){
        out<<rhs.sections[i];
    }
    return out;
}

istream &operator>>(istream &in, ElectionResultsDatabase &rhs) {
    SectionVotes a=SectionVotes();
    while(in>>a){
        rhs.sections.push_back(a);
        rhs.numOfSections++;
        rhs.totalVotesForParty1+=a.votesForParty(PARTY1);
        rhs.totalVotesForParty2+=a.votesForParty(PARTY2);
        rhs.totalVotesForParty3+=a.votesForParty(PARTY3);
    }
    return in;
}

ElectionResultsDatabase::ElectionResultsDatabase() {
    numOfSections = 0;
    totalVotesForParty1 = 0;
    totalVotesForParty2 = 0;
    totalVotesForParty3 = 0;
}
