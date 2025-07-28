#include "perft.hpp"

size_t Perft(Position& pos, int depth) {
    std::vector<Move> move_list;
    size_t            n_moves, i;
    size_t            nodes = 0;

    if (depth == 0)
        return 1ULL;

    move_list = pos.get_legal_moves();
    n_moves   = move_list.size();

    for (i = 0; i < n_moves; i++)
    {
        Position pos2 = pos;
        Move     m    = move_list.at(i);

        pos2.do_move(m);
        nodes += Perft(pos2, depth - 1);
        // pos.undo_move(move_list.at(i));
    }
    return nodes;
}

size_t do_perft(Position& p, int d) {
    size_t total_nodes = 0;
    for (auto move : p.get_legal_moves())
    {
        Position p2 = p;
        p2.do_move(move);
        size_t n = Perft(p2, d - 1);
        std::cout << move.to_str() << ": " << n << std::endl;
        total_nodes += n;
    }
    std::cout << "Nodes searched: " << total_nodes << std::endl;

    return total_nodes;
}
