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

    bool Card::equal(Card c) {
        return (this->_rank == c.getRank()) && (this->_suit == c.getSuit());
    }

    string Card::toStringCol() {
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

    string Card::suitString() {
        switch (this->getSuit()) {
            case HEART:
                return "Hearts";
            case DIAMOND:
                return "Diamonds";
            case CLUB:
                return "Clubs";
            case SPADE:
                return "Spades";
            case SUIT_UNDEFINED:
                return "SUIT_UNDEFINED";
        }
    }

    string Card::rankString() {
        switch (this->_rank) {
            case ACE:
                return "Ace";
            case TWO:
                return "2";
            case THREE:
                return "3";
            case FOUR:
                return "4";
            case FIVE:
                return "5";
            case SIX:
                return "6";
            case SEVEN:
                return "7";
            case EIGHT:
                return "8";
            case NINE:
                return "9";
            case TEN:
                return "10";
            case JACK:
                return "Jack";
            case QUEEN:
                return "Queen";
            case KING:
                return "King";
            case RANK_UNDEFINED:
                return "RANK_UNDEFINED";
        }
    }

    string Card::toString() {
        return rankString() + " of " + suitString();
    }

}