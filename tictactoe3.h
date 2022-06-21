#ifndef tictactoe3_h
#define tictactoe3_h

#include <cstring>
#include <vector>
#include <array>
#include "colors.h"
#include "pieces.h"

using std::vector;

class tictactoe3 {
public:
    int player;
    int moves;
    // p1-p3 win, tie, ongoing
    int outcome;

    // you can make this a lot better with bitmasking but until efficiency is a priority i'm gonna go with ease of implementation.

    // change this to have a third index for small/medium/large, hashing unhashing is unnecessary
    Color state[3][3][3];
    int pieceCounter[3][3];

    tictactoe3();

    tictactoe3(int board[3][3]);

    bool is_win(int tile, int action);

    void move(int tile, int action);

    void unmove(int tile, int action);

    bool legal(int tile, int action, int player);

    vector<array<int, 3>> returnLegalMoves(Color state);

    int* minimax(Color state, std::string mode = "maximizing");

    void display();
};

#endif