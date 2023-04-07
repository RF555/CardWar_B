#include "../sources/game.hpp"

namespace ariel {

    Game::Game(Player _p1, Player _p2) : turns(0), draws(0) {
        if (_p1.getName() == _p2.getName()) {
            throw "ERROR! Only 1 player!\n";
        }
        this->p1 = _p1;
        this->p2 = _p2;
        this->game_deck.init();
        this->game_deck.shuffle();
        while (!this->game_deck.isEmpty()) {
            this->p1.pushMyDeck(this->game_deck.pop());
            this->p2.pushMyDeck(this->game_deck.pop());
        }
    }

    string Game::roundToString() {
        return this->p1.getName() + " played " + this->p1.flippedCard().toString() + " "
               + this->p2.getName() + " played " + this->p2.flippedCard().toString() + ".";
    }

    void Game::playTurn() {
        if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
            throw "Game has already ended!\n";
        }
        this->p1.drawCard();
        this->p2.drawCard();
        ++this->turns;
        this->log.push_back(this->roundToString());
        if (this->p1.flippedCard().getRank() == this->p2.flippedCard().getRank()) {
            // draw:
            this->log.back() = this->log.back() + " Draw. ";
            this->cardDraw();
        } else {
            this->determineWinner();
        }
        this->log.back() = this->log.back() + " " + this->lastWinner + " wins.";
    }

    void Game::cardDraw() {
        ++this->draws;
        if (this->p1.stacksize() < 2 || this->p2.stacksize() < 2) {
            throw "Not enough cards left!\n";
        }
        this->p1.drawCard();
        this->p1.drawCard();
        this->p2.drawCard();
        this->p2.drawCard();
        if (this->p1.flippedCard().getRank() != this->p2.flippedCard().getRank()) {
            this->determineWinner();
            this->log.back() = this->log.back() + " " + this->roundToString();
        }
        while (this->p1.flippedCard().getRank() == this->p2.flippedCard().getRank()) {
            this->log.back() = this->log.back() + " Draw. ";
            if (this->p1.stacksize() < 1 || this->p2.stacksize() < 1) {
                throw "Not enough cards to continue!\n";
            }
            this->p1.drawCard();
            this->p2.drawCard();
            if (this->p1.flippedCard().getRank() != this->p2.flippedCard().getRank()) {
                this->log.back() = this->log.back() + this->roundToString();
                this->determineWinner();
                break;
            }
        }
    }

    void Game::determineWinner() {
        if (this->p1.flippedCard().getRank() == ACE) {
            if (this->p2.flippedCard().getRank() == TWO) {
                // p2 wins:
                this->p2.wonRound(this->p1.getMyPit());
                this->lastWinner = this->p2.getName();
            } else {
                // p1 wins:
                this->p1.wonRound(this->p2.getMyPit());
                this->lastWinner = this->p1.getName();
            }
        } else if (this->p2.flippedCard().getRank() == ACE) {
            if (this->p1.flippedCard().getRank() == TWO) {
                // p1 wins:
                this->p1.wonRound(this->p2.getMyPit());
                this->lastWinner = this->p2.getName();
            } else {
                // p2 wins:
                this->p2.wonRound(this->p1.getMyPit());
                this->lastWinner = this->p2.getName();
            }
        } else if (this->p1.flippedCard().getRank() > this->p2.flippedCard().getRank()) {
            // p1 wins:
            this->p1.wonRound(this->p2.getMyPit());
            this->lastWinner = this->p2.getName();
        } else if (this->p1.flippedCard().getRank() < this->p2.flippedCard().getRank()) {
            // p2 wins:
            this->p2.wonRound(this->p1.getMyPit());
            this->lastWinner = this->p2.getName();
        } else throw "Unable to determine.\n";
    }

    void Game::printLastTurn() {}

    void Game::playAll() {
        while (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
            this->playTurn();
        }
    }

    void Game::printWiner() {}

    void Game::printLog() {}

    void Game::printStats() {}

    int Game::deckSize() { return this->game_deck.size(); }
}