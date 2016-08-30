#pragma once

#include "PlayersInitializer.h"
#include "Turn.h"
#include "Grid.h"
#include "RandomCellCoordinateGenerator.h"

class TicTacToeGame {
public:
    static constexpr int NUM_PLAYERS = 3;
    static constexpr int NUM_BLOCKED_CELLS = 4;

    TicTacToeGame(int numHumans)
        : m_randomCellMaker(m_grid) {
        PlayersInitializer::initialize(this, numHumans);
        initGrid();
    }

    ~TicTacToeGame();

    bool isOver() const {
        return m_winner != -1;
    }

    short winner() const {
        return m_winner;
    }

    const Grid& grid() const {
        return m_grid;
    }

    Turn nextTurn();

private:
    void initGrid();

    void checkGameOver(Turn turn);

    Grid m_grid;
    RandomCellCoordinateGenerator m_randomCellMaker;
    std::vector<Player*> m_players{NUM_PLAYERS};
    short m_currentPlayer{0};
    short m_currentTurnIndex{0};
    short m_winner{-1};

    friend class PlayersInitializer;
};
