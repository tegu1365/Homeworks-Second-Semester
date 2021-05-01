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

#include <iostream>
#include <assert.h>
#include "MonsterCard.h"
#include "MagicCard.h"
#include "PendulumCard.h"

void Test() {
    MonsterCard m = MonsterCard("Backup Secretary",
                                "If you control a Cyberse monster, you can Special Summon this card (from your hand).",
                                1200, 800);
    assert(m.getName()._Equal("Backup Secretary"));
    m.setName("Backup Supervisor");
    assert(m.toString()._Equal(
            "Backup Supervisor|If you control a Cyberse monster, you can Special Summon this card (from your hand).|1200|800"));
    MonsterCard k = MonsterCard(
            "Blue-Eyes White Dragon|This legendary dragon is a powerful engine of destruction.|3000|2500");
    assert(k.getName()._Equal("Blue-Eyes White Dragon"));
    assert(k.getDEF() == 2500);
    assert(k.toString()._Equal(
            "Blue-Eyes White Dragon|This legendary dragon is a powerful engine of destruction.|3000|2500"));

    MagicCard magicCard = MagicCard("Cynet Recovery",
                                    "If a Link Monster(s) you control is destroyed by battle or an opponent's card effect: You can target 1 monster in your GY, except a Link Monster;",
                                    spell);
    assert(magicCard.getName()._Equal("Cynet Recovery"));
    MagicCard mc = MagicCard("Swords of Revealing Light|Your opponent's monsters cannot declare an attack.|SPELL");
    assert(mc.getType() == Type::spell);
    assert(mc.toString()._Equal("Swords of Revealing Light|Your opponent's monsters cannot declare an attack.|SPELL"));

    PendulumCard p = PendulumCard("Speedroid Dominobutterfly",
                                  "You cannot Pendulum Summon monsters, except WIND monsters. This effect cannot be negated.",
                                  100, 300, spell, 8);
    assert(p.getScale() == 8);

    PendulumCard pc = PendulumCard(
            "Timegazer Magician|Your opponent cannot activate Trap Magic Cards|1200|600|8|SPELL");
    assert(pc.getScale() == 8);
    assert(pc.getName()._Equal("Timegazer Magician"));
    assert(p.toString()._Equal(
            "Speedroid Dominobutterfly|You cannot Pendulum Summon monsters, except WIND monsters. This effect cannot be negated.|100|300|8|SPELL"));
}

int main() {
    Test();
    cout << "Test Successful" << endl;
    return 0;
}
