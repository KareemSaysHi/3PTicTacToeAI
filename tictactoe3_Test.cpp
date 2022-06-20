//
// Created by Cyrullian Saharmac on 4/3/21.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tictactoe3.h"

bool test_equality(int answer[3][3], int state[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (answer[i][j] != state[i][j])
                return false;
        }
    }
    return true;
}

TEST_CASE("Testing the display function") {
    int state[3][3] = {{0,1,3}, {8,5,4}, {3,9,7}};
    auto board = new tictactoe3(state);
    board->display();
    int state1[3][3] = {{123, 259, 357}, {398, 545, 674}, {731, 880, 987}};
    auto board1 = new tictactoe3(state1);
    board1->display();
    CHECK(1 == 1);
}

TEST_CASE("Testing the move function") {
    auto board = new tictactoe3();

    board->move(6, 1);
    auto state = board->state;
    int answer[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    answer[2][0] = 1;
    CHECK(test_equality(answer, state));

    board->move(7, 1);
    state = board->state;
    answer[2][1] = 4;
    CHECK(test_equality(answer, state));

    board->move(8, 1);
    state = board->state;
    answer[2][2] = 7;
    CHECK(test_equality(answer, state));

    board->move(6, 3);
    state = board->state;
    answer[2][0] = 31;
    CHECK(test_equality(answer, state));
}

TEST_CASE("Testing the win function") {

    SUBCASE("Test Horizontal") {
        auto board = new tictactoe3();

        board->move(0, 1);
        board->move(1, 1);
        board->move(2, 1);
        board->move(0, 2);
        board->move(1, 2);
        board->move(2, 2);
        board->move(0, 3);

        board->display();
        bool win = board->outcome == 0;

        CHECK(false);
    }

    SUBCASE("Test Vertical") {
        auto board = new tictactoe3();

        board->move(0, 1);
        board->move(3, 1);
        board->move(6, 1);
        // board->move(0, 2);
        // board->move(3, 2);
        // board->move(6, 2);
        // board->move(0, 3);

        board->display();
        bool win = board->outcome == 0;

        CHECK(win);
    }

    SUBCASE("Test Diagonal") {
        auto board = new tictactoe3();

        board->move(0, 1);
        board->move(4, 1);
        board->move(8, 1);
        board->move(0, 2);
        board->move(4, 2);
        board->move(8, 2);
        board->move(0, 3);

        board->display();
        bool win = board->outcome == 0;

        CHECK(win);
    }
}
