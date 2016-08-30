#include "PlayersInitializer.h"
#include "HumanPlayer.h"
#include "BotPlayer.h"
#include "TicTacToeGame.h"

void PlayersInitializer::initialize(TicTacToeGame* game, int numHumans) {
    int i = 0;
    for (; i < numHumans; ++i) {
        game->m_players[i] = new HumanPlayer(i + 1);
    }
    for (; i < game->m_players.size(); ++i) {
        game->m_players[i] = new BotPlayer(i + 1, game->m_randomCellMaker);
    }
}
