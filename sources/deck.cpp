#include <time.h>
#include "../sources/deck.hpp"

namespace ariel {

    Deck::Deck() {
        this->d = new Card[52];
        for (int i = 0; i < 13; ++i) {
            this->d[i].setCard(HEART, i + 1);
        }
        for (int i = 0; i < 13; ++i) {
            this->d[i + 13].setCard(DIAMOND, i + 1);
        }
        for (int i = 0; i < 13; ++i) {
            this->d[i + 26].setCard(SPADE, i + 1);
        }
        for (int i = 0; i < 13; ++i) {
            this->d[i + 39].setCard(CLUB, i + 1);
        }
    }

    Deck::~Deck() { delete[] d; }

    void Deck::swap(Card &_a, Card &_b) {
        Card temp = _a;
        _a = _b;
        _b = temp;
    }

    void Deck::shuffle() {
        srand(time(0));
        for (int i = 0; i < 52; ++i) {
            int j = i + (rand() % (52 - i));
            swap(d[i], d[j]);
        }

    }
}