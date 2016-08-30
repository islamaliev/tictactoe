RandomCellCoordinateGenerator = {}

function RandomCellCoordinateGenerator:new(grid)
    local o = {}
    setmetatable(o, self)
    self._grid = grid
    self.__index = self
    math.randomseed(os.time())
    return o
end

function RandomCellCoordinateGenerator:generate()
    local row, column
    repeat
        local randValue = math.random(0, GRID_SIZE * GRID_SIZE - 1)
        row = math.floor(randValue / GRID_SIZE)
        column = randValue - row * GRID_SIZE
    until (self._grid:isValidCell(row, column))
    return row, column
end