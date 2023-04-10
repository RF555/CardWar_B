#include <algorithm>
#include <random>
#include "../sources/deck.hpp"

namespace ariel {

    void Deck::init() {
        if (!this->vec.empty()) {
            this->vec.clear();
        }
        for (int i = 0; i < 13; ++i) {
            this->push(Card(HEART, i + 1));
            this->push(Card(DIAMOND, i + 1));
            this->push(Card(SPADE, i + 1));
            this->push(Card(CLUB, i + 1));
        }
    }

    bool Deck::push(Card _card) {
        int prev_size = this->size();
        if (!cardExists(_card)) {
            this->vec.push_back(_card);
            return prev_size + 1;
        } else {
            cout << "The Card " + _card.toString() + " already exists!\n";
            return false;
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
        auto rd = std::random_device {};
        auto rng = std::default_random_engine{rd()};
        std::shuffle(begin(this->vec), end(this->vec), rng);
    }

    bool Deck::isEmpty() { return this->vec.empty(); }

    bool Deck::cardExists(Card _card) {
        for (auto &card: this->vec) {
            if (card.equal(_card)) {
                return true;
            }
        }
        return false;
    }

    Card &Deck::peek() {
        return this->vec.back();
    }
}