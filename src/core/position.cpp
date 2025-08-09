#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include "position.hpp"
#include "bitboard.hpp"
#include "types.hpp"

const std::string startposFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

Position::Position() { import_FEN(startposFEN); }
Position::Position(std::string FEN) { import_FEN(FEN); }

Position::Position(const Position& p) {
    if (this != &p) {
        this->board   = p.board;
        this->st      = p.st;
        this->history = p.history;
    }
}

Position& Position::operator=(const Position& p) {
    if (this != &p) {
        this->board   = p.board;
        this->st      = p.st;
        this->history = p.history;
    }
    return *this;
}

Piece Position::piece_at_pos(int j) const {
    for (int i = 0; i < 12; i++)
    {
        if ((board.board.at(i) >> j) & 1)
        {
            return static_cast<Piece>(i);
        }
    }

    return NO_PIECE;
}

bool Position::is_allowed_to_00() const {
    if (st.side_to_move == Color::WHITE)
    {
        return st.castling_availability & 1;
    }
    else
    {
        return st.castling_availability & 4;
    }
}

bool Position::is_allowed_to_000() const {
    if (st.side_to_move == Color::WHITE)
    {
        return st.castling_availability & 2;
    }
    else
    {
        return st.castling_availability & 8;
    }
}

bool Position::king_is_attacked(Color c) const {
    return (board.board.at(PieceType_to_Piece(KING, c)) & get_controlled_squares(~c)) != 0;
}


bool Position::has_queen(Color c) const {
    if (c == Color::WHITE){
        return board.board.at(W_QUEEN) != Bitboard(0);
    }
    else if (c == Color::BLACK) {
        return board.board.at(B_QUEEN) != Bitboard(0);
    }

    return false;
}

int Position::number_of_pieces(Color c) const {
    if (c != Color::NO_COLOR) {
        Bitboard bb = get_occupied_bitboard(c); 
        return __builtin_popcountll(bb);
    }

    return 0;
}











Square str_square_to_square(std::string sq) {
    int file = sq.at(0) - 'a';
    int rank = sq.at(1) - '1';
    return static_cast<Square>(8 * rank + file);
}

std::string square_to_str_square(Square sq) {
    int file = sq % 8;
    int rank = sq / 8;
    return std::string() + (char) (file + 'a') + (char) (rank + '1');
}

bool Position::import_FEN(std::string FEN) {
    std::unordered_map<char, Piece> piece_char_to_piece = {
      {'K', W_KING},   {'Q', W_QUEEN},  {'R', W_ROOK},   {'B', W_BISHOP},
      {'N', W_KNIGHT}, {'P', W_PAWN},   {'k', B_KING},   {'q', B_QUEEN},
      {'r', B_ROOK},   {'b', B_BISHOP}, {'n', B_KNIGHT}, {'p', B_PAWN}};

    std::stringstream ss(FEN);
    std::string       seg;

    // clear the board
    this->board = {Bitboard(0), Bitboard(0), Bitboard(0), Bitboard(0), Bitboard(0), Bitboard(0),
                   Bitboard(0), Bitboard(0), Bitboard(0), Bitboard(0), Bitboard(0), Bitboard(0)};

    ss >> seg;
    int r = 7, c = 0;
    for (const char ch : seg)
    {
        if (ch == '/')
        {
            r--;
            c = 0;
        }
        else if ('0' <= ch && ch < '9')
        {
            c += ch - '0';
        }
        else
        {
            put_piece(piece_char_to_piece.at(ch), static_cast<Square>(8 * r + c));
            c++;
        }
    }

    ss >> seg;
    st.side_to_move = (seg == "w" ? Color::WHITE : Color::BLACK);

    ss >> seg;
    st.castling_availability = 0;
    if (seg.find("K") != std::string::npos)
    {
        st.castling_availability |= 1;
    }
    if (seg.find("Q") != std::string::npos)
    {
        st.castling_availability |= 2;
    }
    if (seg.find("k") != std::string::npos)
    {
        st.castling_availability |= 4;
    }
    if (seg.find("q") != std::string::npos)
    {
        st.castling_availability |= 8;
    }

    ss >> seg;
    if (seg == "-")
    {
        st.en_passant_target_square = NO_SQUARE;
    }
    else
    {
        st.en_passant_target_square = str_square_to_square(seg);
    }

    ss >> seg;
    st.halfmove_clock = std::stoi(seg);

    ss >> seg;
    st.fullmove_number = std::stoi(seg);

    return true;
}


std::string Position::to_string() const {
    std::string          str  = "";
    std::array<char, 13> symb = {' ', 'K', 'Q', 'R', 'B', 'N', 'P', 'k', 'q', 'r', 'b', 'n', 'p'};

    for (int row = 7; row >= 0; --row)
    {
        str += std::to_string(row + 1);
        str += "|";
        for (int col = 0; col < 8; ++col)
        {
            str += symb.at(piece_at_pos(8 * row + col) + 1);
            str += " ";
        }
        str += "\n";
    }

    str += " +---------------\n  ";
    for (int col = 0; col < 8; ++col)
    {
        str += (char) (col + 'a');
        str += " ";
    }

    str += "\n\n";
    str += (st.side_to_move == Color::WHITE ? "w" : "b");
    str += " ";
    str += ((st.castling_availability >> 0) & 1 ? "K" : "");
    str += ((st.castling_availability >> 1) & 1 ? "Q" : "");
    str += ((st.castling_availability >> 2) & 1 ? "k" : "");
    str += ((st.castling_availability >> 3) & 1 ? "q" : "");
    str += " ";
    str += (st.en_passant_target_square == NO_SQUARE
              ? "-"
              : square_to_str_square(st.en_passant_target_square));
    str += " ";
    str += std::to_string(st.halfmove_clock);
    str += " ";
    str += std::to_string(st.fullmove_number);
    str += "\n\n";

    return str;
}

std::ostream& operator<<(std::ostream& os, const Position& p) {
    os << p.to_string();
    return os;
}

bool operator==(const StateInfo& st1, const StateInfo& st2){
    return (
        st1.captured_piece == st2.captured_piece &&
        st1.castling_availability == st2.castling_availability &&
        st1.en_passant_target_square == st2.en_passant_target_square &&
        st1.captured_piece == st2.captured_piece &&
        st1.fullmove_number == st2.fullmove_number &&
        st1.halfmove_clock == st2.halfmove_clock &&
        st1.side_to_move == st2.side_to_move
    );
}

bool operator==(const Position& p1, const Position& p2){
    return (p1.board == p2.board && p1.st == p2.st && p1.history == p2.history);
}
