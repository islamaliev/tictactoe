#pragma once

#include "Player.h"
#include "RandomCellCoordinateGenerator.h"

class BotPlayer : public Player {
public:
    BotPlayer(short id, RandomCellCoordinateGenerator& randomCellMaker)
        : Player(id)
        , m_randomCellMaker(randomCellMaker) {
    }

    Turn makeTurn() override {
        auto cell = m_randomCellMaker.generate();
        return {cell.first, cell.second, id()};
    }

private:
    RandomCellCoordinateGenerator& m_randomCellMaker;
};
