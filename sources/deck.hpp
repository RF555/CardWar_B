#include <iostream>
#include "card.hpp"

using namespace std;
namespace ariel {

    class Deck {
    public:
        Card *d;

        Deck();

        ~Deck();

/**
* @brief Shuffle the array using Fisher–Yates shuffle Algorithm.
*/
        void shuffle();

    private:
        void swap(Card &_a, Card &_b);

    };
}