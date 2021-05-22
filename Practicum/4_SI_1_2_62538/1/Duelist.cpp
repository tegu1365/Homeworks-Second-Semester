/**
*	Solution to homework assignment 4
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021
*
*	@author Teodora Dimitrova Petkova
*	@idnumber 62538
*	@task 1
*	@compiler VC
*/


#include "Duelist.hpp"
#include "fstream"
#include <stdlib.h>

Duelist::Duelist(const string name, const Deck deck) {
    this->name = name;
    this->deck = deck;
}

Deck Duelist::getDeck() const {
    return this->deck;
}

string Duelist::getName() const {
    return name;
}

void Duelist::setDeck(const Deck deck) {
    this->deck = deck;
}

void Duelist::setName(const string name) {
    this->name = name;
}

bool Duelist::saveDeck(const char *filename) {
    fstream file;
    file.open(filename);
    if (!file.is_open()) {
        return false;
    }
    string write=deck.toString();
    file<<write;
    file.close();
    return true;
}

bool Duelist::loadDeck(const char *filename) {
    fstream file;
    file.open(filename);
    if (!file.is_open()) {
        return false;
    }
    string read="";
    string line="";
    while ( getline (file,line) ) {
        read.append(line+"\n");
    }
    this->deck.clear();
    this->deck=Deck(read.c_str());
    file.close();
    return true;
}

void Duelist::display() const {
    cout<<name<<endl;
    cout<<deck.toString()<<endl;
}

void Duelist::duel(const Duelist &enemy) {
    if(this->deck.getNumberOfCards()==enemy.getDeck().getNumberOfCards()){
        int rounds=deck.getNumberOfCards();
        this->deck.shuffle();
        enemy.getDeck().shuffle();
        int score=0, enemyScore=0;
        for(int i=0;i<rounds;i++){
            cout<<"ROUND "<<i+1<<endl;
            if(this->getDeck()[i]>enemy.getDeck()[i]){
                score++;
               // system("Color 0A");//green
                //cout<<"ROUND "<<i+1<<endl;
                cout<<"-> Score for "<<this->name<<endl;
            }else{
                if(this->getDeck()[i]<enemy.getDeck()[i]){
                    enemyScore++;
                   // system("Color 0C");//red
                    //cout<<"ROUND "<<i+1<<endl;
                    cout<<"-> Score for "<<enemy.name<<endl;
                }else{
                   // system("Color 0F");//white
                   // cout<<"ROUND "<<i+1<<endl;
                    cout<<"-> A draw"<<endl;
                }
            }
        }
        cout<<endl;
        if(score>enemyScore){
           // system("Color 0A");
            cout<<this->name<<" WINS\n";
        }else{
            if(score<enemyScore) {
             //   system("Color 0C");
                cout << enemy.name << " WINS\n";
            } else{
               // system("Color 0F");
                cout<<"A DRAW\n";
            }
        }
        //system("Color 0F");
        cout<<"_____________________________________________\n ";
        cout<<score<<" points for "<<this->name<<endl<<" ";
        cout<<enemyScore<<" points for "<<enemy.name<<endl;
        cout<<"_____________________________________________\n ";
    }else{
        cout<<"The duel cannot be conducted\n";
    }
}

