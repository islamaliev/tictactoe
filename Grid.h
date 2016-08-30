#pragma once

#include <array>


class Grid {
public:
    static constexpr int SIZE = 6;
    static constexpr int LINE = 3; // makes 4 with current one

    Grid()
        : m_data() {
    }

    bool isValidCell(short row, short column) const {
        return row >= 0 && row < SIZE && column >= 0 && column < SIZE && m_data[row][column] == 0;
    }

    const std::array<std::array<unsigned char, SIZE>, SIZE>& data() const {
        return m_data;
    };

    void put(short row, short column, unsigned char val) {
        m_data[row][column] = val + '0';
    }

    bool makesLine(short row, short column) const {
        unsigned char value = m_data[row][column];
        if (makesHorizontalLine(row, column, value))
            return true;
        if (makesVerticalLine(row, column, value))
            return true;
        if (makesForwardDiagonalLine(row, column, value))
            return true;
        return makesBackwardDiagonalLine(row, column, value);
    }

private:
    bool makesHorizontalLine(short row, short column, unsigned char value) const {
        return countValues(row, column <= LINE ? 0 : column - LINE, 0, 1, value);
    }

    bool makesVerticalLine(short row, short column, unsigned char value) const {
        return countValues(row <= LINE ? 0 : row - LINE, column, 1, 0, value);
    }

    bool makesForwardDiagonalLine(short row, short column, unsigned char value) const {
        auto sum = row + column;
        if (sum < LINE || sum >= LINE + SIZE - 1)
            return false;
        auto flipCol = SIZE - 1 - column;
        auto min = row > flipCol ? flipCol : row;
        auto shift = min > LINE ? LINE : min;
        return countValues(row - shift, column + shift, 1 , -1, value);
    }

    bool makesBackwardDiagonalLine(short row, short column, unsigned char value) const {
        auto sum = SIZE - 1 - column + row;
        if (sum < LINE || sum >= LINE + SIZE - 1)
            return false;
        auto min = row > column ? column : row;
        auto shift = min > LINE ? LINE : min;
        return countValues(row - shift, column - shift, 1 , 1, value);
    }

    bool countValues(short r, short c, short rm, short cm, unsigned char value) const {
        int counter = 0;
        for (int i = 0; i < LINE + LINE + 1; ++i, r += rm, c += cm) {
            if (r < 0 || r >= Grid::SIZE || c < 0 || c >= Grid::SIZE)
                continue;
            counter = m_data[r][c] == value ? counter + 1 : 0;
            if (counter > LINE)
                return true;
        }
        return false;
    }

    std::array<std::array<unsigned char, SIZE>, SIZE> m_data;
};
