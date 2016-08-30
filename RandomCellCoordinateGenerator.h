#pragma once

#include <random>
#include "Grid.h"

class RandomCellCoordinateGenerator {
public:
    RandomCellCoordinateGenerator(const Grid& grid)
        : m_grid(grid) {
        init();
    };

    std::pair<short, short> generate();

private:
    void init();

    const Grid& m_grid;
    std::mt19937 m_generator;
    std::uniform_int_distribution<> m_distribution;
};
