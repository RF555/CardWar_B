#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include "../sources/player.hpp"

namespace ariel {

    class Game {

        Player p1, p2;
        Deck game_deck;
        int turns;
        int draws;
        vector <string> log;
        string lastWinner;

    public:

        Game(Player _p1, Player _p2);

        /**
        * @brief Simulate a turn in the game.
         * @throw Exception if game already ended.
        */
        void playTurn();

        /**
        * @brief Print the last turn stats.
         * @throw Exception if game didnt start yet.
        */
        void printLastTurn();

        /**
        * @brief Plays the game until the end.
        */
        void playAll();

        /**
        * @brief Print the name of the winning player.
        * @throw Exception if there is no winner yet.
        */
        void printWiner();

        /**
        * @brief Print all the turns played one line per turn
        * (same format as game.printLastTurn()).
        * @throw Exception if game didnt start yet.
        */
        void printLog();

        /**
        * @brief For each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand.
        * (draw within a draw counts as 2 draws. ).
        * @throw Exception if game didnt start yet.
        */
        void printStats();

        /**
         * @return The size of 'game_deck'.
         */
        int deckSize();

    private:

        void cardDraw();

        void determineWinner();

        string roundToString();

    };
}
#endif