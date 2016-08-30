#include <iostream>
#include "TicTacToeGame.h"
#include "Player.h"

Turn TicTacToeGame::nextTurn() {
    Turn turn;
    while (true) {
        turn = m_players[m_currentPlayer]->makeTurn();
        if (m_grid.isValidCell(turn.row, turn.column))
            break;
        else
            std::cout << "Given cell is occupied, please try another one" << std::endl << std::endl;
    }
    turn.index = m_currentTurnIndex++;
    m_grid.put(turn.row, turn.column, (unsigned char) turn.playerId);
    checkGameOver(turn);
    m_currentPlayer = (short) (m_currentPlayer == NUM_PLAYERS - 1 ? 0 : m_currentPlayer + 1);
    return turn;
}

TicTacToeGame::~TicTacToeGame() {
    for (int i = NUM_PLAYERS - 1; i >= 0; --i) {
        delete m_players[i];
    }
}

void TicTacToeGame::initGrid() {
    for (int i = 0; i < NUM_BLOCKED_CELLS; ++i) {
        auto cell = m_randomCellMaker.generate();
        m_grid.put(cell.first, cell.second, 0);
    }
}

void TicTacToeGame::checkGameOver(Turn turn) {
    if (m_grid.makesLine(turn.row, turn.column)) {
        m_winner = turn.playerId;
        return;
    }
    if (turn.index >= Grid::SIZE * Grid::SIZE - NUM_BLOCKED_CELLS - 1)
        m_winner = 0;
}
