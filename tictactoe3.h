#ifndef tictactoe3_h
#define tictactoe3_h

#include <vector>

class tictactoe3 {
public:
    const int rows;
    const int columns;
    const int inarow;

    tictactoe3(int rows, int columns, int inarow);

    int count(int column, int row, int offset_row, int offset_column);

    bool is_win(int action);

    bool is_draw();

    std::vector<int> is_terminal(int action);

    void move(int action);

    void unmove(int action);

    void flip();

    std::vector<int> legal();

    std::vector<std::vector<int>> inline get_state() const{
        return state;
    }

    void set_state(std::vector<std::vector<int>> board) {
        state = board;
    }

    void display() const;

    int inline get_player() const{
        return player;
    }

private:
    std::vector<std::vector<int>> state;
    int player = 1;
};

#endif