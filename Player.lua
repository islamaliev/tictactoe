Player = {}
Player.__index = Player

function Player:new(id)
    local self = setmetatable({}, Player)
    self._id = id
    return self
end

function Player:makeTurn()
    print("Error: Player:makeTurn() is virtual method")
end

function Player:id()
    return self._id
end