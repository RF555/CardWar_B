#include "../sources/game.hpp"

namespace ariel {

    Game::Game(Player _p1, Player _p2) {
        if (_p1.getName() == _p2.getName()) {
            cout << "ERROR! Only 1 player!\n";
            return;
        }
        this->p1 = _p1;
        this->p2 = _p2;
        this->game_deck.init();
//        int i = 1;
//        for (auto &card: this->game_deck.vec) {
//            if (i % 2) {
//                this->p1.pushMyDeck(this->game_deck.peek());
//                ++i;
//            } else {
//                this->p2.pushMyDeck(this->game_deck.peek());
//                ++i;
//            }
//        }
        while (!this->game_deck.isEmpty()) {
            this->p1.pushMyDeck(this->game_deck.pop());
            this->p2.pushMyDeck(this->game_deck.pop());
        }
    }

    void Game::playTurn() {

    }

    void Game::printLastTurn() {}

    void Game::playAll() {}

    void Game::printWiner() {}

    void Game::printLog() {}

    void Game::printStats() {}

    Card Game::popP1() { return this->p1.getMyDeck().pop(); }

    Card Game::popP2() { return this->p2.getMyDeck().pop(); }
}