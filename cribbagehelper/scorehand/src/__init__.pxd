# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

from ...core cimport CARD, HAND

cdef extern from "./score.h":
	ctypedef struct SCOREBUNDLE:
		CARD ***cards
		unsigned short *nCards
		unsigned short nCombinations

	unsigned short scoreHand(HAND h)
	SCOREBUNDLE *setupScoreBundle()
	void freeScoreBundle(SCOREBUNDLE *sb)
	void addScoreBundle(SCOREBUNDLE *sb, HAND *combo, unsigned short nCards)


cdef extern from "./fifteens.h":
	SCOREBUNDLE *findFifteens(HAND h)
	unsigned short scoreFifteens(SCOREBUNDLE sb)


cdef extern from "./flush.h":
	SCOREBUNDLE *findFlush(HAND h)
	unsigned short scoreFlush(SCOREBUNDLE sb)


cdef extern from "./heels.h":
	SCOREBUNDLE *findHeels(HAND h)
	unsigned short scoreHeels(SCOREBUNDLE sb)


cdef extern from "./knobs.h":
	SCOREBUNDLE *findKnobs(HAND h)
	unsigned short scoreKnobs(SCOREBUNDLE sb)


cdef extern from "./pairs.h":
	SCOREBUNDLE *findPairs(HAND h)
	unsigned short scorePairs(SCOREBUNDLE sb)


cdef extern from "./runs.h":
	SCOREBUNDLE *findRuns(HAND h)
	unsigned short scoreRuns(SCOREBUNDLE sb)
