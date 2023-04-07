#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include "../sources/player.hpp"

namespace ariel {

    class Game {

        Player p1, p2;
        Deck game_deck;

    public:

        Game(Player _p1, Player _p2);

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

    private:

        /**
         * @return A card from p1's deck.
         */
        Card popP1();

        /**
         * @return A card from p2's deck.
         */
        Card popP2();

    };
}
#endif