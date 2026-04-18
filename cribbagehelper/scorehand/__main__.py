#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

from cribbagehelper import Hand
import argparse
import sys

def parse_input():
	parser = argparse.ArgumentParser(
		prog = "cribbagehelper.scorehand",
		description = "Compute the score of a cribbage hand.",
		epilog = None)

	parser.add_argument("cards", nargs = "+", help = """\
The cards in the hand, separated by spaces. Each card should be specified \
with either its numerical rank or one of the letters 'a', 'j', 'q', or 'k' \
for an Ace, Jack, Queen, or King, respectively (e.g., \"6s\" for the Six of
Spades, \"jh\" for the Jack of Hearts).""")

	parser.add_argument("-c", "--crib", action = "store_true", help = """\
The hand to be scored is the crib, referring to the bonus hand of four cards \
reserved for the dealer.""")

	parser.add_argument("-d", "--dealer", action = "store_true", help = """\
The hand to be scored belongs to the dealer. In this case, an additional two
points are awarded if the cut card is a Jack (often referred to as "heels," \
"nibs," or "knibs").""")

	parser.add_argument("-i", "--extra-info", action = "store_true", help = """\
Prints a breakdown of the sources of all all points earned. Otherwise, only \
the total is printed.""")

	return parser.parse_args()

if __name__ == "__main__":
	args = parse_input()
	h = Hand(*args.cards, crib = args.crib)
	score = h.score(extra_info = args.extra_info, heels = args.dealer)
	if args.extra_info:
		sys.stdout.write("Total points: %d\n" % (score["total"]))
		for key in score.keys():
			if key == "total": continue
			sys.stdout.write(" - From %s: %d\n" % (key.capitalize(),
				int(score[key])))
			if int(score[key]): sys.stdout.write("%s\n" % (str(score[key])))
	else:
		sys.stdout.write("%d\n" % (score))
