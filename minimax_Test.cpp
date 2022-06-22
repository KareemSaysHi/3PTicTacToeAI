// Created by Cyril Sharma on 4/3/21.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tictactoe3.h"

using namespace std;

bool test_equality(int answer[3][3], Color state[3][3][3]) {
    string num;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            num = "";
            for (int k = 0; k < 3; k++) {
                num += to_string(state[i][j][k]);
            }
            if (answer[i][j] != stoi(num))
                return false;
        }
    }
    return true;
}

TEST_CASE("Testing basic case") {
    int state[3][3] = {{0,1,2}, {2,1,1}, {3,10,3}};
    auto board = new tictactoe3(state);
    board->display();
    auto result = board->minimax(red, 0);
    std::cout << result[0] << " " << result[1] << "\n";
    CHECK(1 == 1);
}
