#!/usr/bin/env bash
rm -f /tmp/stockfish
tee -a >( ts %.S > /tmp/stockfish-in ) |
  stockfish "$@" |
  tee -a >( ts %.S > /tmp/stockfish-out )
sort -k2 -t ' ' --version-sort \
  <( sed -r 's/^/< /' /tmp/stockfish-in ) \
  <( sed -r 's/^/> /' /tmp/stockfish-out ) \
  >/tmp/stockfish
