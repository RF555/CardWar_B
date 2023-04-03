#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
//#include "card.hpp"

using namespace std;
namespace ariel {

    class Player {
    public:
        string name;
//    Card deck;

        Player();

        Player(string _name);

//        ~Player() {}

/**
 * @return The amount of cards left in the to play.
*/
//        int stacksize() { return 0; }
        int stacksize();

/**
 * @return The amount of cards this player has won.
 */
//        int cardesTaken() { return 0; }
        int cardesTaken();

    };
}
#endif