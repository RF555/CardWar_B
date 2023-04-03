#include <iostream>
#include <vector>
#include "card.hpp"

using namespace std;
namespace ariel {

    class Deck {

    public:
        vector <Card> vec;

        Deck(){}

        void init();

/**
* @brief Shuffle the deck using std::shuffle.
*/
        void shuffle();

        void push(Card _card);

        Card pop();

        int cardsLeft();

        string toString();

    private:
        void swap(Card &_a, Card &_b);
    };
}