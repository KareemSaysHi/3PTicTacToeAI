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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            state[i][j] = board[i][j];
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
    // columns and rows
    if (state[i][j] == state[(i+1)%3][j] == state[(i-1)%3][j] ||
    state[i][j] == state[i][(j+1)%3] == state[i][(j-1)%3])
        return true;
    
    // on a diagonal
    if (i == j) {
        if (state[i][j] == state[(i+1)%3][(j+1)%3] == state[(i-1)%3][(j-1)%3])
            return true;
    }
    if (i == 2-j) {
        if (state[i][j] == state[(i+1)%3][(j-1)%3] == state[(i-1)%3][(j+1)%3])
            return true;
    }
    return false;
}

void tictactoe3::move(int tile, int action) {
    // first player affects first digit, second affects second, etc.
    if (action == 0) 
        state[tile/3][tile%3] += (player+1) * 100;
    else if (action == 1)
        state[tile/3][tile%3] += (player+1) * 10;
    else 
        state[tile/3][tile%3] += (player+1);

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

int hash(Color c1, Color c2, Color c3) { 
    return c1*100 + c2*10 + c3; 
}

Color* tictactoe3::unhash(int n) {
    Color c1 = static_cast<Color>(n/100);
    Color c2 = static_cast<Color>(n/10 - 10*c1);
    Color c3 = static_cast<Color>(n - 100*c1 - 10*c2);
    static Color colors[3];
    colors[0] = c1; colors[1] = c2; colors[2] = c3;
    return colors;
}

void tictactoe3::display() {
    string ESC = "\033[";
    string RED = "31";
    string GREEN = "32";
    string BLUE = "34";
    string pieces[3] = {"S", "M", "L"};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Color *colors = unhash(state[i][j]);
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
