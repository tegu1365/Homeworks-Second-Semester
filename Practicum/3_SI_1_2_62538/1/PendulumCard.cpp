//
// Created by Tegu on 1.5.2021 г..
//

#include "PendulumCard.h"
#include <vector>

PendulumCard::PendulumCard(const string name, const string effect, const unsigned int atk, const unsigned int def,
                           const Type type, const unsigned short scale):Card(name,effect),MagicCard(name,effect,type),MonsterCard(name,effect,atk,def) {
    this->setScale(scale);
}

PendulumCard::PendulumCard(const char *text) {
    //<name>|<effect>|<attackPoints>|<defencePoints>|<pendulumScale>|<type>
    string str=text;
    vector<string> list;

    string current="";
    for(int i=0;i<str.size();i++){
        if(str[i]=='|'){
            list.push_back(current);
            current="";
        }else {
            char a=str[i];
            current.push_back(a);
        }
    }
    list.push_back(current);
    this->setName(list[0]);
    this->setEffect(list[1]);
    this->setATK(stoi(list[2]));
    this->setDEF(stoi(list[3]));
    this->setScale(stoi(list[4]));
    if(list[5]._Equal("SPELL")){
        this->setType(spell);
    } else{
        if(list[2]._Equal("TRAP")){
            this->setType(trap);
        }else{
            if(list[2]._Equal("BUFF")){
                this->setType(buff);
            } else{
                this->setType(NT);
            }
        }
    }

}

unsigned short PendulumCard::getScale() const {
    return scale;
}

void PendulumCard::setScale(const unsigned short scale) {
    if(scale>=1&&scale<=13){
        this->scale=scale;
    }else{
        this->scale=1;
    }
}

string PendulumCard::toString() const {
    string result=name+"|"+effect+"|"+to_string(this->getATK())+"|"+to_string(this->getDEF())+"|"+to_string(scale)+"|";
    switch(this->getType()){
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
