/**
*	Solution to homework assignment 1
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021
*
*	@author Teodora Dimitrova Petkova
*	@idnumber 62538
*	@task 2
*	@compiler VC
*/
#include "MagicCard.h"

MagicCard::MagicCard() {
    this->setName("NULL");
    this->setEffect("null");
    this->setType(NT);
}

MagicCard::MagicCard(char *_name, char *_effect, Type _type) {
    this->setName(_name);
    this->setEffect(_effect);
    this->setType(_type);
}

char *MagicCard::getName() {
    return name;
}

char *MagicCard::getEffect() {
    return effect;
}

Type MagicCard::getType() {
    return type;
}

void MagicCard::setName(char *_name) {
    int i = 0;
    while (_name[i] != '\0' && i < 26) {
        name[i] = _name[i];
        i++;
    }
    name[i]='\0';

}

void MagicCard::setEffect(char *_effect) {
    int i = 0;
    //cout<<_effect<<endl;
    while (_effect[i] != '\0' && i<100) {
        effect[i] = _effect[i];
        i++;
    }
    effect[i]='\0';
}

void MagicCard::setType(Type _type) {
    type = _type;
}

void MagicCard::print() const {
    char *_type;
    switch (type) {
        case spell:
            _type = "spell";
            break;
        case buff:
            _type = "buff";
            break;
        case trap:
            _type = "trap";
            break;
        default:
            _type="NO TYPE";
            break;
    }
    cout << name << "\n Type: " << _type << "\n Effect: " << effect << endl;
}

//MagicCard::MagicCard(MagicCard const &_magicCard) {
//    char _name[26],_effect[100];
//    int i=0;
//    while (_magicCard.name[i]!='/0'){
//        _name[i]=_magicCard.name[i];
//        i++;
//    }
//    this->setName(_name);
//    i=0;
//    while (_magicCard.effect[i]!='/0'){
//        _effect[i]=_magicCard.effect[i];
//        i++;
//    }
//    this->setEffect(_effect);
//    this->setType(_magicCard.type);
//}



