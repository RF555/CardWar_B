#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <vector>
#include "card.hpp"

using namespace std;
namespace ariel {

    class Deck {

    public:
        vector <Card> vec;

        Deck() {}

        /**
         * @brief Initiate a full deck of cards.
         */
        void init();

        /**
        * @brief Shuffle the deck using std::shuffle.
        */
        void shuffle();

        /**
         * @brief Add a new Card to the Deck.
         */
        void push(Card _card);

        /**
         * @return Pop and return the first card.
         */
        Card pop();

        /**
         * @return The number of cards left in the deck.
         */
        int size();

        string toString();

        /**
         * @return True if deck is empty.
         */
        bool empty();

    };
}
#endif