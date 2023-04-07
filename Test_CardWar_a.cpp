#include "doctest.h"

using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace ariel;

TEST_CASE("Starting point is legit") {
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p1.getName() == "Alice");
    CHECK(p2.getName() == "Bob");
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    Game game(p1, p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Game finished correctly") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
    CHECK(p1.cardesTaken() != p2.cardesTaken());
}

TEST_CASE("Game play") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    int p1_wi = p1.cardesTaken(); // Cards p1 has won
    int p2_wi = p2.cardesTaken(); // Cards p2 has won
    int p1_ci = p1.stacksize(); // Cards p1 has left to play
    int p2_ci = p2.stacksize(); // Cards p2 has left to play
    game.playTurn();
    CHECK(p1.stacksize() < p1_ci);
    CHECK(p2.stacksize() < p2_ci);
    CHECK(p2.stacksize() == p1.stacksize());
    CHECK(p1.cardesTaken() >= p1_wi);
    CHECK(p2.cardesTaken() >= p2_wi);
    for (int i = 0; i < 10; ++i) {
        p1_wi = p1.cardesTaken();
        p2_wi = p2.cardesTaken();
        p1_ci = p1.stacksize();
        p2_ci = p2.stacksize();
        game.playTurn();
        CHECK(p1.stacksize() < p1_ci);
        CHECK(p2.stacksize() < p2_ci);
        CHECK(p2.stacksize() == p1.stacksize());
        CHECK(p1.cardesTaken() >= p1_wi);
        CHECK(p2.cardesTaken() >= p2_wi);
    }

}