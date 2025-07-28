import numpy as np
import matplotlib.pyplot as plt

# increments to the index in order
# to move a piece in the direction.
# N, E, S, W, NE, SE, SW, NW
deltas = [8, 1, -8, -1, 9, -7, -9, 7]


def gen_rook_moves():
    bitboards = np.zeros(64, dtype=np.uint64)
    for pos in range(64):
        bb = 0
        for i in range(64):
            if i != pos and (i % 8 == pos % 8 or i // 8 == pos // 8):
                bb += 2**i
        bitboards[pos] = bb
    return bitboards


def gen_bishop_moves():
    bitboards = np.zeros(64, dtype=np.uint64)
    for pos in range(64):
        bb = 0
        parity_pos = (pos // 8 + pos % 8) % 2
        for i in range(64):
            parity_i = (i // 8 + i % 8) % 2
            if (
                i != pos
                and (((i - pos) % 9 == 0) or (i - pos) % 7 == 0)
                and (parity_i == parity_pos)
            ):
                bb += 2**i
        bitboards[pos] = bb
    return bitboards

def gen_knight_moves():
    bitboards = np.zeros(64, dtype=np.uint64)
    for pos in range(64):
        bb = 0
        parity_pos = (pos // 8 + pos % 8) % 2
        for delta in (-17, -15, -10, -6, 6, 10, 15, 17):
            i = pos + delta
            parity_i = (i // 8 + i % 8) % 2
            if (0 <= i < 64 and parity_i != parity_pos):
                bb += 2**i
        bitboards[pos] = bb
    return bitboards

def gen_king_moves():
    bitboards = np.zeros(64, dtype=np.uint64)
    for pos in range(64):
        bb = 0
        col = pos % 8
        for delta in (-9, -8, -7, -1, 1, 7, 8, 9):
            i = pos + delta
            col_i = i % 8
            if (0 <= i < 64 and (abs(col_i - col) <= 1)):
                bb += 2**i
        bitboards[pos] = bb
    return bitboards

def main():
    board = np.zeros((8, 8), dtype=int)
    bb_N = gen_king_moves()

    print(bb_N)

    bb = bb_N[10]

    for i in range(64):
        board[i // 8][i % 8] = (bb >> i) & 1

    for i in range(7, -1, -1):
        for j in range(8):
            print(board[i][j], end=" ")
        print()


if __name__ == "__main__":
    main()
