#pragma once

#include <vector>

class Player;
class TicTacToeGame;

class PlayersInitializer {
public:
    static void initialize(TicTacToeGame* game, int numHumans);
};
