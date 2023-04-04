#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "deck.hpp"

using namespace std;
namespace ariel {

    class Player {
    public:

        Player();

        Player(string _name);

        /**
         * @return The name of the player.
         */
        string getName();

        /**
         * @return A reference to the player's won cards pile.
         */
        Deck &getCardsWon();

        /**
         * @return A reference to the player's playing deck.
         */
        Deck &getMyDeck();

        /**
         * @return The amount of cards left to play.
        */
        int stacksize();

        /**
         * @return The amount of cards this player has won.
         */
        int cardesTaken();

        /**
         * Add the won cards to the players pile.
         * @param round_cards
         */
        void addWonCards(Deck &round_cards);

        bool pushMyDeck(Card c);

    private:
        string name;
        Deck cards_won;
        Deck my_deck;
    };
}
#endif