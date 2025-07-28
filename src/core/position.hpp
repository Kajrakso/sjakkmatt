#pragma once

#include <stdint.h>
#include <iostream>
#include <vector>

#include "bitboard.hpp"
#include "move.hpp"
#include "types.hpp"

struct StateInfo {
    Color        side_to_move;
    unsigned int fullmove_number;
    unsigned int halfmove_clock;
    char         castling_availability;  // 0, ..., 15. KQkq
    Square       en_passant_target_square;
    Piece
      captured_piece;  // if a piece was captured, store it. we need this to be able to undo the move.
};

class Position {
   public:
    Position();
    Position(std::string FEN);
    Position(const Position& p);
    Position& operator=(const Position& p);

    /* the move m is assumed to be legal! */
    void do_move(Move m);
    void undo_move(Move m);

    /* so make sure to check it with is_legal(m)! */
    bool is_legal(Move m) const;

    /* or just use get_legal_moves() */
    std::vector<Move> get_legal_moves() const;

    /* we assume that m_alg is on the correct format: e.g.: e2e4, d7e8q */
    Move alg_move_to_move(std::string m_alg);

    bool                 import_FEN(std::string FEN);
    StateInfo            state() const { return st; };
    StateInfo            prev_state() const { return prev_st; };
    std::string          to_string() const;
    friend std::ostream& operator<<(std::ostream& os, const Position& p);

   private:
    Board     board;
    StateInfo st;
    StateInfo prev_st;

    Piece             piece_at_pos(int j) const;
    void              remove_piece(Piece pi, Square sq);
    void              put_piece(Piece pi, Square sq);
    void              move_piece(Piece from_pi, Square from_sq, Piece to_pi, Square to_sq);
    void              gen_pseudo_legal_moves(std::vector<Move>& moves, const Piece p) const;
    void              gen_pseudo_legal_pawn_moves(std::vector<Move>& moves) const;
    void              gen_pseudo_legal_king_moves(std::vector<Move>& moves) const;
    std::vector<Move> get_pseudo_legal_moves() const;
    Bitboard          get_controlled_squares(Color c) const;
    Bitboard          get_occupied_bitboard() const;
    Bitboard          get_occupied_bitboard(Color c) const;
    bool              is_allowed_to_00() const;
    bool              is_allowed_to_000() const;
    bool              king_is_attacked(Color c) const;
};


Square      str_square_to_square(std::string sq);
std::string square_to_str_square(Square sq);
