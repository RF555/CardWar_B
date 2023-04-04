#include "doctest.h"
#include <stdexcept>
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Card initiated correctly") {
    Card c1;
    CHECK(c1.getRank() == -1);
    CHECK(c1.getSuit() == SUIT_UNDEFINED);
    Card c2(SPADE, 2);
    CHECK(c2.getSuit() == SPADE);
    CHECK(c2.getRank() == TWO);
    Card c3(HEART, 3);
    CHECK(c3.getSuit() == HEART);
    CHECK(c3.getRank() == THREE);
    Card c4(DIAMOND, 4);
    CHECK(c4.getSuit() == DIAMOND);
    CHECK(c4.getRank() == FOUR);
}

TEST_CASE("Function 'setCard' works") {
    Card c1;
    c1.setCard(SPADE, 3);
    CHECK(c1.getRank() == THREE);
    CHECK(c1.getSuit() == SPADE);
    c1.setCard(SPADE, -2);
    CHECK(c1.getRank() == RANK_UNDEFINED);
    CHECK(c1.getSuit() == SPADE);
//    cout << c1.toString();
    c1.setCard(HEART, 15);
    CHECK(c1.getRank() == RANK_UNDEFINED);
    CHECK(c1.getSuit() == HEART);
//    cout << c1.toString();
    c1.setCard(DIAMOND, 4);
    CHECK(c1.getRank() == FOUR);
    CHECK(c1.getSuit() == DIAMOND);
//    cout << c1.toString();
    c1.setCard(CLUB, 1);
    CHECK(c1.getRank() == ACE);
    CHECK(c1.getSuit() == CLUB);
//    cout << c1.toString();
}

TEST_CASE("Check equal") {
    Card c1;
    Card c11(SUIT_UNDEFINED, RANK_UNDEFINED);
    Card c2(SPADE, 2);
    Card c22(SPADE, TWO);
    Card c3(HEART, 3);
    Card c33(HEART, THREE);
    Card c4(DIAMOND, 4);
    Card c44(DIAMOND, FOUR);
    CHECK(c1.equal(c11));
    CHECK(c2.equal(c22));
    CHECK(c3.equal(c33));
    CHECK(c4.equal(c44));
    CHECK(c11.equal(c1));
    CHECK(c22.equal(c2));
    CHECK(c33.equal(c3));
    CHECK(c44.equal(c4));
    CHECK_FALSE(c1.equal(c2));
    CHECK_FALSE(c1.equal(c3));
    CHECK_FALSE(c1.equal(c4));
    CHECK_FALSE(c2.equal(c1));
    CHECK_FALSE(c2.equal(c3));
    CHECK_FALSE(c2.equal(c4));
    CHECK_FALSE(c3.equal(c2));
    CHECK_FALSE(c3.equal(c1));
    CHECK_FALSE(c3.equal(c4));
    CHECK_FALSE(c4.equal(c2));
    CHECK_FALSE(c4.equal(c3));
    CHECK_FALSE(c4.equal(c1));
}
