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

#include "../../card/src/card.h"

/*
.. c:type:: ``HAND``

	A hand of playing cards from a standard 52-card deck.

	.. c:member:: ``CARD **cards``

		The cards in the hand.

		.. seealso:: cribbagehelper/core/card/src/card.h

	.. c:member:: ``unsigned short ncards``

		The number of cards in the hand.
*/
typedef struct hand {

	CARD **cards;
	unsigned short ncards;

} HAND;

/*
.. c:function:: extern HAND *handinitialize(unsigned short ncards, unsigned short *ranks, char *suits);

	Allocate memory for and return a pointer to a hand of cards.

	Parameters
	----------
	ncards : ``unsigned short *``
		The number of cards in the hand.
	ranks : ``unsigned short *``
		The ranks of each card. 1 for Ace, 11 for Jack, 12 for Queen, and
		13 for King. Otherwise, the face value of the card. 
	suits : ``char *``
		The suits of each card. 'c' for clubs, 'd' for diamonds, 'h' for
		hearts, and 's' for spades. The order should be a component-wise
		match with ``ranks``.

	Returns
	-------
	h : ``HAND *``
		A pointer to the ``HAND`` object containing the corresponding ``CARD``
		objects.
*/
extern HAND *setup_hand(unsigned short ncards,
	unsigned short *ranks,
	char *suits);

/*
.. c:function:: extern void free_hand(HAND *h);

	Free the memory stored by a ``HAND`` object.

	Parameters
	----------
	h : ``HAND *``
		A pointer to the hand object whose memory is to be freed.
*/
extern void free_hand(HAND *h);

#ifdef __cplusplus
}
#endif
