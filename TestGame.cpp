#include "doctest.h"
#include <stdexcept>
#include "sources/game.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Game initiated correctly") {
    Player p1("Roey");
    Player p2("Ido");
    Game game(p1, p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(game.deckSize() == 0);
    game.playAll();
}
