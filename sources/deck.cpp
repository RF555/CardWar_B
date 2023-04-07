#include <algorithm>
#include <random>
#include "../sources/deck.hpp"

namespace ariel {

    bool Deck::push(ariel::Card _card) {
        if (!cardExists(_card)) {
            this->vec.push_back(_card);
            return true;
        } else {
            cout << "The Card " + _card.toString() + " already exists!\n";
            return false;
        }
    }

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

    bool Deck::isEmpty() { return this->vec.empty(); }

    bool Deck::cardExists(Card c) {
        for (auto &card: this->vec) {
            if (card.equal(c)) {
                return true;
            }
        }
        return false;
    }

    Card &Deck::peek() {
        return this->vec.back();
    }
}