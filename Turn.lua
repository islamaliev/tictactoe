Turn = {row = 0, column = 0, playerId = 0, index = 0}

function Turn:new(row, column, playerId)
    setmetatable({}, self)
    self.row = row
    self.column = column
    self.playerId = playerId
    return self
end