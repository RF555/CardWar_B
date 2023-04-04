#include "../sources/card.hpp"

namespace ariel {
    Card::Card() {
        this->_rank = RANK_UNDEFINED;
        this->_suit = SUIT_UNDEFINED;
    }

    Card::Card(SUIT suit, RANK rank) {
        this->_suit = suit;
        this->_rank = rank;
    }

    Card::Card(ariel::SUIT suit, int rank) {
        this->_suit = suit;
        if (rank >= 1 && rank <= 13) {
            this->_rank = static_cast<RANK>(rank);
        } else {
            cout << "ERROR! This rank is undefined!\n";
            this->_rank = RANK_UNDEFINED;
        }
    }

    SUIT Card::getSuit() { return this->_suit; }

    int Card::getRank() { return this->_rank; }

    void Card::setCard(SUIT suit, RANK rank) {
        this->_suit = suit;
        this->_rank = rank;
    }

    void Card::setCard(SUIT suit, int rank) {
        this->_suit = suit;
        if (rank >= 1 && rank <= 13) {
            this->_rank = static_cast<RANK>(rank);
        } else {
            cout << "ERROR! This rank is undefined!\n";
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

    bool Card::equal(Card c) {
        return (this->_rank == c.getRank()) && (this->_suit == c.getSuit());
    }

}