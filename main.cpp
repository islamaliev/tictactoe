#include <iostream>
#include "Player.h"
#include "TicTacToeGame.h"
#include "ConsoleGridRenderer.h"
#include "StringUtil.h"

using namespace std;

int startInitialDialog() {
    cout << "tic-tac-toe" << endl << endl;
    cout << "How many human players want to play (0-" << TicTacToeGame::NUM_PLAYERS << ")?: ";
    string s;
    cin >> s;
    while (!StringUtil::isNumber(s)) {
        cout << "Invalid input: must be a number. Try again: " << endl;
        cin >> s;
    }
    int numHumans = stoi(s);
    char c;
    while (cin.get(c) && c != '\n')

    if (numHumans < 0)
        numHumans = 0;
    else if (numHumans > TicTacToeGame::NUM_PLAYERS)
        numHumans = TicTacToeGame::NUM_PLAYERS;
    cout << "Start game for ";
    int numBots = TicTacToeGame::NUM_PLAYERS - numHumans;
    if (numHumans > 0)
    {
        cout << numHumans << " human" << (numHumans == 1 ? "" : "s") << (numBots > 0 ? " and " : "");

    }
    if (numBots) {
        cout << numBots << " bot" << (numBots == 1 ? "" : "s");
    }
    cout << endl;
    return numHumans;
}

void showResults(const TicTacToeGame& game) {
    cout << "Game over! ";
    if (game.winner())
        cout << "The winner is Player " << game.winner();
    else
        cout << "It's a tie";
    cout << endl << endl;
}

void playGame(int numHumans) {
    TicTacToeGame game = TicTacToeGame(numHumans);
    ConsoleGridRenderer renderer(game.grid());
    renderer.initialRender();
    while (!game.isOver()) {
        renderer.renderTurn(game.nextTurn());
    }
    showResults(game);
}

int main() {
    int numHumans = startInitialDialog();
    playGame(numHumans);
    return 0;
}