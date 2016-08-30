require "Player"

BotPlayer = Player:new()

function BotPlayer:new(id, cellCoordinateGenerator)
    local o = Player:new(id)
    setmetatable(o, self)
    self.__index = self
    self._cellCoordinateGenerator = cellCoordinateGenerator
    return o;
end

function BotPlayer:makeTurn()
    local row, column = self._cellCoordinateGenerator:generate()
    return Turn:new(row, column, self:id())
end