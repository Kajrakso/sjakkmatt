#include "criterion/criterion.h"

#include "../src/core/position.hpp"

TestSuite(position);

Test(position, do_undo_move) {
    srand((unsigned int) time(NULL));
    const int num_moves = 10;

    std::stack<Move> moves_done{};
    std::stack<Position> positions_reached{};

    Position p = Position();
    for (int i = 0; i < num_moves; i++){
        std::vector<Move> legal_moves = p.get_legal_moves();
        size_t num_legal_moves = legal_moves.size();
        Move m = legal_moves.at(rand() % num_legal_moves);

        p.do_move(m);
        moves_done.push(m);
        positions_reached.push(p);
    }

    // then we undo the moves and check if all
    // the positions we reach are equal
    while (!moves_done.empty()) {
        Position p2 = positions_reached.top();
        positions_reached.pop();

        Move m = moves_done.top(); 
        moves_done.pop();

        cr_assert_eq(p, p2);

        p.undo_move(m);
    }

}
