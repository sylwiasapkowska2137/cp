#!/usr/bin/env python3

""" Skrypt do obliczania zapytań z pliku wejściowego. """

import sys

lines = sys.stdin.readlines()
last = lines[-1].strip()
first = lines[0].strip()

n, _ = map(int, first.split())
q, S, A, B, L = map(int, last.split())

while q:
    q -= 1
    S = (S * A + B) % (1 << 64)
    u = S % n
    S = (S * A + B) % (1 << 64)
    v = S % n
    S = (S * A + B) % (1 << 64)
    k = S % L

    print(u, v, k)
