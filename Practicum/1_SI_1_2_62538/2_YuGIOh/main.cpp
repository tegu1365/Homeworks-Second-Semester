#include "Duelist.h"

int main() {
    Duelist pl1=Duelist("Karen");
    MagicCard k=MagicCard();
    k.print();
    MagicCard a=MagicCard("Spell","Magic",spell);
    a.print();
    pl1.addMagicCardInDeck(a);
    pl1.addMonsterCardInDeck("PINK",200,20);
    pl1.print();
    return 0;
}
