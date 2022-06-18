//
// Created by Cyrullian Saharmac on 4/3/21.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tictactoe3.h"

TEST_CASE("Testing the display function") {
    int state[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
    auto board = new tictactoe3(state);
    board->display();
    int state1[3][3] = {{0,129,231}, {312,457,582}, {624,783,899}};
    auto board1 = new tictactoe3(state1);
    board1->display();
    CHECK(1 == 1);
}

/* TEST_CASE("Testing the move function") {

        auto board = new tictactoe3();

        board->move(4);

        board->display();
        auto state = board->get_state();
        std::vector<std::vector<int>> answer = {{0, 0, 0, 0, 0, 0, 0},
                                                {0, 0, 0, 0, 0, 0, 0},
                                                {0, 0, 0, 0, 0, 0, 0},
                                                {0, 0, 0, 0, 0, 0, 0},
                                                {0, 0, 0, 0, 0, 0, 0},
                                                {0, 0, 0, 0, 1, 0, 0}};

        bool equal = compare_boards(state, answer, false);

        CHECK(equal);
        board->move(4);
        board->display();
        state = board->get_state();
        answer = {{0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, -1, 0, 0},
                  {0, 0, 0, 0, 1, 0, 0}};

        equal = compare_boards(state, answer, false);

        CHECK(equal);
} */

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
