#include "../sources/player.hpp"

namespace ariel {

    Player::Player() { this->name = "NoName"; }

    Player::Player(string _name) { this->name = _name; }

    int Player::stacksize() { return 0; }

    int Player::cardesTaken() { return 0; }
}