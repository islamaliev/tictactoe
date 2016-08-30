#include <random>
#include "RandomCellCoordinateGenerator.h"

std::pair<short, short> RandomCellCoordinateGenerator::generate() {
    short row, column;
    do {
        int randValue = m_distribution(m_generator);
        row = (short) (randValue / Grid::SIZE);
        column = (short) (randValue - row * Grid::SIZE);
    } while (!m_grid.isValidCell(row, column));
    return {row, column};
}

void RandomCellCoordinateGenerator::init() {
    std::random_device rd;
    m_generator = std::mt19937(rd());
    m_distribution = std::uniform_int_distribution<>(0, Grid::SIZE * Grid::SIZE - 1);
}
