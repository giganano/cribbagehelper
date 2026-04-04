# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at https://github.com/giganano/cribbagehelper.git

__all__ = ["card"]
from . cimport card
from libc.stdlib cimport malloc, free

cdef class card:

	r"""
	.. class:: cribbagehelper.core.card(rank, suit)

		The base class for a single card from a 52-card playing card deck.

		Parameters
		----------
		rank : ``int`` or ``str``
			The rank of the card (e.g., Ace, 8, Jack). The 2 through the 9 should
			be specified as integers. The Ace, Jack, Queen, and King should be
			specified as the single-character string of the first letter in their
			names (i.e., 'a', 'j', 'q', and 'k').
		suit : ``str``
			A single-character string denoting the suit of the card: 'c' for
			clubs, 'd' for diamonds, 'h' for hearts, and 's' for spades.

		.. todo::

			* Error handling.

			* Functions and example code.
	"""

	def __cinit__(self, rank, suit):
		# TODO: error handling
		self.c = <CARD *> malloc (sizeof(CARD))

	def __init__(self, rank, suit):
		self.c[0].rank = <unsigned short> rank
		self.c[0].suit = <char> ord(suit)

	def __dealloc__(self):
		if self.c is not NULL:
			free(self.c)
			self.c = NULL
		else: pass

	def __repr__(self):
		rep = "<cribbagehelper.card: "
		if self.c[0].rank == 1:
			rep += "Ace"
		elif self.c[0].rank > 10:
			rep += '%s' % ({
				11: "Jack",
				12: "Queen",
				13: "King"
				}[self.c[0].rank])
		else:
			rep += str(self.c[0].rank)
		rep += " of %s>" % ({
			'c': "Clubs",
			'd': "Diamonds",
			'h': "Hearts",
			's': "Spades"
			}[chr(self.c[0].suit)])
		return rep


