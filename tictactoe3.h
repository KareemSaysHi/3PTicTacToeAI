#ifndef tictactoe3_h
#define tictactoe3_h

#include <cstring>
#include "pieces.h"
class tictactoe3 {
public:
    int player;

    // ongoing, p1-p3 win, tie, 
    int outcome;

    // you can make this a lot better with bitmasking but until efficiency is a priority i'm gonna go with ease of implementation.
    int state[3][3];

    tictactoe3();

    tictactoe3(int board[3][3]) { memcpy(board, state, 9*sizeof(board[0][0])); }

    bool is_win(int tile, int action);

    void move(int tile, int action);

    void unmove(int tile, int action);

    bool legal(int tile, int action);

    int hash(Piece p1, Piece p2, Piece p3) { return p1*100 + p2*10 + p3*1; }

    Piece* unhash(int n);

    void display();
};

#endif