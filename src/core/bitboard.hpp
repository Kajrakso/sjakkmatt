#pragma once

#include <cassert>
#include <cstdint>
#include <array>
#include "types.hpp"

typedef uint64_t Bitboard;

class Board {
   public:
    std::array<Bitboard, 12> board;

    friend bool operator==(const Board& b1, const Board& b2);

   private:
};

static inline Bitboard to_bitboard(Square sq) { return (Bitboard(1) << sq); }

static inline bool in_board(int row, int col) { return 0 <= row && row < 8 && 0 <= col && col < 8; }

static inline bool is_occupied(Bitboard bb, Square sq) {
    return (bb & to_bitboard(sq)) != 0;
}

static Bitboard to_bitboard(int row, int col) {
    if (in_board(row, col))
    {
        return to_bitboard(static_cast<Square>(8 * row + col));
    }
    else
    {
        return Bitboard(0);
    }
}

static bool is_occupied(Bitboard bb, int row, int col) {
    if (in_board(row, col))
    {
        return is_occupied(bb, static_cast<Square>(8 * row + col));
    }
    return false;
}

inline Square lsb(Bitboard b) {
    assert(b);

#if defined(__GNUC__)  // GCC, Clang, ICX

    return Square(__builtin_ctzll(b));

#elif defined(_MSC_VER)
    #ifdef _WIN64  // MSVC, WIN64

    unsigned long idx;
    _BitScanForward64(&idx, b);
    return Square(idx);

    #else  // MSVC, WIN32
    unsigned long idx;

    if (b & 0xffffffff)
    {
        _BitScanForward(&idx, int32_t(b));
        return Square(idx);
    }
    else
    {
        _BitScanForward(&idx, int32_t(b >> 32));
        return Square(idx + 32);
    }
    #endif
#else  // Compiler is neither GCC nor MSVC compatible
    #error "Compiler not supported."
#endif
}

// Finds and clears the least significant bit in a non-zero bitboard.
inline Square pop_lsb(Bitboard& b) {
    assert(b);
    const Square s = lsb(b);
    b &= b - 1;
    return s;
}
