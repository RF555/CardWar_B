#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Card initiated correctly") {
    Card c1;
    CHECK(c1.getRank() == -1);
    CHECK(c1.getSuit() == SUIT_UNDEFINED);
}

TEST_CASE("Function 'setCard' works") {
    Card c1;
    c1.setCard(SPADE, 3);
    CHECK(c1.getRank() == THREE);
    CHECK(c1.getSuit() == SPADE);
    c1.setCard(SPADE, -2);
    CHECK(c1.getRank() == RANK_UNDEFINED);
    CHECK(c1.getSuit() == SPADE);
    cout << c1.toString();
    c1.setCard(HEART, 15);
    CHECK(c1.getRank() == RANK_UNDEFINED);
    CHECK(c1.getSuit() == HEART);
    cout << c1.toString();
    c1.setCard(DIAMOND, 4);
    CHECK(c1.getRank() == FOUR);
    CHECK(c1.getSuit() == DIAMOND);
    cout << c1.toString();
    c1.setCard(CLUB, 1);
    CHECK(c1.getRank() == ACE);
    CHECK(c1.getSuit() == CLUB);
    cout << c1.toString();
}
