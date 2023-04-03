#include <time.h>
#include <algorithm>
#include <random>
#include "../sources/deck.hpp"

namespace ariel {

    Deck::Deck() {
        for (int i = 0; i < 13; ++i) {
            this->vec.push_back(Card(HEART, i + 1));
//            this->d[i].setCard(HEART, i + 1);
        }
        for (int i = 0; i < 13; ++i) {
            this->vec.push_back(Card(DIAMOND, i + 1));
//            this->d[i + 13].setCard(DIAMOND, i + 1);
        }
        for (int i = 0; i < 13; ++i) {
            this->vec.push_back(Card(SPADE, i + 1));
//            this->d[i + 26].setCard(SPADE, i + 1);
        }
        for (int i = 0; i < 13; ++i) {
            this->vec.push_back(Card(CLUB, i + 1));
//            this->d[i + 39].setCard(CLUB, i + 1);
        }
    }

    Card Deck::pop() {
        Card temp = this->vec.back();
        this->vec.pop_back();
        return temp;
    }

    int Deck::cardsLeft() { return this->vec.size(); }

    string Deck::toString() {
        string st = "Deck:\n{";
//        for (int i = 0; i < this->vec.size(); ++i) {
//            st = st + this->vec[i].toString();
//            if (this->vec.size() > i + 1) {
//                st = st + ", ";
//            }
//        }

        for (auto &card: this->vec) {
            st = st + card.toString();
            if (this->vec.back().toString() == card.toString()) {
                st = st + ", ";
            }
        }

        return st;
    }


    void Deck::swap(Card &_a, Card &_b) {
        Card temp = _a;
        _a = _b;
        _b = temp;
    }

//    void Deck::shuffle() {
//        srand(time(0));
//        for (int i = 0; i < 52; ++i) {
//            int j = i + (rand() % (52 - i));
//            swap(d[i], d[j]);
//        }
//    }

    void Deck::shuffle() {
        auto rng = std::default_random_engine{};
        std::shuffle(begin(this->vec), end(this->vec), rng);
    }
}