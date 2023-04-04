#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "../sources/player.hpp"

namespace ariel {

    class Game {
    public:
        Player p1, p2;
//    Card deck[52];

        Game(Player _p1, Player _p2);

//        ~Game();

/**
* @brief Simulate a turn in the game.
*/
        void playTurn();

/**
* @brief Print the last turn stats.
*/
        void printLastTurn();

/**
* @brief Plays the game until the end.
*/
        void playAll();

/**
* @brief Print the name of the winning player.
*/
        void printWiner();

/**
* @brief Print all the turns played one line per turn
     * (same format as game.printLastTurn()).
*/
        void printLog();

/**
* @brief For each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand.
     * (draw within a draw counts as 2 draws. ).
*/
        void printStats();

    };
}
#endif