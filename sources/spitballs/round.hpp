#ifndef ROUND_HPP
#define ROUND_HPP

#include "../player.hpp"

namespace ariel {

    class Round {
        Player *p1, *p2;
        Card c_p1, c_p2;
    public:
        Round(Player *_p1, Player *_p2);

        string toString();

    private:

    };
}
#endif
