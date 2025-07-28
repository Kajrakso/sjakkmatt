#include "bitboard.hpp"
#include "position.hpp"

Bitboard Position::get_occupied_bitboard() const {
    Bitboard b(0);

    for (int i = 0; i < 12; i++)
    {
        b |= board.board.at(i);
    }

    return b;
}

Bitboard Position::get_occupied_bitboard(Color c) const {
    Bitboard b(0);

    if (c == Color::WHITE) {
        for (int i = 0; i < 6; i++)
        {
            b |= board.board.at(i);
        }
    }
    else if (c == Color::BLACK) {
        for (int i = 6; i < 12; i++)
        {
            b |= board.board.at(i);
        }
    }

    return b;
}


