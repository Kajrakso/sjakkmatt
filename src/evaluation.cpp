#include "evaluation.hpp"

int evaluate(const Position p) {
    const Color us   = p.state().side_to_move;
    const Color them = ~us;

    size_t number_of_legal_moves = p.get_legal_moves().size();

    if (number_of_legal_moves == 0)
    {
        if (p.king_is_attacked(us))
        {
            return VALUE_MATED;
        }
        else
        {
            return 0;
        }
    }

    bool we_have_queen   = p.has_queen(us);
    bool they_have_queen = p.has_queen(them);

    int eval_pieces  = (p.number_of_pieces(us) - p.number_of_pieces(them)) * 100;
    int eval_queen   = (we_have_queen - they_have_queen) * 200;
    int random_noice = rand() % 100 - 50;

    return eval_pieces + eval_queen + random_noice;
}
