Grid = {}

GRID_SIZE = 6
EMPTY_CELL = -1
local LINE = 3

function Grid:new()
    local o = {}
    setmetatable(o, self)
    self.__index = self
    self._data = {}
    for i = 0, GRID_SIZE - 1 do
        self._data[i] = {}
        for j = 0, GRID_SIZE - 1 do
            self._data[i][j] = EMPTY_CELL
        end
    end
    return o
end

function Grid:isValidCell(row, column)
    return row >= 0 and row < GRID_SIZE and column >= 0 and column < GRID_SIZE and self._data[row][column] == EMPTY_CELL
end

function Grid:data()
    return self._data;
end

function Grid:put(row, column, val)
    self._data[row][column] = val + '0';
end

function Grid:makesLine(row, column)
    local value = self._data[row][column];
    if (self:makesHorizontalLine(row, column, value)) then
        return true
    end
    if (self:makesVerticalLine(row, column, value)) then
        return true
    end
    if (self:makesForwardDiagonalLine(row, column, value)) then
        return true
    end
    return self:makesBackwardDiagonalLine(row, column, value)
end

function Grid:makesHorizontalLine(row, column, value)
    return self:countValues(row, column <= LINE and 0 or column - LINE, 0, 1, value)
end

function Grid:makesVerticalLine(row, column, value)
    return self:countValues(row <= LINE and 0 or row - LINE, column, 1, 0, value)
end

function Grid:makesForwardDiagonalLine(row, column, value)
    local sum = row + column
    if (sum < LINE or sum >= LINE + GRID_SIZE - 1) then
        return false
    end
    local flipCol = GRID_SIZE - 1 - column
    local min = row > flipCol and flipCol or row
    local shift = min > LINE and LINE or min
    return self:countValues(row - shift, column + shift, 1, -1, value)
end

function Grid:makesBackwardDiagonalLine(row, column, value)
    local sum = GRID_SIZE - 1 - column + row
    if (sum < LINE or sum >= LINE + GRID_SIZE - 1) then
        return false
    end
    local min = row > column and column or row
    local shift = min > LINE and LINE or min
    return self:countValues(row - shift, column - shift, 1 , 1, value)
end

function Grid:countValues(r, c, rm, cm, value)
    local counter = 0
    for i = 1, LINE + LINE + 1 do
        if (r >= 0 and r < GRID_SIZE and c >= 0 and c < GRID_SIZE) then
            counter = self._data[r][c] == value and counter + 1 or 0
            if (counter > LINE) then
                return true
            end
        end
        r = r + rm
        c = c + cm
    end
end