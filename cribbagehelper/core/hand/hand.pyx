# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

__all__ = ["Hand"]
from . cimport hand
from ..card cimport Card, CARD
from libc.stdlib cimport malloc, free
from libc.stdio cimport printf
import numbers

cdef class Hand:

	r"""
	.. class:: cribbagehelper.Hand(ranks, suits)

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
		if (hasattr(ranks, "__getitem__") and hasattr(ranks, "__len__") and
			hasattr(suits, "__getitem__") and hasattr(suits, "__len__")):
			if len(ranks) == len(suits):
				self.h = setupHand(<unsigned short> len(ranks))
			else:
				raise ValueError("""\
Array-length mismatch. Got %d card ranks but %d suits.""" % (
					len(ranks), len(suits)))
		else:
			raise TypeError("""\
Card ranks and suits must both be array-like objects. \
Received for ranks: %s. \
Received for suits: %s.""" % (type(ranks), type(suits)))


	def __init__(self, ranks, suits):
		for i in range(len(ranks)):
			# let the card object do the error handling
			cpy = self.__getitem__(i)
			cpy.rank = ranks[i]
			cpy.suit = suits[i]

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
			rep += "%s of %s" % (
				c._RANK_TO_NAME_[c.rank].capitalize(),
				c._SUIT_NAMES_[c.suit].capitalize())
		rep += ">"
		return rep

	def __getitem__(self, index):
		if isinstance(index, numbers.Number):
			if index % 1 == 0:
				index = int(index)
				if index < -self.__len__() or index >= self.__len__():
					raise IndexError("""\
Index %d out of bounds for hand of %d cards.""" % (index, self.__len__()))
				elif -self.__len__() <= index < 0:
					index += self.__len__()
				cpy = Card(1, 's')
				free(cpy.c)
				cpy.c = self.h[0].cards[index]
				cpy._copy = 1
				return cpy
			else:
				raise IndexError("""\
Index must be an integer. Received a floating point number: %.5e""" % (index))
		else:
			raise IndexError("Index must be an integer. Got: %s" % (
				type(index)))

	def score(self):
		return scoreHand(self.h[0])

