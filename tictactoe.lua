require "TicTacToeGame"
require "ConsoleGridRenderer"

function startInitialDialog()
    io.write("tic-tac-toe\n")
    io.write(string.format("How many human players want to play (0-%d)?: ", NUM_PLAYERS));
    io.flush()

    local numHumans = tonumber(io.read())
    while (numHumans == nil) do
        io.write("Invalid input: must be a number. Try again: ");
        io.flush()
        numHumans = tonumber(io.read())
    end

    if (numHumans < 0) then
        numHumans = 0
    elseif (numHumans > NUM_PLAYERS) then
        numHumans = NUM_PLAYERS
    end

    io.write("Start game for ")
    local numBots = NUM_PLAYERS - numHumans
    if (numHumans > 0) then
        io.write(string.format("%d human"..(numHumans == 1 and "" or "s")..(numBots > 0 and " and " or ""), numHumans))
    end

    if (numBots > 0) then
        io.write(string.format("%d bot"..(numBots == 1 and "" or "s"), numBots))
    end

    io.write("\n\n")
    io.flush()

    return numHumans;
end

function showResults(game)
    io.write("Game over! ")
    if (game:winner()) then
        io.write("The winner is Player "..game:winner())
    else
        io.write("It's a tie")
    end
    io.write("\n\n")
    io.flush()
end

function playGame(numHumans)
    local game = TicTacToeGame:new(numHumans)
    local renderer = ConsoleGridRenderer:new(game:grid())
    renderer:initialRenderer()
    while (game:isOver() == false) do
        renderer:renderTurn(game:nextTurn())
    end
    showResults(game)
end

function main()
    local numHumans = startInitialDialog()
    playGame(numHumans)
end

main()
