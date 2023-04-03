#include <algorithm>
#include <random>
#include "../sources/deck.hpp"

namespace ariel {

    void Deck::push(ariel::Card _card) { this->vec.push_back(_card); }

    void Deck::init() {
        if (!this->vec.empty()) {
            this->vec.clear();
        }
        for (int i = 0; i < 13; ++i) {
            this->push(Card(HEART, i + 1));
        }
        for (int i = 0; i < 13; ++i) {
            this->push(Card(DIAMOND, i + 1));
        }
        for (int i = 0; i < 13; ++i) {
            this->push(Card(SPADE, i + 1));
        }
        for (int i = 0; i < 13; ++i) {
            this->push(Card(CLUB, i + 1));
        }
    }

    Card Deck::pop() {
        Card temp = this->vec.back();
        this->vec.pop_back();
        return temp;
    }

    int Deck::size() { return this->vec.size(); }

    string Deck::toString() {
        string st = "Deck:\n{";
        for (auto &card: this->vec) {
            st = st + card.toString();
            if (this->vec.back().toString() == card.toString()) {
                st = st + ", ";
            }
        }
        return st;
    }

    void Deck::shuffle() {
        auto rng = std::default_random_engine{};
        std::shuffle(begin(this->vec), end(this->vec), rng);
    }
}