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


#include "MagicCard.hpp"
#include <vector>

MagicCard::MagicCard(const string name, const string effect, const unsigned int rarity, const Type type) : Card(MAGIC,name, effect,rarity) {
    this->type = type;
}

MagicCard::MagicCard(const char *text) : Card() {
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
    Card::setName(list[0]);
    Card::setEffect(list[1]);
    Card::setCardType(MAGIC);
    Card::setRarity( stoi(list[2]));
    if (list[3]=="SPELL") {
        this->type = spell;
    } else {
        if (list[3]=="TRAP") {
            this->type = trap;
        } else {
            if (list[3]=="BUFF") {
                this->type = buff;
            } else {
                this->type = NT;
            }
        }
    }
}

string MagicCard::toString() const {
    string result = name + "|" + effect + "|"+to_string(rarity)+"|";
    switch (type) {
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

void MagicCard::setType(const Type type) {
    this->type = type;
}

Type MagicCard::getType() const {
    return type;
}

Card *MagicCard::clone() {
    return new MagicCard(*this);
}
