/**
*	Solution to homework assignment 3
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021
*
*	@author Teodora Dimitrova Petkova
*	@idnumber 62538
*	@task 1
*	@compiler VC
*/


#include "PendulumCard.h"
#include <vector>

PendulumCard::PendulumCard(const string name, const string effect, const unsigned int atk, const unsigned int def,
                           const unsigned short scale, const Type type) : Card(name, effect),
                                                                          MagicCard(name, effect, type),
                                                                          MonsterCard(name, effect, atk, def) {
    this->setScale(scale);
}

PendulumCard::PendulumCard(const char *text) {
    //<name>|<effect>|<attackPoints>|<defencePoints>|<pendulumScale>|<type>
    string str = text;
    vector<string> list;

    string current = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '|') {
            list.push_back(current);
            current = "";
        } else {
            char a = str[i];
            current.push_back(a);
        }
    }
    list.push_back(current);
    this->setName(list[0]);
    this->setEffect(list[1]);
    this->setATK(stoi(list[2]));
    this->setDEF(stoi(list[3]));
    this->setScale(stoi(list[4]));
    if (list[5]._Equal("SPELL")) {
        this->setType(spell);
    } else {
        if (list[2]._Equal("TRAP")) {
            this->setType(trap);
        } else {
            if (list[2]._Equal("BUFF")) {
                this->setType(buff);
            } else {
                this->setType(NT);
            }
        }
    }

}

unsigned short PendulumCard::getScale() const {
    return scale;
}

void PendulumCard::setScale(const unsigned short scale) {
    if (scale >= MIN_SCALE && scale <= MAX_SCALE) {
        this->scale = scale;
    } else {
        this->scale = 1;
    }
}

string PendulumCard::toString() const {
    string result = name + "|" + effect + "|" + to_string(this->getATK()) + "|" + to_string(this->getDEF()) + "|" +
                    to_string(scale) + "|";
    switch (this->getType()) {
        case buff:
            result.append("BUFF");
            break;
        case spell:
            result.append("SPELL");
            break;
        case trap:
            result.append("TRAP");
            break;
        default:
            result.append("NO TYPE");
            break;
    }
    return result;
}
