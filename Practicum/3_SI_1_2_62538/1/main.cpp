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
#include "MonsterCard.h"

int main() {
    MonsterCard m=MonsterCard("Backup Secretary",
                              "If you control a Cyberse monster, you can Special Summon this card (from your hand).",
                              1200,800);
   cout<< m.getName()<<endl;
   m.setName("Backup Supervisor");
   cout<<m.toString()<<endl;
 //  string str="Blue-Eyes White Dragon|This legendary dragon is a powerful engine of destruction.|3000|2500";
   MonsterCard k=MonsterCard("Blue-Eyes White Dragon|This legendary dragon is a powerful engine of destruction.|3000|2500");
   cout<<k.getName()<<endl;
   cout<<k.getDEF()<<endl;
    return 0;
}
