#include <iostream>
#include <assert.h>
#include <fstream>
#include <vector>
#include "SectionVotes.hpp"

using namespace std;

void runTest() {
    SectionVotes first = SectionVotes(1, 2, 3);
    assert(first.votesForParty(PARTY2) == 2);
    cout << first;

    //  SectionVotes second=SectionVotes();
    // cin>>second;
    // cout<<second;
    //  assert(second.votesForParty(PARTY3)==33);
}

int main() {
    runTest();
    std::cout << "End" << std::endl;
//
//    string filename = "text.txt";
//    ifstream infile;
//    infile.open(filename);
//
//    if (!infile.is_open()) {
//        cerr << "Could not open the file - '" << filename << "'" << endl;
//    }
//
//    int number;
//    while (infile >> number) {
//        cout << number << "; ";
//    }
//
//    cout << endl;
//    infile.close();
    return 0;
}
