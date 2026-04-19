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
#include "score.h"

/*
.. c:function:: extern SCOREBUNDLE *fifteens(HAND h);

	Find all combinations of cards in a given hand that add up to a
	value of fifteen, each of which awards two points.

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	sb : ``SCOREBUNDLE *``
		A ``SCOREBUNDLE`` object containing each combination of cards whose
		values add up to 15.

		.. seealso:: cribbagehelper/scorehand/src/score.h

	Notes
	-----
	For these purposes, the jack, queen, and king each have a point value of 10
	(e.g., a king and a five add up to 15 as opposed to 18).
*/
extern SCOREBUNDLE *findFifteens(HAND h);

/*
.. c:function:: extern unsigned short scoreFifteens(SCOREBUNDLE sb);

	Count up all the points in the hand from fifteens (i.e., combinations
	of two cards whose point values add up to 15).

	Parameters
	----------
	sb : ``SCOREBUNDLE``
		A ``SCOREBUNDLE`` object containing all of the corresponding
		combinations of cards, as returned by ``fifteens``.

		.. seealso:: cribbagehelper/scorehand/src/score.h

	Returns
	-------
	points : ``unsigned short``
		The number of combinations of cards in the ``SCOREBUNDLE`` times two.
*/
extern unsigned short scoreFifteens(SCOREBUNDLE sb);

#ifdef __cplusplus
}
#endif /* __cplusplus */
