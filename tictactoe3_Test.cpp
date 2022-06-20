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
    int state[3][3] = {{0,1,2}, {2,1,0}, {1,2,2}};
    auto board = new tictactoe3(state);
    board->display();
    int state1[3][3] = {{0,121,211}, {212,112,103}, {321,312,333}};
    auto board1 = new tictactoe3(state1);
    board1->display();
    CHECK(1 == 1);
}

TEST_CASE("Testing the move function") {
    auto board = new tictactoe3();

    board->move(7, medium);
    auto state = board->state;
    int answer[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 200, 0}};

    CHECK(test_equality(answer, state));

    board->move(7, small);
    state = board->state;
    answer[2][1] = 210;

    CHECK(test_equality(answer, state));

    board->move(7, large);
    state = board->state;
    answer[2][1] = 213;

    CHECK(test_equality(answer, state));
}

/* TEST_CASE("Testing the unmove function") {

    auto board = new tictactoe3();

    board->move(4);
    board->move(3);
    board->move(4);
    board->move(2);

    board->display();
    board->unmove(4);
    board->display();
    auto state = board->get_state();
    std::vector<std::vector<int>> answer = {
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, -1, -1, 1, 0, 0}};

    bool equal = compare_boards(state, answer, false);

    CHECK(equal);
} */

/* TEST_CASE("Testing the win function") {

    SUBCASE("Test Vertical") {
        auto board = new tictactoe3();

        board->move(4);
        board->move(2);
        board->move(4);
        board->move(2);
        board->move(4);
        board->move(2);
        board->move(4);

        board->display();
        bool win = board->is_win(4);

        CHECK(win == true);
    }

    SUBCASE("Test Horizontal") {
        auto board = new tictactoe3();

        board->move(0);
        board->move(0);
        board->move(1);
        board->move(0);
        board->move(2);
        board->move(0);
        board->move(3);

        board->display();
        bool win = board->is_win(3);

        CHECK(win == true);
    }

    SUBCASE("Test Diagonal") {
        auto board = new tictactoe3();

        board->set_state({
                        {0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 1, -1, 0},
                        {0, 0, 0, 1, -1, -1, 0},
                        {1, 1, 1, -1, -1, -1, 0}
        });

        board->display();

        bool win = board->is_win(5);

        CHECK(win == true);
    }
} */
