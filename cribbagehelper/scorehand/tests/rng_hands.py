#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE in top-level directory
# at: https://github.com/giganano/cribbagehelper.git
r"""
This file generates some number of randomly drawn hands of cards and saves them
in an output file. cribbagehelper developers have generated one such file and
scored each hand manually. The manually determined and computed scores are then
compared as a test of the backend code.

SYS.ARGV
--------
1) The name of the output file
2) The number of hands to procedurally generate
"""

from cribbagehelper import Card, Hand
import random
import sys
random.seed(a = 0)

RANKS = [str(_) for _ in range(2, 11)] + ['a', 'j', 'q', 'k']
SUITS = ['c', 'd', 'h', 's']


def generate_hand(ncards = 5):
	r"""
	Generate one psuedorandom hand of cards. Make sure that there are no
	duplicate cards.
	"""
	cards = []
	for i in range(ncards):
		while True:
			rank = RANKS[int(len(RANKS) * random.random())]
			suit = SUITS[int(len(SUITS) * random.random())]
			c = Card("%s%s" % (rank, suit))
			if not c in cards:
				cards.append(c)
				break
			else:
				continue
	return Hand(*["%s%s" % (rank_int_to_str(c.rank), c.suit) for c in cards])


def rank_int_to_str(rank):
	r"""
	Turn the integer rank of the card into string form (e.g., 'a' for Ace
	instead of 1).
	"""
	if 2 <= rank <= 10:
		return str(rank)
	else:
		return {
			1: 'a',
			11: 'j',
			12: 'q',
			13: 'k'
		}[rank]


if __name__ == "__main__":
	nhands = int(sys.argv[2])
	with open(sys.argv[1], 'w') as out:
		for i in range(nhands):
			hand = generate_hand()
			for j in range(len(hand)):
				if j: out.write(" ")
				out.write("%s%s" % (
					rank_int_to_str(hand[j].rank), hand[j].suit))
			# out.write("%d\n" % (hand.score()))
			out.write("\n")
		out.close()

