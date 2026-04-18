# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

__all__ = ["Hand"]
from . cimport hand
from .src cimport setupHand, freeHand
from ..card cimport Card, CARD
from ...scorehand.scoreBundle import (ScoreBundleFifteens, ScoreBundleFlush,
	ScoreBundleHeels, ScoreBundleKnobs, ScoreBundlePairs, ScoreBundleRuns)
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

	def __cinit__(self, *args, crib = False):
		ranks = []
		suits = []
		for i, arg in enumerate(args):
			# let the Card object do the error handling
			r, s = Card._rank_and_suit_from_string(arg)
			ranks.append(r)
			suits.append(s)
		self.h = setupHand(<unsigned long> len(ranks))
		for i in range(len(ranks)):
			self.h[0].cards[i][0].rank = <unsigned short> ranks[i]
			self.h[0].cards[i][0].suit = <char> ord(suits[i])

	def __init__(self, *args, crib = False):
		self.crib = crib

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
				cpy = Card("1s")
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

	def __iter__(self):
		for i in range(self.__len__()):
			yield self.__getitem__(i)

	def __setitem__(self, key, value):
		if isinstance(value, Card):
			c = self.__getitem__(key)
			c.rank = value.rank
			c.suit = value.suit
		elif isinstance(value, str):
			value = Card(value)
			c = self.__getitem__(key)
			c.rank = value.rank
			c.suit = value.suit
		else:
			raise TypeError("""\
Item assignment requires a \'Card\' object or a string. Got: %s""" % (
				type(value)))

	@property
	def crib(self):
		r"""
		Type : ``bool``

		``True`` if this hand is a crib, but ``False`` if it is instead a
		player's hand.
		"""
		return bool(self.h[0].isCrib)

	@crib.setter
	def crib(self, value):
		if isinstance(value, bool):
			self.h[0].isCrib = <unsigned short> value
		else:
			raise TypeError("Attribute 'crib' must be of type bool. Got: %s" % (
				type(value)))

	def score(self, heels = False, extra_info = False):
		r"""
		Compute the score of the hand.

		Parameters
		----------
		heels : ``bool`` [default : False]
			Whether or not to take into account "heels," which awards two points
			to the dealer when the cut card is a Jack. As such, this variable
			should be switched to ``True`` when the hand being scored belongs to
			the dealer but remain ``False`` otherwise.

			.. note:: "Heels" is also known as "nibs," or "knibs."

		extra_info : ``bool`` [default : False]
			If ``True``, returns a dictionary detailing how the points were
			earned (see below). If ``False``, only the final total is returned.

		.. todo::

			- Finish docs on this function: describe returned object and write
			  some example code.
		"""
		if not isinstance(heels, bool):
			raise TypeError("\'heels\' must be of type \'bool.\' Got: %s" % (
				type(heels)))
		elif not isinstance(extra_info, bool):
			raise TypeError("\'extra_info\' must be of type \'bool.\' Got: %s" % (
				type(extra_info)))
		else: pass

		breakdown = {
			"fifteens": ScoreBundleFifteens(self),
			"flush": ScoreBundleFlush(self),
			"heels": ScoreBundleHeels(self),
			"knobs": ScoreBundleKnobs(self),
			"pairs": ScoreBundlePairs(self),
			"runs": ScoreBundleRuns(self)
		}
		if heels: breakdown["heels"] = ScoreBundleHeels(self)
		total = sum([int(breakdown[key]) for key in breakdown.keys()])
		if extra_info:
			breakdown["total"] = total
			return breakdown
		else:
			return total
