#include <iostream>
#include "ConsoleGridRenderer.h"
#include "Grid.h"

using namespace std;

void ConsoleGridRenderer::initialRender() {
    renderGrid();
}

void ConsoleGridRenderer::renderTurn(Turn turn) {
    renderGrid();
    cout << "Turn " << turn.index + 1 << ": " << turn.row + 1 << " " << turn.column + 1 << "  (Player " << turn.playerId << ")" << endl << endl;
}

void ConsoleGridRenderer::renderGrid() {
    cout << endl << "  ";
    auto arr = m_grid.data();
    for (int i = 1; i <= arr[0].size(); ++i) {
        cout << " " << i;
    }
    cout << endl << "  ";
    for (int i = 1; i <= arr[0].size(); ++i) {
        cout << "——";
    }
    cout << endl;
    for (int i = 0; i < arr.size(); ++i) {
        cout << i + 1 << "|";
        for (int j = 0; j < arr[0].size(); ++j) {
            unsigned char c = arr[i][j];
            cout << " " << (unsigned char) (c == 0 ? '.' : c);
        }
        cout << endl;
    }
    cout << endl;
}
