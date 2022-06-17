//
// Created by Cyrullian Saharmac on 4/3/21.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tictactoe3.h"

bool compare_boards(std::vector<std::vector<int>> vec1, std::vector<std::vector<int>> vec2, bool display) {
    bool equal = true;

    for (int i = 0; i < vec2.size(); i++) {

        if (display) {
            for(int j = 0; j < vec1[i].size(); j++)
                std::cout << vec1[i].at(j) << ' ';
            std::cout << "" << std::endl;

            for(int j = 0; j < vec2[i].size(); j++)
                std::cout << vec2[i].at(j) << ' ';

            std::cout << "\n" << std::endl;
        }

        equal = (vec1[i] == vec2[i] & equal);
    }
    return equal;
}

TEST_CASE("Testing the display function") {
    auto board = new tictactoe3(6,7,4);
    board->display();
    CHECK(1 == 1);
}

TEST_CASE("Testing the move function") {

        auto board = new tictactoe3(6, 7, 4);

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
}

TEST_CASE("Testing the unmove function") {

    auto board = new tictactoe3(6, 7, 4);

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
}

TEST_CASE("Testing the win function") {

    SUBCASE("Test Vertical") {
        auto board = new tictactoe3(6, 7, 4);

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
        auto board = new tictactoe3(6, 7, 4);

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
        auto board = new tictactoe3(6, 7, 4);

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
}

TEST_CASE("Testing the draw function") {

    auto board = new tictactoe3(6, 7, 4);

    board->set_state({
        {1, 1, -1, 1, -1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    });

    board->display();

    bool draw = board->is_draw();

    CHECK(draw == true);
}

TEST_CASE("Testing the legal function") {

    auto board = new tictactoe3(6, 7, 4);

    board->set_state({
                          {1, 1, 0, 1, -1, 1, 0},
                          {0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0}
                  });

    board->display();

    std::vector<int> legal_actions = board->legal();

    std::vector<int> answer = {0, 0, 1, 0, 0, 0, 1};

    CHECK(legal_actions == answer);
}