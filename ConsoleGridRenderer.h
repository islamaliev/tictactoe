#pragma once

#include "Turn.h"

class Grid;

class ConsoleGridRenderer {
public:
    ConsoleGridRenderer(const Grid& grid)
        : m_grid(grid) {};

    void initialRender();

    void renderTurn(Turn turn);

private:
    void renderGrid();

    const Grid& m_grid;
};
