#include "../sources/player.hpp"

namespace ariel {

    Player::Player() { this->name = "NoName"; }

    Player::Player(string _name) { this->name = _name; }

    int Player::stacksize() { return this->game_deck->size(); }

    int Player::cardesTaken() { return this->cards_won.size(); }

    void Player::setGameDeck(Deck *_deck) { this->game_deck = _deck; }

}