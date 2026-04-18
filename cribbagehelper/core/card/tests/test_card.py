#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano0@gmail.com)
# License: MIT License. See LICENSE in top-level directory
# at: https://github.com/giganano/cribbagehelper.git

from cribbagehelper import Card
import pytest

_RANKS_ = ['a'] + [str(_) for _ in list(range(2, 11))] + ['j', 'q', 'k']
_SUITS_ = ['c', 'd', 'h', 's']

def test_card_init():
	r"""
	Ensures the Card.__init__ function can create all 52 cards in a standard
	playing card deck.
	"""
	for i in range(len(_RANKS_)):
		for j in range(len(_SUITS_)):
			test = Card("%s%s" % (_RANKS_[i], _SUITS_[j]))
			assert isinstance(test, Card)
			assert test.rank == i + 1
			assert test.suit == _SUITS_[j]

def test_card_rank_setter():
	r"""
	Ensures that the Card.rank setter function accepts all of the proper
	values.
	"""
	try:
		test = Card("as")
	except:
		pytest.skip("Card.__init__ failed.")
	for i in range(len(_RANKS_)):
		test.rank = _RANKS_[i]
		assert isinstance(test.rank, int)
		assert test.rank == i + 1
		if _RANKS_[i].isdigit():
			test.rank = int(_RANKS_[i])
			assert isinstance(test.rank, int)
			assert test.rank == i + 1

def test_card_rank_subclass():
	r"""
	Ensures that the desired type-cast to string behaves properly for
	card ranks.
	"""
	try:
		test = Card("as")
	except:
		pytest.skip("Card.__init__ failed.")
	assert test.rank == 1
	assert str(test.rank) == 'a'
	try:
		test.rank = 2
	except:
		pytest.skip("Card.rank.setter failed.")
	assert test.rank == 2
	assert str(test.rank) == "Card.Rank(2)"
	try:
		test.rank = 11
	except:
		pytest.skip("Card.rank.setter failed.")
	assert test.rank == 11
	assert str(test.rank) == 'j'
	try:
		test.rank = 12
	except:
		pytest.skip("Card.rank.setter failed.")
	assert test.rank == 12
	assert str(test.rank) == 'q'
	try:
		test.rank = 13
	except:
		pytest.skip("Card.rank.setter failed.")
	assert test.rank == 13
	assert str(test.rank) == 'k'


def test_card_suit_setter():
	r"""
	Ensures that the Card.suit setter function accepts all of the proper
	values.
	"""
	try:
		test = Card("as")
	except:
		pytest.skip("Card.__init__ failed.")
	for i in range(len(_SUITS_)):
		test.suit = _SUITS_[i]
		assert isinstance(test.suit, str)
		assert test.suit == _SUITS_[i]

def test_card_eq():
	r"""
	Ensures that the equivalence test for Cards returns expected results.
	"""
	try:
		c1 = Card("as")
		c2 = Card("as")
	except:
		pytest.skip("Card.__init__ failed")
	assert c1 is not c2
	assert c1 == c2
	try:
		c2.rank = 3
	except:
		pytest.skip("Card.rank.setter failed.")
	assert c1 != c2
	try:
		c2.rank = 'a'
	except:
		pytest.skip("Card.rank.setter failed.")
	assert c1 == c2
	try:
		c2.suit = 'd'
	except:
		pytest.skip("Card.suit.setter failed.")
	assert c1 != c2
	try:
		c2.rank = 3
	except:
		pytest.skip("Card.rank.setter failed.")
	assert c1 != c2
