require "HumanPlayer"
require "BotPlayer"

PlayersInitializer = {}

function PlayersInitializer.initialize(game, numHumans)
    local i = 1
    local players = game._players
    while i <= numHumans do
        players[i] = HumanPlayer:new(i)
        i = i + 1
    end

    while i <= players.size do
        players[i] = BotPlayer:new(i, game._cellCoordinateGenerator)
        i = i + 1
    end
end
