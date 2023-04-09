#include "../sources/game.hpp"

namespace ariel {

    Game::Game(Player &_p1, Player &_p2) : p1(_p1), p2(_p2), turns(0), draws(0), game_over(false) {
        if (_p1.getName() == _p2.getName()) {
            throw "ERROR! Only 1 player!\n";
        }
        this->game_deck.init();
        this->game_deck.shuffle();
        while (!this->game_deck.isEmpty()) {
            this->p1.pushMyDeck(this->game_deck.pop());
            this->p2.pushMyDeck(this->game_deck.pop());
        }
    }

    Game::Game(Player &_p1, Player &_p2, Deck &_deck) : p1(_p1), p2(_p2), game_deck(_deck),
                                                        turns(0), draws(0), game_over(false) {
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
//        if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
        if (this->game_over) {
            throw "Game has already ended!\n";
        }
        this->p1.drawCard();
        this->p2.drawCard();
        ++this->turns;
        this->log.push_back(this->roundToString());
        if (this->p1.flippedCard().getRank() == this->p2.flippedCard().getRank()) {
            // draw:
//            this->log.back() = this->log.back() + " Draw1.";
            this->log.back() = this->log.back();
            this->cardDraw();
        } else {
            this->determineWinner();
        }
        this->log.back() = this->log.back() + " " + this->lastWinner + " wins.";
        if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
            this->game_over = true;
        }
//        cout << this->log.back() + "\n";
    }

    void Game::cardDraw() {
        ++this->draws;
        if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
            this->log.back() = this->log.back() + " " + this->roundToString() + " Tie!.";
            return;
        }
        this->p1.drawCard();
        this->p2.drawCard();
        if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
            this->determineWinner();
            this->log.back() = " (last card) " + this->log.back() + " " + this->roundToString();
            return;
        }
        this->p1.drawCard();
        this->p2.drawCard();
        if (this->p1.flippedCard().getRank() != this->p2.flippedCard().getRank()) {
            this->log.back() = this->log.back() + " " + this->roundToString();
            this->determineWinner();
            return;
        }
        while (this->p1.flippedCard().getRank() == this->p2.flippedCard().getRank()) {
            ++this->draws;
            this->log.back() = this->log.back() + " Draw. ";
            if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
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
                this->lastWinner = this->p1.getName();
            } else {
                // p2 wins:
                this->p2.wonRound(this->p1.getMyPit());
                this->lastWinner = this->p2.getName();
            }
        } else if (this->p1.flippedCard().getRank() > this->p2.flippedCard().getRank()) {
            // p1 wins:
            this->p1.wonRound(this->p2.getMyPit());
            this->lastWinner = this->p1.getName();
        } else if (this->p1.flippedCard().getRank() < this->p2.flippedCard().getRank()) {
            // p2 wins:
            this->p2.wonRound(this->p1.getMyPit());
            this->lastWinner = this->p2.getName();
        } else throw "Unable to determine.\n";
    }

    void Game::printLastTurn() {}

    void Game::playAll() {
        while (!this->game_over) {
            this->playTurn();
        }
    }

    void Game::printWiner() {
        if (!this->game_over) {
            throw "Game not over yet!\n";
        }
        if (this->p1.cardesTaken() > this->p2.cardesTaken()) {
            cout << this->p1.getName() + "\n";
        } else if (this->p1.cardesTaken() < this->p2.cardesTaken()) {
            cout << this->p2.getName() + "\n";
        } else {
            cout << "It's a tie!\n";
        }
    }

    void Game::printLog() {
//        cout << "log:\n";
        int i = 0;
        for (auto &turn: this->log) {
            cout << to_string(++i) + ": " + turn + "\n";
        }
    }

    int Game::drawAmount() { return this->draws; }

    int Game::turnsPlayed() { return this->turns; }

    void Game::printStats() {
        string draw_rate = to_string(this->draws / this->turns);
        cout << "Game stats:\n" +
                "\t\tTurns played: " + to_string(this->turns) + ".\n" +
                "\t\tDraw rate: " + draw_rate + ".\n" +
                "\t\tTotal draws: " + to_string(this->draws) + ".\n";
        cout << this->p1.getMyStats(this->turns);
        cout << this->p2.getMyStats(this->turns);

    }

    int Game::deckSize() { return this->game_deck.size(); }
}