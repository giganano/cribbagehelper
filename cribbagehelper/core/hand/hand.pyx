# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

from . cimport hand
from ..card cimport card, CARD
from libc.stdlib cimport malloc, free

cdef class hand:

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
		n = len(ranks)
		cdef unsigned short *_ranks = <unsigned short *> malloc (n * sizeof(
			unsigned short))
		cdef char *_suits = <char *> malloc (n * sizeof(char))
		for i in range(n):
			_ranks[i] = ranks[i]
			_suits[i] = suits[i]
		try:
			self.h = setup_hand(<unsigned short> n, _ranks, _suits)
		finally:
			free(_ranks)
			free(_suits)

	def __init__(self, ranks, suits):
		pass

	def __dealloc__(self):
		free_hand(self.h)

	def __enter__(self):
		return self

	def __exit__(self, exc_type, exc_value, exc_tb):
		return exc_type is None

	def __len__(self):
		return self.h[0].ncards

	def __repr__(self):
		rep = "<cribbagehelder.hand: "
		for i in range(self.__len__()):
			if i: rep += ", "
			c = self.__getitem__(i)
			rep += "%s of %s" % (
				c.__repr__().split()[-2],
				c.__repr__().split()[-1][:-1])
		rep += ">"
		return rep

	def __getitem__(self, index):
		cdef void *ptr = <void *> self.h[0].cards[index]
		c = card(1, 's')
		free(c.c)
		c.c = <CARD *> ptr
		# self.h[0].cards[index]
		return c







