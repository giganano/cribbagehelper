# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

__all__ = ["Hand"]
from . cimport hand
from ..card cimport Card, CARD
from libc.stdlib cimport malloc, free
from libc.stdio cimport printf

cdef class Hand:

	r"""
	.. class:: cribbagehelper.core.hand(ranks, suits)

		The base class for a hand of cards.

		Parameters
		----------
		ranks : array-like
			The ranks of each card, specified as an integer between 1 and 13: 1
			for Ace, 11 for Jack, 12 for Queen, 13 King, and otherwise the
			numerical value of each card.
		suits : array-like
			The suits of each card: 'c' for clubs, 'd' for diamonds, 'h' for
			hearts, and 's' for spades. Should be a component-wise match to the
			elements of ``ranks``.

		.. todo::

			* Error handling

			* Functions and example code.
	"""

	def __cinit__(self, ranks, suits):
		# TODO: error handling
		self.h = setupHand(<unsigned short> len(ranks))

	def __init__(self, ranks, suits):
		# TODO: error handling
		for i in range(len(ranks)):
			self.h[0].cards[i][0].rank = <unsigned short> ranks[i]
			self.h[0].cards[i][0].suit = <char> ord(suits[i])

	def __dealloc__(self):
		freeHand(self.h)

	def __enter__(self):
		return self

	def __exit__(self, exc_type, exc_value, exc_tb):
		return exc_type is None

	def __len__(self):
		return self.h[0].nCards

	def __repr__(self):
		rep = "<cribbagehelder.hand: "
		for i in range(self.__len__()):
			if i: rep += ", "
			c = self.__getitem__(i)
			rep += "%s of %s" % (c.rank, c.suit)
		rep += ">"
		return rep

	def __getitem__(self, index):
		# TODO: error handling
		return Card(
			self.h[0].cards[index][0].rank,
			chr(self.h[0].cards[index][0].suit))


	def score(self):
		return scoreHand(self.h[0])

