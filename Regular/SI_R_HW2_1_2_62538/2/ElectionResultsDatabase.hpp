//
// Created by Tegu on 18.4.2021 г..
//

#ifndef INC_2_ELECTIONRESULTSDATABASE_HPP
#define INC_2_ELECTIONRESULTSDATABASE_HPP

#include <vector>
#include <iostream>
#include <fstream>

#include "SectionVotes.hpp"

using namespace std;

class ElectionResultsDatabase {
private:
    int totalVotesForParty1,totalVotesForParty2,totalVotesForParty3;
    int numOfSections;
    vector<SectionVotes> sections;
public:
    ElectionResultsDatabase();
    void addResultsFromFile(const char* filename);

    int numberOfSections() const;

    int votesForParty(Party) const;

    Party winningParty() const;
    friend ostream& operator<<(ostream& out, const ElectionResultsDatabase& rhs);
    friend istream & operator>>(istream& in, ElectionResultsDatabase& rhs);
};


#endif //INC_2_ELECTIONRESULTSDATABASE_HPP
