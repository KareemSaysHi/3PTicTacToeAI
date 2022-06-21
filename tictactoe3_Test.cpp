//
// Created by Cyrullian Saharmac on 4/3/21.
// lmaooo i like the username
//

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

TEST_CASE("Testing the display function") {
    int state[3][3] = {{0,1,2}, {2,1,1}, {3,2,3}};
    auto board = new tictactoe3(state);
    board->display();
    int state1[3][3] = {{123, 213, 312}, {222, 112, 321}, {123, 320, 123}};
    auto board1 = new tictactoe3(state1);
    board1->display();
    CHECK(1 == 1);
}

TEST_CASE("Testing the move function") {
    auto board = new tictactoe3();

    board->move(6, small);
    auto state = board->state;
    int answer[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    answer[2][0] = 100;
    CHECK(test_equality(answer, state));

    board->move(7, small);
    state = board->state;
    answer[2][1] = 200;
    CHECK(test_equality(answer, state));

    board->move(8, small);
    state = board->state;
    answer[2][2] = 300;
    CHECK(test_equality(answer, state));

    board->move(6, large);
    state = board->state;
    answer[2][0] = 101;
    CHECK(test_equality(answer, state));
}

TEST_CASE("Testing the win function") {

    SUBCASE("Test Horizontal") {
        auto board = new tictactoe3();

        board->move(0, small);
        board->move(4, small);
        board->move(5, small);
        board->move(1, small);
        board->move(4, medium);
        board->move(5, medium);
        board->move(2, small);

        board->display();
        bool win = board->outcome == 0;

        CHECK(win);
    }

    SUBCASE("Test Vertical") {
        auto board = new tictactoe3();

        board->move(0, medium);
        board->move(4, small);
        board->move(5, small);
        board->move(3, medium);
        board->move(4, medium);
        board->move(5, medium);
        board->move(6, medium);

        board->display();
        bool win = board->outcome == 0;

        CHECK(win);
    }

    SUBCASE("Test Diagonal") {
        auto board = new tictactoe3();

        board->move(0, small);
        board->move(3, small);
        board->move(2, small);
        board->move(4, small);
        board->move(4, medium);
        board->move(8, large);
        board->move(8, small);

        board->display();
        bool win = board->outcome == 0;

        CHECK(win);
    }

    SUBCASE("Test Main Diagonal ascending") {
        auto board = new tictactoe3();

        board->move(0, small);
        board->move(0, medium);
        board->move(5, small);
        board->move(4, medium);
        board->move(3, medium);
        board->move(2, medium);
        board->move(8, large);

        board->display();
        bool win = board->outcome == 0;

        CHECK(win);
    }

    SUBCASE("Test Off Diagonal ascending") {
        auto board = new tictactoe3();

        board->move(0, small);
        board->move(6, small);
        board->move(0, medium);
        board->move(5, small);
        board->move(4, medium);
        board->move(3, medium);
        board->move(2, medium);
        board->move(2, large);

        board->display();
        bool win = board->outcome == 1;

        CHECK(win);
    }

    SUBCASE("Test Stack") {
        auto board = new tictactoe3();

        board->move(0, small);
        board->move(1, small);
        board->move(2, medium);
        board->move(0, medium);
        board->move(1, medium);
        board->move(2, medium);
        board->move(0, large);

        board->display();
        bool win = board->outcome == 0;

        CHECK(win);
    }

    SUBCASE("Test False") {
        auto board = new tictactoe3();

        board->move(0, small);
        board->move(1, small);
        board->move(2, medium);
        board->move(0, medium);
        board->move(1, medium);
        board->move(2, medium);

        board->display();
        bool win = board->outcome == 0;

        CHECK(!win);
    }
}
