# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

__all__ = ["Card"]
from . cimport card
from libc.stdlib cimport malloc, free
import numbers

cdef class Card:

	r"""
	.. class:: cribbagehelper.Card(rank, suit)

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

	_RANK_TO_NAME_ = {
		**{1: "ace", 11: "jack", 12: "queen", 13: "king"},
		**dict(zip(range(2, 11), [str(_) for _ in range(2, 11)]))
	}

	_SUIT_NAMES_ = {
		"c": "clubs",
		"d": "diamonds",
		"h": "hearts",
		"s": "spades"
	}

	@staticmethod
	def _rank_and_suit_from_string(identifier):
		r"""
		Determine the rank and suit of a card from its input string.
		"""
		if isinstance(identifier, str):
			rank_msg = """\
Invalid card rank. Must be 2-10 for a numerical card value or 'a', 'j', 'q', \
or 'k' for an ace, jack, queen, or king, respectively. \
Got: %s""" % (identifier[:-1])
			if len(identifier) == 2:
				if identifier[0].isdigit():
					rank = int(identifier[0])
				elif identifier[0].lower() in ['a', 'j', 'q', 'k']:
					rank = {
						'a': 1,
						'j': 11,
						'q': 12,
						'k': 13
					}[identifier[0].lower()]
				else:
					raise ValueError(rank_msg)
			elif len(identifier) == 3:
				if identifier.startswith("10"):
					rank = 10
				else:
					raise ValueError(rank_msg)
			else:
				raise ValueError("""\
Invalid card identifier. Must be 2-10 for a numerical card value or 'a', 'j', \
'q', or 'k' for an ace, jack, queen, or king, respectively. Must be followed \
by 'c', 'd', 'h', or 's' for clubs, diamonds, hearts, or spades, respectively. \
Got: %s""" % (identifier))
		else:
			raise TypeError("Card identifier must be a string. Got: %s" % (
				type(identifier)))
		if identifier[-1].lower() in Card._SUIT_NAMES_.keys():
			suit = identifier[-1].lower()
		else:
			raise ValueError("""\
Invalid card suit. Must be 'c', 'd', 'h', or 's' for clubs, diamonds, hearts \
or spades, respectively. Got: %s""" % (identifier[-1]))
		return [rank, suit]

	def __cinit__(self, identifier):
		self.c = <CARD *> malloc (sizeof(CARD))

	def __init__(self, identifier):
		# let the subroutine do the error handling
		rank, suit = self._rank_and_suit_from_string(identifier)
		self.rank = rank
		self.suit = suit
		self._copy = 0

	def __dealloc__(self):
		if self._copy: return
		if self.c is not NULL:
			free(self.c)
			self.c = NULL
		else: pass

	def __repr__(self):
		return "<cribbagehelper.card: %s of %s>" % (
			self._RANK_TO_NAME_[self.rank].capitalize(),
			self._SUIT_NAMES_[self.suit].capitalize()
			)

	def __eq__(self, Card other):
		return (self.c[0].rank == other.c[0].rank and
			self.c[0].suit == other.c[0].suit)

	@property
	def rank(self):
		r"""
		Type : ``int``

		The rank of the playing card. 1 for Ace, 11 for Jack, 12 for Queen, 13 for
		King, and otherwise the numerical value of the card.
		"""
		return self.c[0].rank

	@rank.setter
	def rank(self, value):
		if isinstance(value, numbers.Number):
			if value % 1 == 0:
				value = int(value)
				if 1 <= value <= 13:
					self.c[0].rank = <unsigned short> value
				else:
					raise ValueError("""\
Card rank outside allowed range. Must be between 1 and 13 (inclusive). \
Got: %d""" % (value))
			else:
				raise ValueError("""\
Card rank must be an integer between 1 and 13 (inclusive). Received a \
floating point number: %.5e""" % (value))
		elif isinstance(value, str):
			if (value in [str(_) for _ in range(2, 11)] or
				value.lower() in ['a', 'j', 'q', 'k']):
				if value.isdigit():
					self.c[0].rank = <unsigned short> int(value)
				else:
					self.c[0].rank = {
						'a': 1,
						'j': 11,
						'q': 12,
						'k': 13
					}[value.lower()]
			else:
				raise ValueError("""\
Could not determine rank from string. Must be either any numerical value \
between 2 and 10, 'a' for 'ace,' 'j' for 'jack,' 'q' for 'queen,' or 'k' for \
'king.' Got: %s""" % (value))
		else:
			raise TypeError("Card rank must be an integer or string. Got: %s" % (
				type(value)))

	@property
	def suit(self):
		r"""
		Type : ``str``

		The suit of the card (i.e., "Clubs", "Diamonds", "Hearts", or
		"Spades")
		"""
		return chr(self.c[0].suit)

	@suit.setter
	def suit(self, value):
		if isinstance(value, str):
			if value in self._SUIT_NAMES_.keys():
				self.c[0].suit = <char> ord(value)
			else:
				raise ValueError("""\
Card suit must be a one-character string: 'c', 'd', 'h', or 's'. \
Got: \"%s\"""" % (value))
		else:
			raise TypeError("""\
Card suit must be a one-character string. Got: %s""" % (type(value)))


