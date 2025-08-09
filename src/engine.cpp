#include <vector>

#include "engine.hpp"
#include "evaluation.hpp"

std::thread       search_thread;
std::atomic<bool> stop_flag = false;


int negamax(Position& pos, int depth);

void start_thinking(const Position& p) {
    Position pos = p;

    stop_flag     = false;
    search_thread = std::thread([pos]() mutable {
        int               best_score = VALUE_MATED;
        std::vector<Move> moves      = pos.get_legal_moves();

        if (moves.empty())
        {
            std::cout << "bestmove 0000" << std::endl;
        }
        else
        {
            Move              bestmove   = moves.at(rand() % moves.size());

            for (const Move& move : moves)
            {
                if (stop_flag)
                    break;

                pos.do_move(move);
                int score = -negamax(pos, SEARCH_DEPTH - 1);
                pos.undo_move(move);

                if (score > best_score)
                {

                    best_score = score;
                    bestmove   = move;

                    // std::cout << "info depth " << SEARCH_DEPTH <<
                    //     " score cp " << best_score << " time 0 nps 1 nodes 0 pv "
                    //     << bestmove.to_str() << std::endl;
                }
            }

            std::cout << "bestmove " << bestmove.to_str() << std::endl;
        }
    });
}

void stop_thinking() {
    stop_flag = true;
    if (search_thread.joinable())
    {
        search_thread.join();
    }
}


int negamax(Position& pos, int depth) {
    if (stop_flag)
        return 0;  // Check early

    if (depth == 0)
    {
        return evaluate(pos);  // Terminal condition
    }

    int max_score = VALUE_MATED + depth;
    for (const Move& move : pos.get_legal_moves())
    {
        if (stop_flag)
            return 0;  // Check often

        pos.do_move(move);
        int score = -negamax(pos, depth - 1);
        pos.undo_move(move);

        if (score > max_score)
        {
            max_score = score;
            // Optionally store principal variation or best move
        }
    }
    return max_score;
}
