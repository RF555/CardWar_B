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
//    cout << "Before:\n";
//    cout << "p1.stacksize() = " + to_string(p1.stacksize()) + "\n";
//    cout << "p2.stacksize() = " + to_string(p2.stacksize()) + "\n\n";
    game.playAll();
//    game.printLog();
//    cout << to_string(game.drawAmount()) + "\n";
//    cout << to_string(game.turnsPlayed()) + "\n";
//    cout << "\nAfter:\n";
//    cout << "p1.stacksize() = " + to_string(p1.stacksize()) + "\n";
//    cout << "p2.stacksize() = " + to_string(p2.stacksize()) + "\n";
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
//    CHECK(p1.cardesTaken() != p2.cardesTaken());
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

TEST_CASE("Specific game play") {
    Deck deck;
    CHECK(deck.isEmpty());



    deck.push(Card(HEART, ACE));
    deck.push(Card(SPADE, 2));
    deck.push(Card(HEART, 2));
    deck.push(Card(CLUB, 2));
    deck.push(Card(HEART, 10));
    deck.push(Card(DIAMOND, 9));
    deck.push(Card(HEART, QUEEN));
    deck.push(Card(SPADE, 10));
    deck.push(Card(SPADE, KING));
    deck.push(Card(CLUB, QUEEN));
    deck.push(Card(CLUB, 7));
    deck.push(Card(DIAMOND, 7));
    deck.push(Card(SPADE, 6));
    deck.push(Card(HEART, 6));
    deck.push(Card(CLUB, 5));
    deck.push(Card(DIAMOND, 5));
    deck.push(Card(HEART, 3));
    deck.push(Card(SPADE, 5));
    deck.push(Card(HEART, JACK));
    deck.push(Card(DIAMOND, 10));
    deck.push(Card(SPADE, 8));
    deck.push(Card(SPADE, JACK));
    deck.push(Card(HEART, 5));
    deck.push(Card(DIAMOND, 6));
    deck.push(Card(DIAMOND, 2));
    deck.push(Card(SPADE, ACE));
    deck.push(Card(DIAMOND, ACE));
    deck.push(Card(DIAMOND, KING));
    deck.push(Card(CLUB, KING));
    deck.push(Card(CLUB, ACE));
    deck.push(Card(HEART, KING));
    deck.push(Card(DIAMOND, 3));
    deck.push(Card(SPADE, 3));
    deck.push(Card(CLUB, 4));
    deck.push(Card(HEART, 4));
    deck.push(Card(HEART, 7));
    deck.push(Card(DIAMOND, 8));
    deck.push(Card(HEART, 8));
    deck.push(Card(HEART, 9));
    deck.push(Card(SPADE, 9));
    deck.push(Card(SPADE, 4));
    deck.push(Card(DIAMOND, 4));
    deck.push(Card(DIAMOND, QUEEN));
    deck.push(Card(SPADE, QUEEN));
    deck.push(Card(SPADE, 7));
    deck.push(Card(DIAMOND, JACK));
    deck.push(Card(CLUB, JACK));
    deck.push(Card(CLUB, 9));
    deck.push(Card(CLUB, 3));
    deck.push(Card(CLUB, 6));
    deck.push(Card(CLUB, 10));
    deck.push(Card(CLUB, 8));






    CHECK(deck.size() == 52);
    Player p1("P1");
    Player p2("P2");
    Game game(p1, p2, deck);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    game.playAll();
    game.printLog();
    game.printStats();

}