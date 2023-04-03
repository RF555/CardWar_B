#include "../sources/card.hpp"

namespace ariel {

    Card::Card(SUIT s, RANK rank) {
        this->_suit = s;
        this->_rank = rank;
    }

    SUIT Card::getSuit() { return this->_suit; }

    int Card::getRank() { return this->_rank; }

    void Card::setCard(SUIT s, RANK rank) {
        this->_suit = s;
        this->_rank = rank;
    }

    void Card::setCard(SUIT s, int rank) {
        this->_suit = s;
        this->_rank = static_cast<RANK>(rank);
    }

}