#include "../sources/player.hpp"

namespace ariel {

    Player::Player() :
            name("NoName"), cards_won(new Deck()),
            my_deck(new Deck()), my_pit(new Deck()) {
        this->wins = 0;
    }

    Player::Player(string _name) :
            name(_name), cards_won(new Deck()),
            my_deck(new Deck()), my_pit(new Deck()) {
        this->wins = 0;
    }

    Deck &Player::getMyDeck() { return *this->my_deck; }

    int Player::stacksize() { return this->my_deck->size(); }

    int Player::cardesTaken() { return this->cards_won->size(); }

    string Player::getName() { return this->name; }

    Deck &Player::getCardsWon() { return *this->cards_won; }

    bool Player::addWonCards(Deck &opponents_pit) {
        int prev_won = this->cardesTaken();
        int my_pit = this->my_pit->size();
        int opp_pit = opponents_pit.size();
        for (auto &card: opponents_pit.vec) {
            this->cards_won->push(card);
        }
        while (!opponents_pit.isEmpty()) {
            opponents_pit.pop();
        }
        for (auto &card: this->my_pit->vec) {
            this->cards_won->push(card);
        }
        while (!this->my_pit->isEmpty()) {
            this->my_pit->pop();
        }
        return (this->cardesTaken() == prev_won + opp_pit + my_pit)
               && opponents_pit.isEmpty()
               && this->my_pit->isEmpty();
    }

    bool Player::wonRound(ariel::Deck &opponents_pit) {
        ++this->wins;
        return this->addWonCards(opponents_pit);

    }

    bool Player::pushMyDeck(Card c) {
        return this->my_deck->push(c);
    }

    bool Player::drawCard() {
        return this->my_pit->push(this->my_deck->pop());
    }

    Card &Player::flippedCard() { return this->my_pit->peek(); }

    Deck &Player::getMyPit() { return *this->my_pit; }

    string Player::getMyStats(int turns_played) {
        string win_rate = to_string(this->wins / turns_played);
        string turns_lost = to_string(turns_played - this->wins);
        return this->getName() + "'s stats:\n" +
               "\t\tWin rate: " + win_rate + ".\n" +
               "\t\tCards won: " + to_string(this->cardesTaken()) + ".\n" +
               "\t\tTurns won: " + to_string(this->wins) + ".\n" +
               "\t\tTurns won: " + turns_lost + ".\n";
    }

}