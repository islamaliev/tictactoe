ConsoleGridRenderer = {}

function ConsoleGridRenderer:new(grid)
    setmetatable({}, self)
    self.__index = self
    self._grid = grid
    return self
end

function ConsoleGridRenderer:initialRenderer()
    self:renderGrid()
end

function ConsoleGridRenderer:renderTurn(turn)
    self:renderGrid()
    print(string.format("Turn %d: %d %d  (Player %d)\n", turn.index + 1, turn.row + 1, turn.column + 1, turn.playerId))
end

function ConsoleGridRenderer:renderGrid()
    io.write("  ")
    local arr = self._grid._data
    for i = 1, GRID_SIZE do
        io.write(" "..i)
    end
    io.write("\n  ")
    for i = 1, GRID_SIZE do
        io.write("--")
    end
    io.write("\n")
    for i = 1, GRID_SIZE do
        io.write(i.."|")
        for j = 1, GRID_SIZE do
            local c = arr[i - 1][j - 1]
            io.write(" "..(c == EMPTY_CELL and "." or c))
        end
        io.write("\n")
    end
    io.write("\n")
    io.flush()
end