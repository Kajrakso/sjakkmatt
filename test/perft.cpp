#include <iostream>
#include <string>

#include "criterion/criterion.h"

#include "../src/perft.hpp"

TestSuite(PERFT);

/* Positions and results from
 * https://www.chessprogramming.org/Perft_Results */
Test(PERFT, startpos) {
    Position p = Position("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    cr_assert_eq(do_perft(p, 1), 20ULL);
    cr_assert_eq(do_perft(p, 2), 400ULL);
    cr_assert_eq(do_perft(p, 3), 8902ULL);
    cr_assert_eq(do_perft(p, 4), 197281ULL);
    cr_assert_eq(do_perft(p, 5), 4865609ULL);
    // cr_assert_eq(do_perft(p, 6), 119060324ULL);
    // cr_assert_eq(do_perft(p, 7), 3195901860ULL);
    // cr_assert_eq(do_perft(p, 8), 84998978956ULL);
    // cr_assert_eq(do_perft(p, 9), 2439530234167ULL);
    // cr_assert_eq(do_perft(p, 10), 69352859712417ULL);
    // cr_assert_eq(do_perft(p, 11), 2097651003696806ULL);
    // cr_assert_eq(do_perft(p, 12), 62854969236701747ULL);
    // cr_assert_eq(do_perft(p, 13), 1981066775000396239ULL);
}

Test(PERFT, pos2) {
    Position p = Position("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1");
    cr_assert_eq(do_perft(p, 1), 48ULL);
    cr_assert_eq(do_perft(p, 2), 2039ULL);
    cr_assert_eq(do_perft(p, 3), 97862ULL);
    // cr_assert_eq(do_perft(p, 4), 4085603ULL);
    // cr_assert_eq(do_perft(p, 5), 193690690ULL);
    // cr_assert_eq(do_perft(p, 6), 8031647685ULL);
}

Test(PERFT, pos3) {
    Position p = Position("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 0 1");
    cr_assert_eq(do_perft(p, 1), 14ULL);
    cr_assert_eq(do_perft(p, 2), 191ULL);
    cr_assert_eq(do_perft(p, 3), 2812ULL);
    cr_assert_eq(do_perft(p, 4), 43238ULL);
    // cr_assert_eq(do_perft(p, 5), 674624ULL);
    // cr_assert_eq(do_perft(p, 6), 11030083ULL);
    // cr_assert_eq(do_perft(p, 7), 178633661ULL);
    // cr_assert_eq(do_perft(p, 8), 3009794393ULL);
}

Test(PERFT, pos4a) {
    Position p = Position("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1");
    cr_assert_eq(do_perft(p, 1), 6ULL);
    cr_assert_eq(do_perft(p, 2), 264ULL);
    cr_assert_eq(do_perft(p, 3), 9467ULL);
    // cr_assert_eq(do_perft(p, 4), 422333ULL);
    // cr_assert_eq(do_perft(p, 5), 15833292ULL);
    // cr_assert_eq(do_perft(p, 6), 706045033ULL);
}


Test(PERFT, pos4b) {
    Position p = Position("r2q1rk1/pP1p2pp/Q4n2/bbp1p3/Np6/1B3NBn/pPPP1PPP/R3K2R b KQ - 0 1 ");
    cr_assert_eq(do_perft(p, 1), 6ULL);
    cr_assert_eq(do_perft(p, 2), 264ULL);
    cr_assert_eq(do_perft(p, 3), 9467ULL);
    // cr_assert_eq(do_perft(p, 4), 422333ULL);
    // cr_assert_eq(do_perft(p, 5), 15833292ULL);
    // cr_assert_eq(do_perft(p, 6), 706045033ULL);
}

Test(PERFT, pos5) {
    Position p = Position("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8");
    cr_assert_eq(do_perft(p, 1), 44ULL);
    cr_assert_eq(do_perft(p, 2), 1486ULL);
    cr_assert_eq(do_perft(p, 3), 62379ULL);
    // cr_assert_eq(do_perft(p, 4), 2103487ULL);
    // cr_assert_eq(do_perft(p, 5), 89941194ULL);
}

Test(PERFT, pos6) {
    Position p =
      Position("r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - - 0 10");
    cr_assert_eq(do_perft(p, 1), 46ULL);
    cr_assert_eq(do_perft(p, 2), 2079ULL);
    // cr_assert_eq(do_perft(p, 3), 89890ULL);
    // cr_assert_eq(do_perft(p, 4), 3894594ULL);
    // cr_assert_eq(do_perft(p, 5), 164075551ULL);
    // cr_assert_eq(do_perft(p, 6), 6923051137ULL);
    // cr_assert_eq(do_perft(p, 7), 287188994746ULL);
    // cr_assert_eq(do_perft(p, 8), 11923589843526ULL);
    // cr_assert_eq(do_perft(p, 9), 490154852788714ULL);
}
