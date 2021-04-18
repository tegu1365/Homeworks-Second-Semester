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
        sections[numOfSections] = SectionVotes(party1, party2, party3);
        numOfSections++;
    }
}

int ElectionResultsDatabase::numberOfSections() const {
    return 0;
}

int ElectionResultsDatabase::votesForParty(Party) const {
    return 0;
}

Party ElectionResultsDatabase::winningParty() const {
    return PARTY1;
}

ostream &operator<<(ostream &out, const ElectionResultsDatabase &rhs) {
    return out;
}

istream &operator>>(istream &in, ElectionResultsDatabase &rhs) {
    return in;
}

ElectionResultsDatabase::ElectionResultsDatabase() {
    numOfSections = 0;
    totalVotesForParty1 = 0;
    totalVotesForParty2 = 0;
    totalVotesForParty3 = 0;
}
