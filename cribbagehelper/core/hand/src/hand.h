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

	A hand of playing cards from a standard 52-card deck, stored in an
	array-like manner.
	Scoring routines in ``cribbagehelper/scorehand/src`` assume that the card
	in the last memory block refers to the turn card from the cut.

	.. c:member:: ``CARD **cards``

		The cards in the hand.

		.. seealso:: cribbagehelper/core/card/src/card.h

	.. c:member:: ``unsigned short nCards``

		The number of cards in the hand.

	.. c:member:: ``unsigned short isCrib``

		1 if this hand is being scored as a Crib. 0 if it is a regular hand.
*/
typedef struct hand {

	CARD **cards;
	unsigned short nCards;
	unsigned short isCrib;

} HAND;

/*
.. c:function:: extern HAND *setupHand(unsigned short ncards);

	Allocate memory for and return a pointer to a hand of cards.
	Does not assign ranks and suits to the constituent cards.

	Parameters
	----------
	ncards : ``unsigned short *``
		The number of cards in the hand.

	Returns
	-------
	h : ``HAND *``
		A pointer to the ``HAND`` object containing the specified number of
		``CARD`` objects.
*/
extern HAND *setupHand(unsigned short nCards);

/*
.. c:function:: extern HAND *copyHand(HAND h);

	Allocate memory for and return a new pointer to a hand of cards with the
	same cards as another hand.

	Parameters
	----------
	h : ``HAND``
		The hand of cards to copy.

	Returns
	-------
	copy : ``HAND *``
		The new hand with the same cards as the input ``h``.
*/
extern HAND *copyHand(HAND h);

/*
.. c:function:: extern void freeHand(HAND *h);

	Free the memory stored by a ``HAND`` object.

	Parameters
	----------
	h : ``HAND *``
		A pointer to the hand object whose memory is to be freed.
*/
extern void freeHand(HAND *h);

#ifdef __cplusplus
}
#endif
