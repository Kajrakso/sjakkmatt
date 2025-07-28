#pragma once

#include <cstdint>
#include <string>
#include "types.hpp"
#include "bitboard.hpp"

typedef uint16_t MoveInfo;

constexpr MoveInfo SPECIAL_FLAG_0 = 1;
constexpr MoveInfo SPECIAL_FLAG_1 = 2;
constexpr MoveInfo CAPTURE_FLAG   = 4;
constexpr MoveInfo PROMOTION_FLAG = 8;

/*
code	promotion	capture	special 1	special 0	kind of move
0	0	0	0	0	quiet moves
1	0	0	0	1	double pawn push
2	0	0	1	0	king castle
3	0	0	1	1	queen castle
4	0	1	0	0	captures
5	0	1	0	1	ep-capture
8	1	0	0	0	knight-promotion
9	1	0	0	1	bishop-promotion
10	1	0	1	0	rook-promotion
11	1	0	1	1	queen-promotion
12	1	1	0	0	knight-promo capture
13	1	1	0	1	bishop-promo capture
14	1	1	1	0	rook-promo capture
15	1	1	1	1	queen-promo capture
*/

class Move {
   public:
    Move(Square from, Square to, MoveInfo flags) {
        this->from_square = from;
        this->to_square   = to;
        this->flags       = flags;
    }

    Square from_square;
    Square to_square;

    bool is_double_push() const { return (this->flags == SPECIAL_FLAG_0); };
    bool is_k_castle() const { return (this->flags == SPECIAL_FLAG_1); };
    bool is_q_castle() const { return (this->flags == (SPECIAL_FLAG_1 | SPECIAL_FLAG_0)); };
    bool is_capture() const { return (this->flags & CAPTURE_FLAG) != 0; };
    bool is_ep_capture() const { return (this->flags == (CAPTURE_FLAG | SPECIAL_FLAG_0)); };

    bool is_promotion() const { return (this->flags & PROMOTION_FLAG) != 0; };

    PieceType promotion_piecetype() const;

    std::string to_str();

   private:
    MoveInfo flags;
};


extern const Bitboard RookAttack[64];
extern const Bitboard BishopAttack[64];
extern const Bitboard KnightAttack[64];
extern const Bitboard KingAttack[64];

Bitboard get_attacking_squares(Piece p, Square sq, Bitboard occupied_sqs);
