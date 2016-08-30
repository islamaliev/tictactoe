require "RandomCellCoordinateGenerator"
require "PlayersInitializer"
require "Grid"
require "Turn"

TicTacToeGame = {}

NUM_PLAYERS = 3

local NUM_BLOCKED_CELLS = 4

function TicTacToeGame:new(numHumans)
    local o = {}
    setmetatable(o, self)
    self.__index = self
    self._winner = -1
    self._currentPlayer = 1
    self._currentTurnIndex = 0
    self._players = {size = NUM_PLAYERS}
    self._grid = Grid:new()
    self._cellCoordinateGenerator = RandomCellCoordinateGenerator:new(self._grid)
    PlayersInitializer.initialize(self, numHumans)
    self:initGrid()
    return o
end

function TicTacToeGame:initGrid()
    for i = 1, NUM_BLOCKED_CELLS do
        local row, column = self._cellCoordinateGenerator:generate()
        self._grid:put(row, column, 0)
    end
end

function TicTacToeGame:winner()
    return self._winner
end

function TicTacToeGame:checkGameOver(turn)
    if (self._grid:makesLine(turn.row, turn.column)) then
        self._winner = turn.playerId
        return
    end
    if (turn.index >= GRID_SIZE * GRID_SIZE - NUM_BLOCKED_CELLS - 1) then
        self._winner = 0
    end
end

function TicTacToeGame:grid()
    return self._grid
end

function TicTacToeGame:isOver()
    return self._winner ~= -1
end

function TicTacToeGame:nextTurn()
    local turn
    while (true) do
        turn = self._players[self._currentPlayer]:makeTurn()
        if (self._grid:isValidCell(turn.row, turn.column)) then
            break
        else
            print("Given cell is occupied, please try another one\n")
        end
    end

    turn.index = self._currentTurnIndex
    self._currentTurnIndex = self._currentTurnIndex + 1
    self._grid:put(turn.row, turn.column, turn.playerId)
    self:checkGameOver(turn)
    self._currentPlayer = self._currentPlayer == NUM_PLAYERS and 1 or self._currentPlayer + 1
    return turn
end