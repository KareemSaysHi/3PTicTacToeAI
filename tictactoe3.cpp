//
// Created by Cyrullian Saharmac on 3/28/21.
//

#include <algorithm>
#include <iostream>
#include "tictactoe3.h"
using namespace std;

tictactoe3::tictactoe3(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            state[i][j] = board[i][j];
        }
    }
}

bool tictactoe3::is_win(int tile, int action) {
    return false;
}

void tictactoe3::move(int tile, int action) {
    return;
}

void tictactoe3::unmove(int tile, int action) {
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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Piece *pieces = unhash(state[i][j]);
            for (int k = 0; k < 3; k++) {
                if (pieces[k] == Piece::empty)
                    std::cout << " ";
                else if (pieces[k] == redS || pieces[k] == redM || pieces[k] == redL)
                    std::cout << ESC + RED + "m" << pieces[k] << ESC + "m";
                else if (pieces[k] == greenS || pieces[k] == greenM || pieces[k] == greenL)
                    std::cout << ESC + GREEN + "m" << pieces[k] << ESC + "m";
                else
                    std::cout << ESC + BLUE + "m" << pieces[k] << ESC + "m";
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
