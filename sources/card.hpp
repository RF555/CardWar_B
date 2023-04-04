#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

using namespace std;
namespace ariel {
    enum SUIT {
        HEART = 0, DIAMOND = 1, SPADE = 2, CLUB = 3, SUIT_UNDEFINED = -1
    };
    enum RANK {
        ACE = 1,
        TWO = 2,
        THREE = 3,
        FOUR = 4,
        FIVE = 5,
        SIX = 6,
        SEVEN = 7,
        EIGHT = 8,
        NINE = 9,
        TEN = 10,
        JACK = 11,
        QUEEN = 12,
        KING = 13,
        RANK_UNDEFINED = -1
    };

    class Card {
        SUIT _suit;
        RANK _rank;

    public:

        Card();

        Card(SUIT suit, RANK rank);

        Card(SUIT suit, int rank);

        SUIT getSuit();

        int getRank();

        void setCard(SUIT suit, RANK rank);

        void setCard(SUIT suit, int rank);

        string toString();

        string toStringCol();

        /**
         * @param c A Card instance.
         * @return True if the cards are equal.
         */
        bool equal(Card c);

        Card copy();

    private:
        string suitString();

        string rankString();

    };
}
#endif