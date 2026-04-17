/*
This file is part of the cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
.. c:type:: CARD

	A playing card from a standard 52-card deck.

	.. c:member:: ``unsigned short rank``

		The rank of the card. 1 for ace, 11 for jack, 12 for queen, and 13
		for king.

	.. c:member:: ``char suit``

		The suit of the card. 'c' for clubs, 'd' for diamonds, 'h' for
		hearts, and 's' for spades.
*/
typedef struct card {

	unsigned short rank;
	char suit;

} CARD;

#ifdef __cplusplus
}
#endif
