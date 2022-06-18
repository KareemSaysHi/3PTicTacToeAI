//
// Created by Cyrullian Saharmac on 3/28/21.
//

#include <algorithm>
#include <iostream>
#include "tictactoe3.h"
#include "<cmath>"
using namespace std;

tictactoe3::tictactoe3() {
    player = 0;
    outcome = 0;
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
    state[tile/3][tile%3] += pow(action, 2-player);
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

int hash(Piece p1, Piece p2, Piece p3) { 
    return p1*100 + p2*10 + p3; 
}

Piece* tictactoe3::unhash(int n) {
    Piece p1 = static_cast<Piece>(n/100);
    Piece p2 = static_cast<Piece>(n/10 - 10*p1);
    Piece p3 = static_cast<Piece>(n - 100*p1 - 10*p2);
    static Piece pieces[3];
    pieces[0] = p1; pieces[1] = p2; pieces[2] = p3;
    return pieces;
}

void tictactoe3::display() {
    string ESC = "\033[";
    string RED = "31";
    string GREEN = "32";
    string BLUE = "34";
    string colors[] = {RED, GREEN, BLUE};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Piece *pieces = unhash(state[i][j]);
            for (int k = 0; k < 3; k++) {
                if (pieces[k] == Piece::empty)
                    std::cout << " ";
                else if (pieces[k] == small)
                    std::cout << ESC + colors[k] + "m" << "S" << ESC + "m";
                else if (pieces[k] == medium)
                    std::cout << ESC + colors[k] + "m" << "M" << ESC + "m";
                else
                    std::cout << ESC + colors[k] + "m" << "L" << ESC + "m";
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
