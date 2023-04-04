#include "../sources/round.hpp"

namespace ariel {
    Round::Round(Player *_p1, Player *_p2) : p1(_p1), p2(_p2) {
        this->c_p1 = this->p1->getMyDeck().pop();
        this->c_p2 = this->p2->getMyDeck().pop();
    }


    string Round::toString() {
        return this->p1->getName() + " played " + this->c_p1.toString() + " " + this->p2->getName() + " played " +
               this->c_p2.toString() + ".";
    }
}