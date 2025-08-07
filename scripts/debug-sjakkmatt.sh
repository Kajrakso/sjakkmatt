#!/usr/bin/env bash

cur_dir="$(dirname "$0")"

rm -f /tmp/sjakkmatt
tee -a >( ts %.S > /tmp/sjakkmatt-in ) |
  $cur_dir/../sjakkmatt "$@" |
  tee -a >( ts %.S > /tmp/sjakkmatt-out )
sort -k2 -t ' ' --version-sort \
  <( sed -r 's/^/< /' /tmp/sjakkmatt-in ) \
  <( sed -r 's/^/> /' /tmp/sjakkmatt-out ) \
  >/tmp/sjakkmatt
