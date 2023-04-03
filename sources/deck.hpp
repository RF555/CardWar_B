#include <iostream>
#include <vector>
#include "card.hpp"

using namespace std;
namespace ariel {

    class Deck {

    public:
        vector <Card> vec;

        Deck();

//        ~Deck();

/**
* @brief Shuffle the deck using std::shuffle.
*/
        void shuffle();

        Card pop();

        int cardsLeft();

        string toString();

    private:
        void swap(Card &_a, Card &_b);
    };
}