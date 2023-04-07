#include "../sources/player.hpp"

namespace ariel {

    Player::Player() : name("NoName"), cards_won(new Deck()), my_deck(new Deck()) {}

    Player::Player(string _name) : name(_name), cards_won(new Deck()), my_deck(new Deck()) {}

    Deck &Player::getMyDeck() { return *this->my_deck; }

    int Player::stacksize() { return this->my_deck->size(); }

    int Player::cardesTaken() { return this->cards_won->size(); }

    void Player::addWonCards(Deck &round_cards) {
        for (auto &card: round_cards.vec) {
            this->cards_won->push(card);
        }
    }

    bool Player::pushMyDeck(Card c) {
        return this->my_deck->push(c);
    }

    string Player::getName() { return this->name; }

    Deck &Player::getCardsWon() { return *this->cards_won; }
}