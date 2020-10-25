#include <cstdint>

#include "chess_field"

class Player {

};

class Game {
    Player p1_;
    Player p2_;
    ChessField field_;

public:
    Game();

    auto start();

    auto stop();
};
