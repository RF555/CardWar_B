#include "../sources/game.hpp"

namespace ariel {

    Game::Game(Player &_p1, Player &_p2) : p1(_p1), p2(_p2), turns(0), draws(0), game_over(false) {
//        if (_p1.getName() == _p2.getName()) {
//            throw logic_error{"ERROR! Only 1 player!\n"};
//        }
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
        if ((this->p1.getName() == this->p2.getName()) || (&this->p1 == &this->p2)) {
            throw logic_error("ERROR! Only 1 player!\n");
        }
        if (this->game_over) {
            throw "Game has already ended!\n";
        }
        this->p1.drawCard();
        this->p2.drawCard();
        ++this->turns;
        this->log.push_back(this->roundToString());
        if (this->p1.flippedCard().getRank() == this->p2.flippedCard().getRank()) {
            // Draw:
            ++this->draws;
            this->log.back() = this->log.back() + " Draw1. ";
            if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
                // No more cards left so each player 'wins' his card:
                this->log.back() = this->log.back() + " Tie!.";
                this->p1.addWonCards(this->p1.getMyPit());
                this->p2.addWonCards(this->p2.getMyPit());
                this->lastWinner = "Tie!.";
            } else {
                this->p1.drawCard();
                this->p2.drawCard();

                this->cardDraw();
            }
        } else {
            // Not a draw:
            this->determineWinner();
        }
        this->log.back() = this->log.back() + " " + this->lastWinner + " wins.";
        if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
            this->game_over = true;
        }
    }

    void Game::cardDraw() {
        if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
            this->log.back() = this->log.back() + " " + this->roundToString();
            if (this->p1.flippedCard().getRank() == this->p2.flippedCard().getRank()) {
                // Draw AGAIN!
                ++this->draws;
                this->p1.addWonCards(this->p1.getMyPit());
                this->p2.addWonCards(this->p2.getMyPit());
                this->lastWinner = "Last Card Tie!.";
                return;
            } else {
                this->determineWinner();
                return;
            }
        } else {
            this->p1.drawCard();
            this->p2.drawCard();
            this->log.back() = this->log.back() + this->roundToString();
            if (this->p1.flippedCard().getRank() != this->p2.flippedCard().getRank()) {
                this->determineWinner();
                return;
            }
            while (this->p1.flippedCard().getRank() == this->p2.flippedCard().getRank()) {
                ++this->draws;
                this->p1.drawCard();
                this->p2.drawCard();
                this->log.back() = this->log.back() + " Draw2. " + this->roundToString();
                if (this->p1.flippedCard().getRank() != this->p2.flippedCard().getRank()) {
                    this->determineWinner();
                    return;
                }
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

    string Game::getWinner() {
        if (this->p1.cardesTaken() > this->p2.cardesTaken()) {
            return this->p1.getName();
        } else if (this->p1.cardesTaken() < this->p2.cardesTaken()) {
            return this->p2.getName();
        } else {
            return "It's a tie!";
        }
    }

    void Game::printWiner() {
//        if (!this->game_over) {
//            throw "Game not over yet!\n";
//        }
        cout << this->getWinner() + "\n";
    }

    void Game::printLog() {
//        cout << "log:\n";
        int i = 0;
        for (auto &turn: this->log) {
            cout << to_string(++i) + ": " + turn + "\n";
//            cout << turn + "\n";
        }
    }

    int Game::drawAmount() { return this->draws; }

    int Game::turnsPlayed() { return this->turns; }

    void Game::printStats() {
        double draw_rate = static_cast<double>(this->draws) / this->turns;
        string game_stats = "Game stats:\n"
                            "\tTurns played: " + to_string(this->turns) + ".\n" +
                            "\tDraw rate: " + to_string(draw_rate) + ".\n" +
                            "\tTotal draws: " + to_string(this->draws) + ".\n";
        if (this->game_over) {
            game_stats = game_stats + "\tWinner: ";
        } else {
            game_stats = game_stats + "\tLeading player: ";
        }
        game_stats = game_stats + this->getWinner() + "\n";
        cout << game_stats;
        cout << this->p1.getMyStats(this->turns);
        cout << this->p2.getMyStats(this->turns);

    }

    int Game::deckSize() { return this->game_deck.size(); }
}