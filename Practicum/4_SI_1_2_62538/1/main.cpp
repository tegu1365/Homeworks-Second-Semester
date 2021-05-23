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

#include <iostream>
#include <assert.h>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include "Deck.hpp"
#include "Duelist.hpp"

void Test() {
    MonsterCard m = MonsterCard("Backup Secretary",
                                "If you control a Cyberse monster, you can Special Summon this card (from your hand).",12,
                                1200, 800);
    assert(m.getRarity()==12);
    assert(m.getCardType()==MONSTER);
    assert(m.getName()=="Backup Secretary");
    m.setName("Backup Supervisor");
    assert(m.toString()==
            "Backup Supervisor|If you control a Cyberse monster, you can Special Summon this card (from your hand).|12|1200|800");
    MonsterCard k = MonsterCard(
            "Blue-Eyes White Dragon|This legendary dragon is a powerful engine of destruction.|0|3000|2500");
    assert(k.getName()=="Blue-Eyes White Dragon");
    assert(k.getDEF() == 2500);
    assert(k.getRarity()==0);
    assert(k.toString()==
            "Blue-Eyes White Dragon|This legendary dragon is a powerful engine of destruction.|0|3000|2500");

    MagicCard magicCard = MagicCard("Cynet Recovery",
                                    "If a Link Monster(s) you control is destroyed by battle or an opponent's card effect: You can target 1 monster in your GY, except a Link Monster;",
                                    3,spell);
    assert(magicCard.getName()=="Cynet Recovery");
    MagicCard mc = MagicCard("Swords of Revealing Light|Your opponent's monsters cannot declare an attack.|2|SPELL");
    assert(mc.getType() == Type::spell);
    assert(mc.toString()=="Swords of Revealing Light|Your opponent's monsters cannot declare an attack.|2|SPELL");

    PendulumCard p = PendulumCard("Speedroid Dominobutterfly",
                                  "You cannot Pendulum Summon monsters, except WIND monsters. This effect cannot be negated.",
                                  12,100, 300, 8, spell);
    assert(p.getScale() == 8);

    PendulumCard pc = PendulumCard(
            "Timegazer Magician|Your opponent cannot activate Trap Magic Cards|4|1200|600|8|SPELL");
    assert(pc.getScale() == 8);
    assert(pc.getName()=="Timegazer Magician");
    assert(pc.toString()==
            "Timegazer Magician|Your opponent cannot activate Trap Magic Cards|4|1200|600|8|SPELL");
    assert(pc.getRarity()==4);
    assert(pc.getCardType()==PENDULUM);



    Deck deck = Deck(string("Deck 1"));
    deck.addCard(&m);
    deck.setCard(1,&k);
    deck.setCard(1,&pc);
    assert(deck.getNumberOfMonsterCards() == 2);


    Deck deck2 = deck;
    deck.clear();
    assert(deck.getNumberOfMonsterCards() == 0);
    assert(deck2.getNumberOfMonsterCards() == 2);
    //cout << deck2.toString() << endl;

    Deck d2 = Deck(
            "Deck 2|2|2|0|0\nBackup Supervisor|If you control a Cyberse monster, you can Special Summon this card (from your hand).|3|1200|800\nBlue-Eyes White Dragon|This legendary dragon is a powerful engine of destruction.|2|3000|2500\n");
    //cout << d2.toString() << endl;

    d2.addCard(&pc);
    d2.addCard(&p);
    d2.addCard(&magicCard);
   // d2.setCard(1,&m);
    /*d2.addCard(&mc);
    cout << d2.toString() << endl<<"_______________________________________________________\n";
    d2.shuffle();*/

    Duelist duelist=Duelist(string("Tegu"));
    duelist.setDeck(d2);
    //duelist.display();
    assert(duelist.saveDeck("textDeck.txt")==true);

    assert(duelist.loadDeck("magicDeck.txt")==true);
    // duelist.display();

    Duelist duelist1=Duelist(string("Veny"));
    assert(duelist1.loadDeck("textDeck.txt")==true);
    duelist.duel(duelist1);
}

int main() {
    Test();
    cout << "Test Successful" << endl;
    return 0;
}
