#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include "../sources/player.hpp"

namespace ariel {

    class Game {

        Player &p1, &p2;
        Deck game_deck;
        int turns;
        int draws;
        vector <string> log;
        string lastWinner;
        bool game_over;

    public:

        Game(Player &_p1, Player &_p2);

        Game(Player &_p1, Player &_p2, Deck &_deck);

        /**
        * @brief Simulate a turn in the game.
         * @throw Exception if game already ended.
        */
        void playTurn();

        /**
        * @brief Prints the last turn stats.
         * @throw Exception if game didnt start yet.
        */
        void printLastTurn();

        /**
        * @brief Plays the game until the end.
        */
        void playAll();

        /**
        * @brief Prints the name of the winning player.
        * @throw Exception if there is no winner yet.
        */
        void printWiner();

        /**
        * @brief Prints all the turns played one line per turn
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

        int drawAmount();
        int turnsPlayed();

    private:

        void cardDraw();

        void determineWinner();

        string roundToString();

    };
}
#endif