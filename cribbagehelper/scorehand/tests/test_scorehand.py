#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE in top-level directory
# at: https://github.com/giganano/cribbagehelper.git

from cribbagehelper import Hand
import os

def test_scorehand():
	r"""
	Test cribbagehelper.Hand.score() for accuracy by running the
	function on the randomly generated hands in ``test_hands.out``
	and checking for any mismatches with ``test_scores.txt``.
	"""
	path = os.path.dirname(os.path.abspath(__file__))
	with open("%s/test_hands.out" % (path), 'r') as hands:
		with open("%s/test_scores.txt" % (path), 'r') as scores:
			while True:
				line = hands.readline()
				if line != "": break
				line = line.split()
				h = Hand(*line)
				score = int(score.readline())
				assert h.score(heels = True) == score
			scores.close()
		hands.close()
