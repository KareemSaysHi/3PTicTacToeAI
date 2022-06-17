//
// Created by Cyrullian Saharmac on 3/28/21.
//

#include <algorithm>
#include <iostream>
#include "tictactoe3.h"
using namespace std;

tictactoe3::tictactoe3(int r, int c, int num):
    state(std::vector<std::vector<int>>(r, std::vector<int>(c, 0))),
    rows(r),
    columns(c),
    inarow(num),
    player(1){}

int tictactoe3::count(int column, int row, int offset_row, int offset_column) {
    // Counts number of pieces in a certain direction, excluding the starting piece

    int mark = state[row][column];
    for (int i = 0; i < this->inarow; i++) {
        int r = row + offset_row * i;
        int c = column + offset_column * i;
        // if current mark doesn't fit into the sequence, stop counting
        if (r < 0 || c < 0 || c >= columns || r >= rows || state[r][c] != mark) {
            return i - 1;
        }
    }
    return this->inarow;
}

bool tictactoe3::is_win(int action) {
    // determine row winning piece was placed in
    int row = 0;
    for (int i = 0; i < rows; i++) {
        if (state[i][action] == 0) {
            row += 1;
        }
    }

    // check for connect 4s in all directions
    return (
            ((count(action, row, 1, 0)) >= inarow - 1) ||
            ((count(action, row, 0, 1) + count(action, row, 0, -1)) >= (inarow - 1)) ||
            ((count(action, row, -1, -1) + count(action, row, 1, 1)) >= (inarow - 1)) ||
            ((count(action, row, -1, 1) + count(action, row, 1, -1)) >= (inarow - 1))
    );
}

bool tictactoe3::is_draw() {
    int zeros = std::count(this->state[0].begin(), this->state[0].end(), 0);
    if (zeros == 0) {
        return true;
    }
    else {
        return false;
    }
}

std::vector<int> tictactoe3::is_terminal(int action) {
    if (is_win(action)) {
        return {1, 1};
    }
    else if (is_draw()) {
        return {1, 0};
    }
    else {
        return {0, 0};
    }
}

void tictactoe3::move(int action) {
    int row_num = rows - 1;
    for (int row = rows - 1; row >= 0; row--) {
        if (state[row][action] == 0) {
            break;
        }

        row_num--;
    }

    // Make board flipped for ease of use
    state[row_num][action] = player;
    player *= -1;
}

void tictactoe3::unmove(int action) {
    int row_num = rows;
    for (int row = rows - 1; row < rows; row--) {
        if (state[row][action] == 0) {
            break;
        }

        row_num--;
    }
    state[row_num][action] = 0;
    player *= -1;
}

void tictactoe3::flip() {
    std::vector<int> state_copy;
    for (auto v: this->state) {
        transform(v.begin(), v.end(), v.begin(), [](int &c){ return -c; });
    }
}

std::vector<int> tictactoe3::legal() {
    std::vector<int> legal_actions = std::vector<int>(this->columns, 0);
    int i = 0;
    for (auto mark: this->state[0]) {
        if (mark == 0) {
            legal_actions[i] = 1;
        }
        i += 1;
    }
    return legal_actions;
}

void tictactoe3::display() const {
    std::cout << "" << std::endl;
    for (auto vec: state) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == 1) {
                std::cout << "+" << vec[i] << " " << std::flush;
            }
            else if (vec[i] == 0){
                std::cout << " " << vec[i] << " " << std::flush;
            }
            else{
                std::cout << vec[i] << " " << std::flush;
            }
        }
        std::cout << "" << std::endl;
    }
    std::cout << "" << std::endl;
}
