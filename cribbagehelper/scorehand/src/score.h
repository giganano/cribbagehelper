/*
This file is part of the cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../../core/card/src/card.h"
#include "../../core/hand/src/hand.h"

/* The maximum possible score of a 5-card hand */
#ifndef MAXIMUM_POSSIBLE_SCORE_5CARDS
#define MAXIMUM_POSSIBLE_SCORE_5CARDS 30u
#endif /* MAXIMUM_POSSIBLE_SCORE_5CARDS */


/*
.. c:function:: extern unsigned short scoreHand(HAND h);

	Compute the total number of points in a given cribbage hand.

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	points : ``unsigned short``
		The total number of points, arising from fifteens, flushes,
		heels, knobs, pairs, and runs.

	.. seealso::

		In the cribbagehelper/scorehand/src directory:

			- fifteens.h
			- flush.h
			- heels.h
			- knobs.h
			- pairs.h
			- runs.h
			- subsets.h
*/
extern unsigned short scoreHand(HAND h);

/*
.. c:type:: ``SCOREBUNDLE``

	Stores the combinations of cards that earn points under some scoring
	opportunitiy (e.g., fifteens, runs, pairs).

	.. c:member:: ``CARD ***cards``

		The cards that earn points in each scoring combination. Index along
		the first axis based on the scoring opportunity, from 0 to
		``nCombinations``. Index along the second axis based on the individual
		cards part of that scoring opportunity, from 0 to ``nCards[i]``.
		After indexing twice, a single card is stored by the remaining pointer
		on the third axis.

	.. c:member:: ``unsigned short *nCards``

		The number of cards in each scoring opportunity. ``nCards[i]``
		corresponds to the length of ``indices[i]``.

	.. c:member:: ``unsigned short nCombinations``

		the number of combinations of cards that earned points under this
		scoring opportunity. This variable corresponds to the length of
		``indices``.
*/
typedef struct scoreBundle {

	CARD ***cards;
	unsigned short *nCards;
	unsigned short nCombinations;

} SCOREBUNDLE;

/*
.. c:function:: extern SCOREBUNDLE *setupScoreBundle(void);

	Allocate memory for and return a pointer to a ``SCOREBUNDLE`` object.
	Sets the attributes ``cards`` and ``nCards`` to ``NULL`` with
	``nCombinations = 0``.
*/
extern SCOREBUNDLE *setupScoreBundle(void);

/*
.. c:function:: extern void freeScoreBundle(SCOREBUNDLE *sb);

	Free up the memory stored in a ``SCOREBUNDLE`` object.

	Parameters
	----------
	sb : ``SCOREBUNDLE``
		The object to be deconstructed.
*/
extern void freeScoreBundle(SCOREBUNDLE *sb);

/*
.. c:function:: extern void addScorecombo(SCOREBUNDLE *sb, HAND *combo, unsigned short nCards);

	Add a new combination of cards to a given ``SCOREBUNDLE``.

	Parameters
	----------
	sb : ``SCOREBUNDLE *``
		The ``SCOREBUNDLE`` itself, to be extended to contain one more
		combination of cards than when this function is called.
	combo : ``HAND *``
		A ``HAND`` object containing the cards to be added to the
		``SCOREBUNDLE``.
	nCards : ``unsigned short``
		The number of ``CARD``s to take from ``combo``, starting with index
		``0``.
*/
extern void addScoreCombo(SCOREBUNDLE *sb, HAND *combo, unsigned short nCards);

#ifdef __cplusplus
}
#endif /* __cplusplus */

