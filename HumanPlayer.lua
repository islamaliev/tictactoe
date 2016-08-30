require "Player"

HumanPlayer = Player:new()

function HumanPlayer:new(id)
    local o = Player:new(id)
    setmetatable(o, self)
    self.__index = self
    return o;
end

function HumanPlayer:makeTurn()
    local turn = Turn:new()
    turn.playerId = self:id();
    while(not self:getInput(turn)) do end
    print()
    return turn
end

function HumanPlayer:getInput(turn)
    io.write(string.format("Player %d: ", self:id()))
    io.flush()
    local input = io.read()

    local numStr = 0
    for i in string.gmatch(input, "%S+") do
        local inputValue = tonumber(i)
        if (numStr == 2 or inputValue == nil or not self:isInRange(inputValue)) then
            self:outputInvalidInput()
            return false
        end
        if (numStr == 0) then
            turn.row = inputValue - 1
        else
            turn.column = inputValue - 1
        end
        numStr = numStr + 1
    end

    if (numStr ~= 2) then
        self:outputInvalidInput()
        return false
    end

    return true
end

function HumanPlayer:isInRange(value)
    return value > 0 and value <= GRID_SIZE
end

function HumanPlayer:outputInvalidInput()
    print(string.format("Invalid input: 2 digits (1-%d) separated with a space must be given\n", GRID_SIZE))
end