#include <string>

#include "position.hpp"
#include "move.hpp"

// clang-format off
const Bitboard BishopAttack[64] = {
  9241421688590303744ULL,    36099303471056128ULL,      141012904249856ULL,
         550848566272ULL,           6480472064ULL,        1108177604608ULL,
      283691315142656ULL,    72624976668147712ULL,  4620710844295151618ULL,
  9241421688590368773ULL,    36099303487963146ULL,      141017232965652ULL,
        1659000848424ULL,      283693466779728ULL,    72624976676520096ULL,
   145249953336262720ULL,  2310355422147510788ULL,  4620710844311799048ULL,
  9241421692918565393ULL,    36100411639206946ULL,      424704217196612ULL,
    72625527495610504ULL,   145249955479592976ULL,   290499906664153120ULL,
  1155177711057110024ULL,  2310355426409252880ULL,  4620711952330133792ULL,
  9241705379636978241ULL,   108724279602332802ULL,   145390965166737412ULL,
   290500455356698632ULL,   580999811184992272ULL,   577588851267340304ULL,
  1155178802063085600ULL,  2310639079102947392ULL,  4693335752243822976ULL,
  9386671504487645697ULL,   326598935265674242ULL,   581140276476643332ULL,
  1161999073681608712ULL,   288793334762704928ULL,   577868148797087808ULL,
  1227793891648880768ULL,  2455587783297826816ULL,  4911175566595588352ULL,
  9822351133174399489ULL,  1197958188344280066ULL,  2323857683139004420ULL,
   144117404414255168ULL,   360293502378066048ULL,   720587009051099136ULL,
  1441174018118909952ULL,  2882348036221108224ULL,  5764696068147249408ULL,
 11529391036782871041ULL,  4611756524879479810ULL,      567382630219904ULL,
     1416240237150208ULL,     2833579985862656ULL,     5667164249915392ULL,
    11334324221640704ULL,    22667548931719168ULL,    45053622886727936ULL,
    18049651735527937ULL,
};

const Bitboard RookAttack[64] = {
    72340172838076926ULL,   144680345676153597ULL,   289360691352306939ULL,
   578721382704613623ULL,  1157442765409226991ULL,  2314885530818453727ULL,
  4629771061636907199ULL,  9259542123273814143ULL,    72340172838141441ULL,
   144680345676217602ULL,   289360691352369924ULL,   578721382704674568ULL,
  1157442765409283856ULL,  2314885530818502432ULL,  4629771061636939584ULL,
  9259542123273813888ULL,    72340172854657281ULL,   144680345692602882ULL,
   289360691368494084ULL,   578721382720276488ULL,  1157442765423841296ULL,
  2314885530830970912ULL,  4629771061645230144ULL,  9259542123273748608ULL,
    72340177082712321ULL,   144680349887234562ULL,   289360695496279044ULL,
   578721386714368008ULL,  1157442769150545936ULL,  2314885534022901792ULL,
  4629771063767613504ULL,  9259542123257036928ULL,    72341259464802561ULL,
   144681423712944642ULL,   289361752209228804ULL,   578722409201797128ULL,
  1157443723186933776ULL,  2314886351157207072ULL,  4629771607097753664ULL,
  9259542118978846848ULL,    72618349279904001ULL,   144956323094725122ULL,
   289632270724367364ULL,   578984165983651848ULL,  1157687956502220816ULL,
  2315095537539358752ULL,  4629910699613634624ULL,  9259541023762186368ULL,
   143553341945872641ULL,   215330564830528002ULL,   358885010599838724ULL,
   645993902138460168ULL,  1220211685215703056ULL,  2368647251370188832ULL,
  4665518383679160384ULL,  9259260648297103488ULL, 18302911464433844481ULL,
 18231136449196065282ULL, 18087586418720506884ULL, 17800486357769390088ULL,
 17226286235867156496ULL, 16077885992062689312ULL, 13781085504453754944ULL,
  9187484529235886208ULL,
};

const Bitboard KnightAttack[64] = { 
               132096ULL,               329728ULL,               659712ULL,
              1319424ULL,              2638848ULL,              5277696ULL,
             10489856ULL,              4202496ULL,             33816580ULL,
             84410376ULL,            168886289ULL,            337772578ULL,
            675545156ULL,           1351090312ULL,           2685403152ULL,
           1075839008ULL,           8657044482ULL,          21609056261ULL,
          43234889994ULL,          86469779988ULL,         172939559976ULL,
         345879119952ULL,         687463207072ULL,         275414786112ULL,
        2216203387392ULL,        5531918402816ULL,       11068131838464ULL,
       22136263676928ULL,       44272527353856ULL,       88545054707712ULL,
      175990581010432ULL,       70506185244672ULL,      567348067172352ULL,
     1416171111120896ULL,     2833441750646784ULL,     5666883501293568ULL,
    11333767002587136ULL,    22667534005174272ULL,    45053588738670592ULL,
    18049583422636032ULL,   145241105196122112ULL,   362539804446949376ULL,
   725361088165576704ULL,  1450722176331153408ULL,  2901444352662306816ULL,
  5802888705324613632ULL, 11533718717099671552ULL,  4620693356194824192ULL,
   288234782788157440ULL,   576469569871282176ULL,  1224997833292120064ULL,
  2449995666584240128ULL,  4899991333168480256ULL,  9799982666336960512ULL,
  1152939783987658752ULL,  2305878468463689728ULL,     1128098930098176ULL,
     2257297371824128ULL,     4796069720358912ULL,     9592139440717824ULL,
    19184278881435648ULL,    38368557762871296ULL,     4679521487814656ULL,
     9077567998918656ULL,
};

const Bitboard KingAttack[64] = {
                  770ULL,                 1797ULL,                 3594ULL,
                 7188ULL,                14376ULL,                28752ULL,
                57504ULL,                49216ULL,               197123ULL,
               460039ULL,               920078ULL,              1840156ULL,
              3680312ULL,              7360624ULL,             14721248ULL,
             12599488ULL,             50463488ULL,            117769984ULL,
            235539968ULL,            471079936ULL,            942159872ULL,
           1884319744ULL,           3768639488ULL,           3225468928ULL,
          12918652928ULL,          30149115904ULL,          60298231808ULL,
         120596463616ULL,         241192927232ULL,         482385854464ULL,
         964771708928ULL,         825720045568ULL,        3307175149568ULL,
        7718173671424ULL,       15436347342848ULL,       30872694685696ULL,
       61745389371392ULL,      123490778742784ULL,      246981557485568ULL,
      211384331665408ULL,      846636838289408ULL,     1975852459884544ULL,
     3951704919769088ULL,     7903409839538176ULL,    15806819679076352ULL,
    31613639358152704ULL,    63227278716305408ULL,    54114388906344448ULL,
   216739030602088448ULL,   505818229730443264ULL,  1011636459460886528ULL,
  2023272918921773056ULL,  4046545837843546112ULL,  8093091675687092224ULL,
 16186183351374184448ULL, 13853283560024178688ULL,   144959613005987840ULL,
   362258295026614272ULL,   724516590053228544ULL,  1449033180106457088ULL,
  2898066360212914176ULL,  5796132720425828352ULL, 11592265440851656704ULL,
  4665729213955833856ULL,
};
// clang-format on

std::string Move::to_str() {
    std::string str = "";
    str += square_to_str_square(from_square);
    str += square_to_str_square(to_square);
    PieceType pt = promotion_piecetype();
    switch (pt)
    {
    case KNIGHT :
        str += "n";
        break;
    case BISHOP :
        str += "b";
        break;
    case ROOK :
        str += "r";
        break;
    case QUEEN :
        str += "q";
        break;
    default :
        break;
    }
    // str += is_capture() ? " capture" : "";
    // str += is_ep_capture() ? " ep" : "";
    // str += is_promotion() ? " promo" : "";
    // str += is_k_castle() ? " 0-0" : "";
    // str += is_q_castle() ? " 0-0-0" : "";
    // str += is_double_push() ? " dbl. pawn push" : "";
    return str;
}

// removing NO_PIECE should crash, since
// this is undefined behaviour!
void Position::remove_piece(Piece pi, Square sq) { board.board.at(pi) ^= to_bitboard(sq); }

// putting NO_PIECE should crash, since
// this is undefined behaviour!
void Position::put_piece(Piece pi, Square sq) { board.board.at(pi) |= to_bitboard(sq); }

void Position::move_piece(Piece from_pi, Square from_sq, Piece to_pi, Square to_sq) {
    if (from_sq != NO_SQUARE)
    {
        remove_piece(from_pi, from_sq);
    }
    if (to_sq != NO_SQUARE)
    {
        put_piece(to_pi, to_sq);
    }
}


PieceType Move::promotion_piecetype() const {
    if (is_promotion())
    {
        if ((flags & 0b0011) == 0)
        {
            return KNIGHT;
        }
        if ((flags & 0b0011) == SPECIAL_FLAG_0)
        {
            return BISHOP;
        }
        if ((flags & 0b0011) == SPECIAL_FLAG_1)
        {
            return ROOK;
        }
        if ((flags & 0b0011) == (SPECIAL_FLAG_0 | SPECIAL_FLAG_1))
        {
            return QUEEN;
        }
    }
    return NO_PIECE_TYPE;
}


/* the move is assumed to be legal */
void Position::do_move(Move m) {
    prev_st = st;

    Piece p                     = piece_at_pos(m.from_square);
    Piece p_to                  = piece_at_pos(m.to_square);
    st.captured_piece           = p_to;  // this can be NO_PIECE
    st.en_passant_target_square = NO_SQUARE;

    Color us   = st.side_to_move;
    Color them = ~us;

    // update move counters
    if (us == Color::BLACK)
    {
        st.fullmove_number++;
    }

    if (Piece_to_PieceType(p) == PAWN || m.is_capture())
    {
        st.halfmove_clock = 0;
    }
    else
    {
        st.halfmove_clock++;
    }

    if (p == W_KING)
    {
        st.castling_availability &= 0b1100;
    }
    if (p == B_KING)
    {
        st.castling_availability &= 0b0011;
    }
    if (m.from_square == A1 || m.to_square == A1)
    {
        st.castling_availability &= 0b1101;
    }
    if (m.from_square == H1 || m.to_square == H1)
    {
        st.castling_availability &= 0b1110;
    }
    if (m.from_square == A8 || m.to_square == A8)
    {
        st.castling_availability &= 0b0111;
    }
    if (m.from_square == H8 || m.to_square == H8)
    {
        st.castling_availability &= 0b1011;
    }


    // set en passant square
    if (m.is_double_push())
    {
        st.en_passant_target_square = m.to_square + (us == Color::WHITE ? -8 : 8);
    }

    // captures
    if (m.is_ep_capture())
    {
        remove_piece(us == Color::WHITE ? B_PAWN : W_PAWN,
                     m.to_square + (us == Color::WHITE ? -8 : 8));
    }
    else if (m.is_capture())
    {
        remove_piece(p_to, m.to_square);
    }

    // castling moves the rook
    if (us == Color::WHITE)
    {
        if (m.is_k_castle())
        {
            move_piece(W_ROOK, H1, W_ROOK, F1);
        }
        if (m.is_q_castle())
        {
            move_piece(W_ROOK, A1, W_ROOK, D1);
        }
    }
    else
    {
        if (m.is_k_castle())
        {
            move_piece(B_ROOK, H8, B_ROOK, F8);
        }
        if (m.is_q_castle())
        {
            move_piece(B_ROOK, A8, B_ROOK, D8);
        }
    }

    if (m.is_promotion())
    {
        remove_piece(p, m.from_square);
        put_piece(PieceType_to_Piece(m.promotion_piecetype(), st.side_to_move), m.to_square);
    }
    else
    {
        move_piece(p, m.from_square, p, m.to_square);
    }

    st.side_to_move = them;
}

void Position::undo_move(Move m) {
    // see https://github.com/official-stockfish/Stockfish/blob/master/src/position.cpp#L913

    // check promotion
    // check castling
    // move back and check if was capture

    Color us   = ~st.side_to_move;
    // Color them = ~us;
    Piece p    = piece_at_pos(m.to_square);

    remove_piece(p, m.to_square);
    if (m.is_capture())
    {
        if (m.is_ep_capture())
        {
            put_piece((us == Color::WHITE ? B_PAWN : W_PAWN),
                      m.to_square + (us == Color::WHITE ? -8 : 8));
        }
        else if (st.captured_piece != NO_PIECE)
        {
            put_piece(st.captured_piece, m.to_square);
        }
    }

    // castling moves the rook
    if (us == Color::WHITE)
    {
        if (m.is_k_castle())
        {
            move_piece(W_ROOK, F1, W_ROOK, H1);
        }
        if (m.is_q_castle())
        {
            move_piece(W_ROOK, D1, W_ROOK, A1);
        }
    }
    else
    {
        if (m.is_k_castle())
        {
            move_piece(B_ROOK, F8, B_ROOK, H8);
        }
        if (m.is_q_castle())
        {
            move_piece(B_ROOK, D8, B_ROOK, A8);
        }
    }

    if (m.is_promotion())
    {
        put_piece((us == Color::WHITE ? W_PAWN : B_PAWN), m.from_square);
    }
    else
    {
        put_piece(p, m.from_square);
    }

    // reset StateInfo
    st = prev_st;
}


Move Position::alg_move_to_move(std::string m_alg) {
    Square from  = str_square_to_square(m_alg.substr(0, 2));
    Square to    = str_square_to_square(m_alg.substr(2, 2));
    char   flags = 0;

    bool  is_piece_at_to_square = (piece_at_pos(to) != NO_PIECE);
    Piece piece_at_from_square  = piece_at_pos(from);
    if (piece_at_from_square == NO_PIECE) {
        return Move(NO_SQUARE, NO_SQUARE, 0);
    }

    // standard capture
    if (is_piece_at_to_square)
    {
        flags |= CAPTURE_FLAG;
    }

    // if promotion
    if (m_alg.length() == 5)
    {
        flags |= PROMOTION_FLAG;

        char p = m_alg.at(4);

        if (p == 'b')
        {
            flags |= SPECIAL_FLAG_0;
        }
        if (p == 'r')
        {
            flags |= SPECIAL_FLAG_1;
        }
        if (p == 'q')
        {
            flags |= (SPECIAL_FLAG_1 | SPECIAL_FLAG_0);
        }
    }


    if (Piece_to_PieceType(piece_at_from_square) == PAWN)
    {
        // double push
        if (abs(row(to) - row(from)) == 2)
        {
            flags |= SPECIAL_FLAG_0;
        }

        // ep-capture
        if (file(from) != file(to) && !is_piece_at_to_square)
        {
            flags |= (CAPTURE_FLAG | SPECIAL_FLAG_1);
        }
    }

    // castling
    if (Piece_to_PieceType(piece_at_from_square) == KING)
    {
        // queen side
        if (file(to) - file(from) == -2)
        {
            flags |= (SPECIAL_FLAG_0 | SPECIAL_FLAG_1);
        }

        // king side
        if (file(to) - file(from) == 2)
        {
            flags |= SPECIAL_FLAG_1;
        }
    }

    return Move(from, to, flags);
}


Bitboard get_attacking_squares_sliding(Square sq, Bitboard occupied_sqs, bool diagonal) {
    std::pair<int, int> directions_straight[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::pair<int, int> directions_diagonal[4] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    Bitboard bb(0);
    int      row = sq / 8;
    int      col = sq % 8;
    for (const auto dir : (diagonal ? directions_diagonal : directions_straight))
    {
        int _row = row;
        int _col = col;
        while (1)
        {
            _row += dir.second;
            _col += dir.first;
            if (!in_board(_row, _col))
            {
                break;
            }

            bb |= to_bitboard(_row, _col);

            if (is_occupied(occupied_sqs, _row, _col))
            {
                break;
            }
        }
    }

    return bb;
}

Bitboard get_attacking_squares_pawn(Color c, Square sq) {
    Bitboard bb(0);

    int row = sq / 8;
    int col = sq % 8;

    /* we know that pawn cannot
     * be on the 8th rank, so no need to
     * think about that. */

    int direction = (c == Color::WHITE ? 1 : -1);

    if (col != 0)
    {
        bb |= to_bitboard(row + direction, col - 1);
    }

    if (col != 7)
    {
        bb |= to_bitboard(row + direction, col + 1);
    }

    return bb;
}

Bitboard get_attacking_squares(const Piece p, Square sq, Bitboard occupied_sqs) {
    switch (Piece_to_PieceType(p))
    {
    case PAWN :
        return get_attacking_squares_pawn(Piece_to_Color(p), sq);
    case KNIGHT :
        return KnightAttack[sq];
    case KING :
        return KingAttack[sq];
    case BISHOP :
        return get_attacking_squares_sliding(sq, occupied_sqs, true);
    case ROOK :
        return get_attacking_squares_sliding(sq, occupied_sqs, false);
    case QUEEN :
        return get_attacking_squares_sliding(sq, occupied_sqs, true)
             | get_attacking_squares_sliding(sq, occupied_sqs, false);
    default:
        return Bitboard(0);
    }
}


Bitboard Position::get_controlled_squares(Color c) const {
    Bitboard controlled_squares = Bitboard(0);
    Bitboard occupied_sqs       = get_occupied_bitboard();
    for (int i = 0; i < 6; i++)
    {
        Piece piece;
        if (c == Color::WHITE)
        {
            piece = static_cast<Piece>(i);
        }
        else
        {
            piece = static_cast<Piece>(i + 6);
        }

        Bitboard bb = board.board.at(piece);
        while (bb)
        {
            Square   from_square = pop_lsb(bb);
            Bitboard bb_attack   = get_attacking_squares(piece, from_square, occupied_sqs);
            controlled_squares |= bb_attack;
        }
    }

    return controlled_squares;
}


void Position::gen_pseudo_legal_moves(std::vector<Move>& moves, const Piece piece) const {
    const Color us = st.side_to_move;

    const Bitboard occ_sqs   = get_occupied_bitboard();
    const Bitboard my_pieces = get_occupied_bitboard(us);

    Bitboard bb = board.board.at(piece);
    while (bb)
    {
        Square   from_square = pop_lsb(bb);
        Bitboard bb_move     = (get_attacking_squares(piece, from_square, occ_sqs) & ~occ_sqs);
        Bitboard bb_attack =
          (get_attacking_squares(piece, from_square, occ_sqs) & ~my_pieces) & ~bb_move;

        while (bb_move)
        {
            moves.emplace_back(Move(from_square, pop_lsb(bb_move), 0));
        }

        while (bb_attack)
        {
            moves.emplace_back(Move(from_square, pop_lsb(bb_attack), CAPTURE_FLAG));
        }
    }
}


void Position::gen_pseudo_legal_pawn_moves(std::vector<Move>& moves) const {
    const Color us   = st.side_to_move;
    const Color them = ~us;

    const Bitboard occ_sqs    = get_occupied_bitboard();
    const Bitboard opp_pieces = get_occupied_bitboard(them);

    const char promotion_flags[4] = {
        PROMOTION_FLAG,
        PROMOTION_FLAG | SPECIAL_FLAG_0,
        PROMOTION_FLAG | SPECIAL_FLAG_1,
        PROMOTION_FLAG | SPECIAL_FLAG_0 | SPECIAL_FLAG_1,
    };

    const Piece p  = (us == Color::WHITE) ? W_PAWN : B_PAWN;
    Bitboard    bb = board.board.at(p);
    while (bb)
    {
        Square from_square = pop_lsb(bb);

        // standard move
        int    delta     = (us == Color::WHITE ? 8 : -8);
        Square to_square = from_square + delta;

        if (!(to_bitboard(to_square) & occ_sqs))
        {
            if (is7rank(from_square, us))
            {
                for (const auto flag : promotion_flags) {
                    moves.emplace_back(Move(from_square, to_square, flag));
                }
            }
            else
            {
                moves.emplace_back(Move(from_square, to_square, 0));
            }

            if (from_square / 8 == (us == Color::WHITE ? 1 : 6))
            {
                to_square = from_square + 2 * delta;
                if (!(to_bitboard(to_square) & occ_sqs))
                {
                    moves.emplace_back(
                      Move(from_square, to_square, SPECIAL_FLAG_0));  // double pawn push
                }
            }
        }

        // captures and en passant
        Bitboard bb_attack = get_attacking_squares(p, from_square, occ_sqs);

        Bitboard bb_capture    = bb_attack & opp_pieces;
        Bitboard bb_ep_capture = 0;

        if (st.en_passant_target_square != NO_SQUARE)
        {
            bb_ep_capture = bb_attack & to_bitboard(st.en_passant_target_square);
        }

        if (is7rank(from_square, us))
        {
            while (bb_capture)
            {
                Square sq = pop_lsb(bb_capture);

                for (const auto flag : promotion_flags) {
                    moves.emplace_back(Move(from_square, sq, CAPTURE_FLAG | flag));
                }
            }
        }
        else
        {
            while (bb_capture)
            {
                moves.emplace_back(Move(from_square, pop_lsb(bb_capture), CAPTURE_FLAG));
            }
        }


        while (bb_ep_capture)
        {
            moves.emplace_back(
              Move(from_square, pop_lsb(bb_ep_capture), CAPTURE_FLAG | SPECIAL_FLAG_0));
        }
    }
}


void Position::gen_pseudo_legal_king_moves(std::vector<Move>& moves) const {
    const Color us   = st.side_to_move;
    const Color them = ~us;

    const Bitboard occ_sqs   = get_occupied_bitboard();
    const Bitboard my_pieces = get_occupied_bitboard(us);
    const Piece    piece     = (us == Color::WHITE) ? W_KING : B_KING;

    const Bitboard area_00                = Bitboard(3UL << (us == Color::WHITE ? 5 : 61));
    const Bitboard area_00_king_movement  = Bitboard(3UL << (us == Color::WHITE ? 4 : 60));
    const Bitboard area_000               = Bitboard(7UL << (us == Color::WHITE ? 1 : 57));
    const Bitboard area_000_king_movement = Bitboard(3UL << (us == Color::WHITE ? 3 : 59));
    Bitboard       bb                     = board.board.at(piece);
    Square         from_square            = pop_lsb(bb);  // there is only 1 king

    Bitboard bb_move = (get_attacking_squares(piece, from_square, occ_sqs) & ~occ_sqs);
    Bitboard bb_attack =
      (get_attacking_squares(piece, from_square, occ_sqs) & ~my_pieces) & ~bb_move;

    while (bb_move)
    {
        moves.emplace_back(Move(from_square, pop_lsb(bb_move), 0));
    }

    while (bb_attack)
    {
        moves.emplace_back(Move(from_square, pop_lsb(bb_attack), CAPTURE_FLAG));
    }


    if (is_allowed_to_00())
    {
        // check if area is free
        if ((area_00 & occ_sqs) == Bitboard(0))
        {
            // check if area is not hit by the enemy
            if ((area_00_king_movement & get_controlled_squares(them)) == Bitboard(0))
            {
                moves.emplace_back(
                  Move((us == Color::WHITE) ? E1 : E8, (us == Color::WHITE) ? G1 : G8, 2));
            }
        }
    }

    if (is_allowed_to_000())
    {
        // check if area is free
        if ((area_000 & occ_sqs) == Bitboard(0))
        {
            // check if area is not hit by enemy
            if ((area_000_king_movement & get_controlled_squares(them)) == Bitboard(0))
            {
                moves.emplace_back(
                  Move((us == Color::WHITE) ? E1 : E8, (us == Color::WHITE) ? C1 : C8, 3));
            }
        }
    }
}

std::vector<Move> Position::get_pseudo_legal_moves() const {
    std::vector<Move> moves = {};
    const Color       us    = st.side_to_move;

    /* queen */  // todo: since queen is rook + bishop, can we do gen queen at the same time as we gen bishop + rook?
    gen_pseudo_legal_moves(moves, (us == Color::WHITE) ? W_QUEEN : B_QUEEN);
    /* rook */
    gen_pseudo_legal_moves(moves, (us == Color::WHITE) ? W_ROOK : B_ROOK);
    /* bishop */
    gen_pseudo_legal_moves(moves, (us == Color::WHITE) ? W_BISHOP : B_BISHOP);
    /* knight */
    gen_pseudo_legal_moves(moves, (us == Color::WHITE) ? W_KNIGHT : B_KNIGHT);
    /* pawn */
    gen_pseudo_legal_pawn_moves(moves);
    /* king */
    gen_pseudo_legal_king_moves(moves);

    return moves;
}

bool Position::is_legal(Move move) const {
    Position    p  = *this;  // copying the current position
    const Color us = st.side_to_move;
    const Color them = ~us;

    if (move.from_square == NO_SQUARE || move.to_square == NO_SQUARE) {
        return false;
    }

    // hacky way to make sure that castling out of check is illegal
    if (p.king_is_attacked(us) && (move.is_k_castle() || move.is_q_castle()))
    {
        return false;
    }

    p.do_move(move);
    return !p.king_is_attacked(us);
}

std::vector<Move> Position::get_legal_moves() const {
    /*
     * At the moment I am just
     * copying the current position
     * and trying out all pseudo legal
     * moves to check if my king
     * is in check. There is perhaps
     * a way to do this without actually
     * doing the moves?
     * */

    Position    p  = *this;  // copying the current position
    const Color us = st.side_to_move;

    std::vector<Move> pseudo_moves = get_pseudo_legal_moves();
    std::vector<Move> legal_moves  = {};

    for (auto move : pseudo_moves)
    {
        p.do_move(move);
        if (!p.king_is_attacked(us))
        {
            legal_moves.emplace_back(move);
        }
        p.undo_move(move);
    }

    return legal_moves;
}
