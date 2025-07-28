#pragma once

// clang-format off
enum class Color {
    NO_COLOR = -1,
    WHITE,
    BLACK
};

enum PieceType {
    NO_PIECE_TYPE = -1,
    KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN
};

enum Piece {
    NO_PIECE = -1,
    W_KING, W_QUEEN, W_ROOK, W_BISHOP, W_KNIGHT, W_PAWN,
    B_KING, B_QUEEN, B_ROOK, B_BISHOP, B_KNIGHT, B_PAWN
};

/*
 * squares are numerated 0, ... 63,
 * where 0 is a1, and 63 is h8.
 * rows first, then columns.
 * */
enum Square : short {
    NO_SQUARE = -1,
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
};

enum Direction {
    NORTH = 8,
    NORTHEAST = 9,
    EAST = 1,
    SOUTHEAST = -7,
    SOUTH = -8,
    SOUTHWEST = -9,
    WEST = -1,
    NORTHWEST = 7,
};


// clang-format on
static inline PieceType Piece_to_PieceType(Piece P) {
    // if (P == NO_PIECE) return NO_PIECE_TYPE;
    return static_cast<PieceType>(static_cast<int>(P) % 6);
}

static inline Piece PieceType_to_Piece(PieceType PT, Color c) {
    if (c == Color::WHITE)
    {
        return static_cast<Piece>(PT);
    }
    else if (c == Color::BLACK)
    {
        return static_cast<Piece>(PT + 6);
    }
    return NO_PIECE;
}

static inline Color Piece_to_Color(Piece P) {
    if (P == NO_PIECE)
    {
        return Color::NO_COLOR;
    }
    if (P >= B_KING)
    {
        return Color::BLACK;
    }
    else
    {
        return Color::WHITE;
    }
}

static inline int file(Square sq) { return static_cast<int>(sq) % 8; }

static inline int row(Square sq) { return static_cast<int>(sq) / 8; }

static inline bool is7rank(Square sq, Color c) {
    if (c == Color::WHITE)
    {
        return (row(sq) == 6);
    }
    else if (c == Color::BLACK)
    {
        return (row(sq) == 1);
    }
    return false;
}


static inline Color operator~(Color c) { return (c == Color::WHITE ? Color::BLACK : Color::WHITE); }

static inline Square operator+(Square s, int i) {
    return static_cast<Square>(static_cast<int>(s) + i);
};
