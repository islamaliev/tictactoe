#pragma once

#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(short id)
        : Player(id) {
    }

    Turn makeTurn() override;

private:
    bool getInput(Turn& turn);
};
