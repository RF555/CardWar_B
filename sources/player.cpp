#include "../sources/player.hpp"

namespace ariel {

    Player::Player() :
            name("NoName"), cards_won(new Deck()), my_deck(new Deck()), my_pit(new Deck()) {}

    Player::Player(string _name) :
            name(_name), cards_won(new Deck()), my_deck(new Deck()), my_pit(new Deck()) {}

    Deck &Player::getMyDeck() { return *this->my_deck; }

    int Player::stacksize() { return this->my_deck->size(); }

    int Player::cardesTaken() { return this->cards_won->size(); }

    bool Player::addWonCards(Deck &round_cards) {
        int prev_won = this->cardesTaken();
        for (auto &card: round_cards.vec) {
            this->cards_won->push(card);
        }
        return this->cardesTaken() == prev_won + round_cards.size();
    }

    bool Player::pushMyDeck(Card c) {
        return this->my_deck->push(c);
    }

    string Player::getName() { return this->name; }

    Deck &Player::getCardsWon() { return *this->cards_won; }
}