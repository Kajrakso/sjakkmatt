#pragma once
#include "core/position.hpp"

#define LOG(x) (std::cerr << (x));

static void log_st(StateInfo st) {
    std::cerr << "StateInfo {\n"
              << "\tside_to_move: " << (st.side_to_move == Color::WHITE ? "w" : "b") << std::endl
              << "\tfullmove_number: " << st.fullmove_number << std::endl
              << "\thalfmove_clock: " << st.halfmove_clock << std::endl
              << "\tcastling_availability: " << ((st.castling_availability >> 0) & 1)
              << ((st.castling_availability >> 1) & 1) << ((st.castling_availability >> 2) & 1)
              << ((st.castling_availability >> 3) & 1) << std::endl
              << "\ten_passant_target_square: "
              << (st.en_passant_target_square != NO_SQUARE
                    ? square_to_str_square(st.en_passant_target_square)
                    : "NA")
              << std::endl

              << "}" << std::endl;
}

static void visualize_bitboard(Bitboard b) {
    std::string s = "";
    for (int row = 7; row >= 0; --row)
    {
        s += std::to_string(row + 1) + "|";
        for (int col = 0; col < 8; ++col)
        {
            s += (((b >> (8 * row + col)) & 1) ? "X " : "  ");
        }
        s += "\n";
    }
    s += " +----------------\n  ";
    for (int col = 0; col < 8; ++col)
    {
        s += (char) (col + 'a');
        s += " ";
    }
    std::cerr << s << std::endl;
}
