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

	SCOREBUNDLE *setupScoreBundle()
	void freeScoreBundle(SCOREBUNDLE *sb)
	void addScoreBundle(SCOREBUNDLE *sb, HAND *combo, unsigned short nCards)

cdef extern from "./fifteens.h":
	SCOREBUNDLE *fifteens(HAND h)


cdef extern from "./flush.h":
	SCOREBUNDLE *flush(HAND h)


cdef extern from "./heels.h":
	SCOREBUNDLE *heels(HAND h)


cdef extern from "./knobs.h":
	SCOREBUNDLE *knobs(HAND h)


cdef extern from "./pairs.h":
	SCOREBUNDLE *pairs(HAND h)


cdef extern from "./runs.h":
	SCOREBUNDLE *runs(HAND h)
