#include <iostream>
#include <sstream>
#include "HumanPlayer.h"
#include "Grid.h"
#include "StringUtil.h"

using namespace std;

namespace {
    void outputInvalidInput() {
        cout << "Invalid input: 2 digits (1-" << Grid::SIZE << ") separated with a space must be given" << endl;
    }

    bool _checkAndSetValue(short value, short& result) {
        result = (short) (value - 1);
        return result >= 0 && result < Grid::SIZE;
    }
}

Turn HumanPlayer::makeTurn() {
    Turn turn;
    turn.playerId = id();
    while(!getInput(turn)) {}
    return turn;
}

bool HumanPlayer::getInput(Turn& turn) {
    string s;
    cout << "Player " << id() << ": ";
    getline(cin, s);

    string buf;
    stringstream ss(s);

    int numStr = 0;
    while (ss >> buf) {
        short inputValue;
        if (numStr == 2 || !StringUtil::isNumber(buf) || !_checkAndSetValue((short) stoi(buf), inputValue)) {
            outputInvalidInput();
            return false;
        }
        (&turn.row)[numStr] = inputValue;
        ++numStr;
    }
    if (numStr != 2) {
        outputInvalidInput();
        return false;
    }
    return true;
}
