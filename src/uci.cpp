#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

#include "uci.hpp"
#include "engine.hpp"
#include "logging.hpp"
#include "perft.hpp"
#include "core/position.hpp"

void uci_loop() {
    srand((unsigned int)time(NULL));

    std::string line;
    Position    p = Position();
    while (std::getline(std::cin, line))
    {
        std::string        cmd;
        std::istringstream is(line);

        if (is >> cmd)
        {

            if (cmd == "uci")
            {
                std::cout << "id name sjakkmatt" << "\n"
                          << "id author Oskar Feed Jakobsen" << "\n"
                          << "uciok" << "\n";
            }
            else if (cmd == "isready")
            {
                std::cout << "readyok" << "\n";
            }
            else if (cmd == "position")
            {
                // parse FEN and move list
                std::string pos, is_moves, move;
                std::string fen, position, color, castle, ep, hm, fm;

                p = Position();
                is >> pos;
                if (pos == "fen")
                {
                    is >> position >> color >> castle >> ep >> hm >> fm;
                    fen = position + " " + color + " " + castle + " " + ep + " " + hm + " " + fm;
                    p   = Position(fen);
                }
                else if (pos != "startpos")
                {
                    continue;
                }

                is >> is_moves;
                if (is_moves == "moves")
                {
                    while (is >> move)
                    {
                        /* if the move is illegal (or is not a move at all)
                        we should ignore it and all the moves that follow */

                        Move              m           = p.alg_move_to_move(move);
                        std::vector<Move> legal_moves = p.get_legal_moves();

                        auto it = std::find(legal_moves.begin(), legal_moves.end(), m);
                        if (it == legal_moves.end())
                        {
                            break;
                        }

                        p.do_move(m);
                    }
                }

                LOG(p)
            }
            else if (cmd == "ucinewgame")
            {
                LOG("not implemented yet\n")
            }
            else if (cmd == "go")
            {
                stop_thinking();
                start_thinking(p);
            }
            else if (cmd == "stop")
            {
                stop_thinking();
            }
            else if (cmd == "perft")
            {
                std::string depth;
                if (is >> depth)
                {
                    int d = stoi(depth);
                    do_perft(p, d);
                }
            }
            else if (cmd == "quit")
            {
                stop_thinking();
                break;
            }
        }
    }
}
