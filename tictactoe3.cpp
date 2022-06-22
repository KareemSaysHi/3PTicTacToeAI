//
// Created by Cyrullian Saharmac on 3/28/21.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
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
    //tile is:
    // 0 1 2
    // 3 4 5
    // 6 7 8
    //action is size of piece (small medium big -> 1 2 3)

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
    pieceCounter[player][action] += 1; //logging the piece that they played
    moves += 1;
    
    if (is_win(tile, action))
        outcome = player;
    else if (moves == 27)
        outcome = 3;
    player = (player + 1) % 3;
}

void tictactoe3::unmove(int tile, int action) {
    if (state[tile/3][tile%3][action] == Color::empty) {
        state[tile/3][tile%3][action] = static_cast<Color>(0);
        pieceCounter[player][action] -= 1;
        moves -= 1;
        player = (player - 1) % 3;
    }
}

bool tictactoe3::legal(int tile, int action, int player) {
    if (state[tile/3][tile%3][action] == Color::empty) {
        if (pieceCounter[player][action] > 3) {
            return false;
        }
        return true;
    }
    return false;
}

vector<array<int, 2>> tictactoe3::returnLegalMoves(Color state, int player) {
    //1D array of length 9, which are all the tiles of the board
    //inside all of THOSE indexes are a 1D array of length 3, which store which pieces can be played

    vector<array<int, 2>> legalMoves; //player, tile, size
    for (int tile = 0; tile < 9; tile++) {
        for (int pieceSize = 0; pieceSize < 3; pieceSize++) {
            if (tictactoe3::legal(tile, pieceSize, player)) {
                //log in legal moves array
                array<int, 2> holder = {tile, pieceSize};
                legalMoves.push_back(holder);
            }
        }
    }

    return legalMoves;
}

int* tictactoe3::minimax(Color state, int player) {

    vector<array<int, 2>> childStates = tictactoe3::returnLegalMoves(state, player);
    int numChildStates = childStates.size();

    static int maxEvaluation[3] = {-10, -10, -10};

    for(int i=0; i < numChildStates; i++){
        tictactoe3::move(childStates[i][0], childStates[i][1]);
        int* eval = minimax(state, player); //player was updated by move func
        if (eval[player] > maxEvaluation[player]) {
            for (int j = 0; j < 3; j++) {
                maxEvaluation[i] = eval[j];
            }
            if (eval[player] == 1) {
                return maxEvaluation; //immediate pruning
            }
        }
        tictactoe3::unmove(childStates[i][0], childStates[i][1]);

    }
    return maxEvaluation;
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
