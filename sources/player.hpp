#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "deck.hpp"

using namespace std;
namespace ariel {

    class Player {
        string name;
        /** Cards the player has won. */
        Deck *cards_won;
        /** Player's playing deck. */
        Deck *my_deck;
        /** Player's pit pile contains the cards drawn this round. */
        Deck *my_pit;

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
         * @return True if all cards added successfully.
         */
        bool addWonCards(Deck &round_cards);

        /**
         * @param c Card added to the players deck.
         * @return True if added successfully.
         */
        bool pushMyDeck(Card c);


    };
}
#endif