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

#include "Deck.hpp"
#include <algorithm>
#include <random>

Deck::Deck(const string name) {
    this->name = name;
    numOfMagic = 0;
    numOfMonsters = 0;
    numOfCards = 0;
    numOfPendulum = 0;
}

unsigned int Deck::getNumberOfMagicCards() const {
    return numOfMagic;
}

unsigned int Deck::getNumberOfMonsterCards() const {
    return numOfMonsters;
}

unsigned int Deck::getNumberOfPendulumCards() const {
    return numOfPendulum;
}

void Deck::clear() {
    for (auto x : cards) {
        delete x;
    }
    this->cards.clear();

    numOfPendulum = 0;
    numOfMonsters = 0;
    numOfMagic = 0;
    numOfCards = 0;
}

Deck &Deck::operator=(const Deck &sth) {
    if (this != &sth) {
        this->name = sth.name;
        this->numOfCards = sth.numOfCards;
        this->numOfMonsters = sth.numOfMonsters;
        this->numOfMagic = sth.numOfMagic;
        this->numOfPendulum = sth.numOfPendulum;

        for (auto x : cards) {
            delete x;
        }
        cards.clear();

        for (auto x : sth.cards) {
            cards.push_back(x->clone());
        }
    }
    return *this;
}

Deck::Deck(const Deck &deck) {
    this->name = deck.name;
    this->numOfCards = deck.numOfCards;
    this->numOfMonsters = deck.numOfMonsters;
    this->numOfMagic = deck.numOfMagic;
    this->numOfPendulum = deck.numOfPendulum;
    for (auto x : deck.cards) {
        cards.push_back(x->clone());
    }
}

string Deck::toString() const {
    string result =
            this->name + "|" + to_string(this->getNumberOfCards()) + "|" + to_string(this->getNumberOfMonsterCards()) +
            "|" + to_string(this->getNumberOfMagicCards()) +
            "|" + to_string(this->getNumberOfPendulumCards()) + "\n";
    string monsters = "";
    string magic = "";
    string pendulum = "";
    for (auto x : cards) {
        if (x->getCardType() == MONSTER) {
            monsters.append(x->toString() + "\n");
        }
        if (x->getCardType() == MAGIC) {
            magic.append(x->toString() + "\n");
        }
        if (x->getCardType() == PENDULUM) {
            pendulum.append(x->toString() + "\n");
        }
    }
    result.append(monsters);
    result.append(magic);
    result.append(pendulum);
    return result;
}

Deck::Deck(const char *text) {
    string str = text;
    vector<string> list;

    string current = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '\n') {
            list.push_back(current);
            current = "";
        } else {
            char a = str[i];
            current.push_back(a);
        }
    }
    list.push_back(current);
    current = "";
    vector<string> line;

    for (int i = 0; i < list[0].size(); i++) {
        if (str[i] == '|') {
            line.push_back(current);
            current = "";
        } else {
            char a = str[i];
            current.push_back(a);
        }
    }
    line.push_back(current);
    this->name = line[0];
    numOfCards = stoi(line[1]);
    numOfMonsters = stoi(line[2]);
    numOfMagic = stoi(line[3]);
    numOfPendulum = stoi(line[4]);
    line.clear();
    current = "";
    //cout<<numOfMonsters<<"-"<<numOfMagic<<"-"<<numOfPendulum<<endl;
    int indexOfLine = 1;
    for (int i = 0; i < numOfMonsters; i++) {
        MonsterCard m = MonsterCard(list[indexOfLine].c_str());
        cards.push_back(m.clone());
        //cout<<indexOfLine<<". "<<m.getName()<<endl;
        indexOfLine++;
    }
    for (int i = 0; i < numOfMagic; i++) {
        MagicCard m = MagicCard(list[indexOfLine].c_str());
        cards.push_back(m.clone());
        //  cout<<indexOfLine<<". "<<m.toString()<<endl;
        indexOfLine++;
    }
    for (int i = 0; i < numOfPendulum; i++) {
        PendulumCard m = PendulumCard(list[indexOfLine].c_str());
        cards.push_back(m.clone());
        // cout<<indexOfLine<<". "<<m.toString()<<endl;
        indexOfLine++;
    }
}

unsigned int Deck::getNumberOfCards() const {
    return numOfCards;
}

Deck::~Deck() {
    for (auto x : cards) {
        delete x;
    }
}

void Deck::addCard(Card *card) {
    cards.push_back(card->clone());
    numOfCards++;
    if (card->getCardType() == MAGIC) {
        numOfMagic++;
    } else {
        if (card->getCardType() == MONSTER) {
            numOfMonsters++;
        } else {
            numOfPendulum++;
        }
    }
}

void Deck::setCard(const unsigned int index, Card *card) {
    if (index < numOfCards) {
        if (cards[index]->getCardType() == card->getCardType()) {
            cards[index]->setName(card->getName());
            cards[index]->setEffect(card->getEffect());
            cards[index]->setRarity(card->getRarity());

            MonsterCard *monsterCard = dynamic_cast<MonsterCard *>(cards[index]);
            MonsterCard *monsterCard1 = dynamic_cast<MonsterCard *>(card);
            if (monsterCard) {
                monsterCard->setDEF(monsterCard1->getDEF());
                monsterCard->setATK(monsterCard1->getATK());
            }

            MagicCard *magicCard = dynamic_cast<MagicCard *>(cards[index]);
            MagicCard *magicCard1 = dynamic_cast<MagicCard *>(card);
            if (magicCard) {
                magicCard->setType(magicCard1->getType());
            }

            PendulumCard *pendulumCard = dynamic_cast<PendulumCard *>(cards[index]);
            PendulumCard *pendulumCard1 = dynamic_cast<PendulumCard *>(card);
            if (pendulumCard) {
                pendulumCard->setDEF(pendulumCard1->getDEF());
                pendulumCard->setATK(pendulumCard1->getATK());
                pendulumCard->setType(pendulumCard1->getType());
                pendulumCard->setScale(pendulumCard1->getScale());
            }
        }
    } else {
        cards.push_back(card->clone());
        numOfCards++;
        if (card->getCardType() == MAGIC) {
            numOfMagic++;
        } else {
            if (card->getCardType() == MONSTER) {
                numOfMonsters++;
            } else {
                numOfPendulum++;
            }
        }
    }
}

void Deck::shuffle() {
    auto rng = std::default_random_engine{};
    ::shuffle(cards.begin(), cards.end(), rng);
//    string result="";
//    for (auto x : cards) {
//            result.append(x->toString() + "\n");
//    }
//    cout<<result;
}

Card *Deck::operator[](unsigned int index) const {
    if(index<numOfCards) {
        return cards[index];
    }
}
