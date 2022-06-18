//
// Created by Cyrullian Saharmac on 3/28/21.
//

#include <algorithm>
#include <iostream>
#include "tictactoe3.h"
using namespace std;

bool tictactoe3::is_win(int tile, int action) {
    return false;
}

void tictactoe3::move(int tile, int action) {
    return;
}

void tictactoe3::unmove(int tile, int action) {
    return;
}

vector<Piece> unhash(int n) {
    Piece p1 = static_cast<Piece>(n%100);
    Piece p2 = static_cast<Piece>(n%10 - 10*p1);
    Piece p3 = static_cast<Piece>(n - 100*p1 - 10*p2);
    return {p1, p2, p3};
}

void tictactoe3::display() {
    string ESC = "\033[";
    string RED = "31";
    string GREEN = "32";
    string BLUE = "34";

    std::cout << "" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vector<Piece> pieces = unhash(state[i][j]);
            std::cout << ESC + RED << pieces[0] << ESC;
            std::cout << ESC + GREEN << pieces[1] << ESC;
            std::cout << ESC + BLUE << pieces[2] << ESC << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
