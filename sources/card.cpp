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

    Card Card::copy() {
        Card c(this->getSuit(), this->_rank);
        return c;
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
        if (this->_suit == HEART)
            return "Hearts";
        else if (this->_suit == DIAMOND)
            return "Diamonds";
        else if (this->_suit == CLUB)
            return "Clubs";
        else if (this->_suit == SPADE)
            return "Spades";
        else
            return "SUIT_UNDEFINED";
    }


    string Card::rankString() {
        if (this->_rank == ACE)
            return "Ace";
        else if (this->_rank == TWO)
            return "2";
        else if (this->_rank == THREE)
            return "3";
        else if (this->_rank == FOUR)
            return "4";
        else if (this->_rank == FIVE)
            return "5";
        else if (this->_rank == SIX)
            return "6";
        else if (this->_rank == SEVEN)
            return "7";
        else if (this->_rank == EIGHT)
            return "8";
        else if (this->_rank == NINE)
            return "9";
        else if (this->_rank == TEN)
            return "10";
        else if (this->_rank == JACK)
            return "Jack";
        else if (this->_rank == QUEEN)
            return "Queen";
        else if (this->_rank == KING)
            return "King";
        else
            return to_string(this->_rank);
//            return "RANK_UNDEFINED";

    }


    string Card::toString() {
        return rankString() + " of " + suitString();
    }

}