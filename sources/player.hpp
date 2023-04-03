#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "deck.hpp"

using namespace std;
namespace ariel {

    class Player {
    public:
        string name;
        Deck cards_won;
        Deck *game_deck;

        Player();

        Player(string _name);

/**
 * Point game_deck to the actual game's deck.
 * @param _deck Pointer of the game's deck.
 */
        void setGameDeck(Deck *_deck);

/**
 * @return The amount of cards left to play.
*/
        int stacksize();

/**
 * @return The amount of cards this player has won.
 */
        int cardesTaken();

    };
}
#endif