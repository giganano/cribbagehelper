#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

from cribbagehelper import Card, Hand
import pytest

# _RANKS_ = [str(_) for _ in range(2, 11)] + ['a', 'j', 'q', 'k']
# _SUITS_ = ['c', 'd', 'h', 's']

def test_hand_init():
	r"""
	Ensures the Hand.__init__ function sets everything up properly.
	"""
	test = Hand("4c", "4s", "5d", "6h", "6s")
	assert isinstance(test, Hand)
	assert not test.crib
	test.crib = True
	assert test.crib

def test_hand_len():
	r"""
	Ensures the Hand.__init__ function behaves properly.
	"""
	try:
		test = Hand("4c", "4s", "5d", "6h", "6s")
	except:
		pytest.skip("Hand.__init__ failed.")
	assert len(test) == 5

def test_hand_getitem():
	r"""
	Ensures the Hand.__getitem__ function behaves properly.
	"""
	try:
		test = Hand("4c", "4s", "5d", "6h", "6s")
	except:
		pytest.skip("Hand.__init__ failed.")
	for i in range(5): assert isinstance(test[i], Card)
	try:
		test[0] == Card("4c")
	except:
		pytest.skip("Card.__eq__ failed.")
	assert test[0] == Card("4c")
	assert test[1] == Card("4s")
	assert test[2] == Card("5d")
	assert test[3] == Card("6h")
	assert test[4] == Card("6s")

def test_hand_iter():
	r"""
	Ensures the Hand.__iter__ function behaves properly.
	"""
	try:
		test = Hand("4c", "4s", "5d", "6h", "6s")
	except:
		pytest.skip("Hand.__init__ failed.")
	for i in test:
		assert isinstance(i, Card)

def test_hand_setitem():
	try:
		test = Hand("4c", "4s", "5d", "6h", "6s")
	except:
		pytest.skip("Hand.__init__ failed.")
	test[0] = Card("js")
	try:
		test[0] == test[1]
	except:
		pytest.skip("Card.__eq__ failed.")
	assert test[0] == Card("js")
	test[0] = "7d"
	assert test[0] == Card("7d")


