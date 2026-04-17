# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

from ...card cimport Card, CARD

cdef extern from "./hand.h":
	ctypedef struct HAND:
		CARD **cards
		unsigned short nCards
		unsigned short isCrib

	HAND *setupHand(unsigned short ncards)
	HAND *copyHand(HAND h)
	void freeHand(HAND *h)


