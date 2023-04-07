#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Player initiated correctly") {
    Player p1;
    CHECK(p1.getName() == "NoName");
    CHECK(p1.cardesTaken() == 0);
    CHECK(p1.getCardsWon().isEmpty());
    CHECK(p1.stacksize() == 0);
    Player p2("Roey");
    CHECK(p2.getName() == "Roey");
    CHECK(p2.cardesTaken() == 0);
    CHECK(p2.getCardsWon().isEmpty());
    CHECK(p2.stacksize() == 0);
}

TEST_CASE("Check addWonCards & cardesTaken") {
    Player p1("Roey");
    Deck d;
    d.init();
    for (int i = 0; i < 14; ++i) {
        d.pop();
    }
    CHECK(d.size() == 38);
    CHECK(p1.addWonCards(d));
    CHECK(p1.cardesTaken() == 38);
}