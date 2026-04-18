# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

__all__ = ["ScoreBundle", "ScoreBundleFifteens", "ScoreBundleFlush",
	"ScoreBundleHeels", "ScoreBundleKnobs", "ScoreBundlePairs",
	"ScoreBundleRuns"]

from . cimport scoreBundle
from .src cimport fifteens, flush, heels, knobs, pairs, runs
from ..core.card cimport Card
from ..core.hand cimport Hand

cdef class ScoreBundle:

	r"""
	.. class: cribbagehelper.scorehand.ScoreBundle()

		.. todo::

			Docs on this class and its derived classes.

		.. warning::

			Users should not directly access this class.
	"""

	def __cinit__(self):
		self.sb = NULL

	def __dealloc__(self):
		freeScoreBundle(self.sb)

	def __repr__(self):
		if self.sb[0].nCombinations:
			rep = ""
			for i in range(self.sb[0].nCombinations):
				rep += "    (%d) " % (i + 1)
				for j in range(self.sb[0].nCards[i]):
					if (j and self.sb[0].nCards[i] > 2): rep += ","
					if j > 0 and j == self.sb[0].nCards[i] - 1: rep += " and the"
					r = Card._RANK_TO_NAME_[self.sb[0].cards[i][j][0].rank]
					s = Card._SUIT_NAMES_[chr(self.sb[0].cards[i][j][0].suit)]
					rep += " %s of %s" % (r.capitalize(), s.capitalize())
				if i < self.sb[0].nCombinations - 1: rep += "\n"
			return rep
		else:
			return ""

	def __int__(self):
		return 0


cdef class ScoreBundleFifteens(ScoreBundle):

	def __cinit__(self, Hand hand):
		self.sb = fifteens(hand.h[0])

	def __int__(self):
		return 2 * self.sb[0].nCombinations


cdef class ScoreBundleFlush(ScoreBundle):

	def __cinit__(self, Hand hand):
		self.sb = flush(hand.h[0])

	def __int__(self):
		if self.sb[0].nCombinations == 1:
			return self.sb[0].nCards[0]
		elif self.sb[0].nCombinations == 0:
			return 0
		else:
			raise SystemError("Internal Error: >1 flush combination returned.")


cdef class ScoreBundleHeels(ScoreBundle):

	def __cinit__(self, Hand hand):
		self.sb = heels(hand.h[0])

	def __int__(self):
		if self.sb[0].nCombinations <= 1:
			return 2 * self.sb[0].nCombinations
		else:
			raise SystemError("Internal Error: >1 heels combination returned.")


cdef class ScoreBundleKnobs(ScoreBundle):

	def __cinit__(self, Hand hand):
		self.sb = knobs(hand.h[0])

	def __int__(self):
		if self.sb[0].nCombinations <= 1:
			return self.sb[0].nCombinations
		else:
			raise SystemError("Internal Error: >1 knobs combination returned.")


cdef class ScoreBundlePairs(ScoreBundle):

	def __cinit__(self, Hand hand):
		self.sb = pairs(hand.h[0])

	def __int__(self):
		return 2 * self.sb[0].nCombinations


cdef class ScoreBundleRuns(ScoreBundle):

	def __cinit__(self, Hand hand):
		self.sb = runs(hand.h[0])

	def __int__(self):
		total = 0
		for i in range(self.sb[0].nCombinations):
			total += self.sb[0].nCards[i]
		return total
