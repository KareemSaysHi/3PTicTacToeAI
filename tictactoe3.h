#ifndef tictactoe3_h
#define tictactoe3_h

#include <vector>
#include "pieces.h"
class tictactoe3 {
public:
    int player = 0;

    // ongoing, p1-p3 win, tie, 
    int outcome;

    int state[3][3];

    tictactoe3();

    tictactoe3(int board[3][3]) { memcpy(board, state, sizeof(board)); }

    bool is_win(int tile, int action);

    vector<int> is_terminal(int action);

    void move(int tile, int action);

    void unmove(int tile, int action);

    bool legal(int tile, int action);

    int hash(Piece p1, Piece p2, Piece p3) { return p1*100 + p2*10 + p3*1; }

    vector<Piece> unhash(int n);

    void display();
};

#endif