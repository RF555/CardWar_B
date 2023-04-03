#include "doctest.h"
#include <stdexcept>
#include "sources/deck.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Deck initiated correctly") {
    Deck d;
    d.init();
    CHECK(d.cardsLeft() == 52);
}

TEST_CASE("Check each SUIT has 13 cards") {
    Deck d;
    d.init();
    int _HEART = 0;
    int _SPADE = 0;
    int _DIAMOND = 0;
    int _CLUB = 0;
    for (auto &card: d.vec) {
        if (card.getSuit() == HEART) {
            ++_HEART;
        } else if (card.getSuit() == SPADE) {
            ++_SPADE;
        } else if (card.getSuit() == DIAMOND) {
            ++_DIAMOND;
        } else if (card.getSuit() == CLUB) {
            ++_CLUB;
        }
    }
    CHECK(_HEART == 13);
    CHECK(_DIAMOND == 13);
    CHECK(_SPADE == 13);
    CHECK(_CLUB == 13);
}

TEST_CASE("Check each RANK has 4 cards") {
    Deck d;
    d.init();
    int _ACE = 0;
    int _TWO = 0;
    int _THREE = 0;
    int _FOUR = 0;
    int _FIVE = 0;
    int _SIX = 0;
    int _SEVEN = 0;
    int _EIGHT = 0;
    int _NINE = 0;
    int _TEN = 0;
    int _JACK = 0;
    int _QUEEN = 0;
    int _KING = 0;
    for (auto &card: d.vec) {
        if (card.getRank() == 1) {
            ++_ACE;
        } else if (card.getRank() == 2) {
            ++_TWO;
        } else if (card.getRank() == 3) {
            ++_THREE;
        } else if (card.getRank() == 4) {
            ++_FOUR;
        } else if (card.getRank() == 5) {
            ++_FIVE;
        } else if (card.getRank() == 6) {
            ++_SIX;
        } else if (card.getRank() == 7) {
            ++_SEVEN;
        } else if (card.getRank() == 8) {
            ++_EIGHT;
        } else if (card.getRank() == 9) {
            ++_NINE;
        } else if (card.getRank() == 10) {
            ++_TEN;
        } else if (card.getRank() == 11) {
            ++_JACK;
        } else if (card.getRank() == 12) {
            ++_QUEEN;
        } else if (card.getRank() == 13) {
            ++_KING;
        }
    }
    CHECK(_ACE == 4);
    CHECK(_TWO == 4);
    CHECK(_THREE == 4);
    CHECK(_FOUR == 4);
    CHECK(_FIVE == 4);
    CHECK(_SIX == 4);
    CHECK(_SEVEN == 4);
    CHECK(_EIGHT == 4);
    CHECK(_NINE == 4);
    CHECK(_TEN == 4);
    CHECK(_JACK == 4);
    CHECK(_QUEEN == 4);
    CHECK(_KING == 4);
}

TEST_CASE("Check shuffle") {
    Deck d;
    d.init();
    string st1 = d.toString();
    d.shuffle();
    string st2 = d.toString();
    CHECK(st1 != st2);
    d.shuffle();
    string st3 = d.toString();
    CHECK(st1 != st3);
    CHECK(st3 != st2);
    d.shuffle();
    string st4 = d.toString();
    CHECK(st4 != st2);
    CHECK(st1 != st4);
    CHECK(st4 != st3);
}

TEST_CASE("Check pop"){
    Deck d;
    d.init();
    CHECK(d.cardsLeft()==52);
    d.pop();
    CHECK(d.cardsLeft()==51);
    d.pop();
    CHECK(d.cardsLeft()==50);
    d.pop();
    CHECK(d.cardsLeft()==49);
    d.pop();
    CHECK(d.cardsLeft()==48);
    d.pop();
    CHECK(d.cardsLeft()==47);
    d.pop();
    CHECK(d.cardsLeft()==46);
}
