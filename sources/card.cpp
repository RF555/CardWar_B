#include "../sources/card.hpp"

namespace ariel {
    Card::Card() {
        this->_rank = RANK_UNDEFINED;
        this->_suit = SUIT_UNDEFINED;
    }

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
        if (rank >= 1 && rank <= 13) {
            this->_rank = static_cast<RANK>(rank);
        } else {
            cout << "ERROR! This rank is undefined!\n";
//            cout << "\e[31mbold red text\e[0m\n";
//            cout << "\e[31m\u2665";

            this->_rank = RANK_UNDEFINED;
        }
    }

    string Card::toString() {
        if (this->_suit == HEART) {
            return "\e[31m\u2665" + to_string(this->_rank) + "\e[0m\n";
        } else if (this->_suit == DIAMOND) {
            return "\e[31m\u2666" + to_string(this->_rank) + "\e[0m\n";
        } else if (this->_suit == SPADE) {
            return "\e[30;47m\u2660" + to_string(this->_rank) + "\e[0m\n";
        } else if (this->_suit == CLUB) {
            return "\e[30;47m\u2663" + to_string(this->_rank) + "\e[0m\n";
        } else {
            return "";
        }
    }

}