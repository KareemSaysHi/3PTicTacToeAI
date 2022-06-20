//
// Created by Cyrullian Saharmac on 3/28/21.
//

#include <algorithm>
#include <iostream>
#include "cmath"
#include "tictactoe3.h"
using namespace std;

tictactoe3::tictactoe3() {
    player = 0;
    // ongoing
    outcome = 4;
    moves = 0;
}

tictactoe3::tictactoe3(int board[3][3]) {
    int n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            n = board[i][j];
            Color c1 = static_cast<Color>(n/100);
            Color c2 = static_cast<Color>(n/10 - 10*c1);
            Color c3 = static_cast<Color>(n - 100*c1 - 10*c2);
            state[i][j][0] = c1; state[i][j][1] = c2; state[i][j][2] = c3;
        }
    }
    player = 0;
    // ongoing
    outcome = 4;
    moves = 0;
}

bool tictactoe3::is_win(int tile, int action) {
    int i = tile/3;
    int j = tile%3;

    // check all equal along rows cols and diagonals
    // columns and rows
    if (state[i][j][action] == state[(i+1)%3][j][action] == state[(i-1)%3][j][action] ||
    state[i][j][action] == state[i][(j+1)%3][action] == state[i][(j-1)%3][action])
        return true;
    
    // on a diagonal
    if (i == j) {
        if (state[i][j][action] == state[(i+1)%3][(j+1)%3][action] == state[(i-1)%3][(j-1)%3][action])
            return true;
    }
    if (i == 2-j) {
        if (state[i][j][action] == state[(i+1)%3][(j-1)%3][action] == state[(i-1)%3][(j+1)%3][action])
            return true;
    }

    // check ascending / descending combos on diagonals.
    if ((i == j || i == 2-j) && i != 1 && action != 1) {
        int increment = (action == 2) ? -1 : 1;
        if (state[i][j][action] == state[(i+1)%3][(j+1)%3][action+increment] == state[(i-1)%3][(j-1)%3][action+2*increment])
            return true;
        
        if (state[i][j][action] == state[(i+1)%3][(j-1)%3][action+increment] == state[(i-1)%3][(j+1)%3][action+2*increment])
            return true;
    }

    // stack.
    if (state[i][j][0] == state[i][j][1] == state[i][j][2])
        return true;

    return false;
}

void tictactoe3::move(int tile, int action) {
    state[tile/3][tile%3][action] = static_cast<Color>(player+1);
    moves += 1;
    
    if (is_win(tile, action))
        outcome = player;
    else if (moves == 27)
        outcome = 3;
    player = (player + 1) % 3;
}

void tictactoe3::unmove(int tile, int action) {
    // this may not be needed.
    return;
}

void tictactoe3::display() {
    string ESC = "\033[";
    string RED = "31";
    string GREEN = "32";
    string BLUE = "34";
    string pieces[3] = {"S", "M", "L"};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Color *colors = state[i][j];
            for (int k = 0; k < 3; k++) {
                if (colors[k] == Color::empty)
                    std::cout << "-";
                else
                    if (colors[k] == red)
                        std::cout << ESC + RED + "m" << pieces[k] << ESC + "m";
                    else if (colors[k] == green)
                        std::cout << ESC + GREEN + "m" << pieces[k] << ESC + "m";
                    else if (colors[k] == blue)
                        std::cout << ESC + BLUE + "m" << pieces[k] << ESC + "m";
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
