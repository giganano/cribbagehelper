/*
This file is part of the Cribbagehelper package.
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
.. c:function:: extern SCOREBUNDLE *pairs(HAND h);

	Determine the number of points earned through pairs of cards of
	equal rank (e.g., two jacks, three queens).

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	sb : ``SCOREBUNDLE *``
		A ``SCOREBUNDLE`` object containing each unique pair of cards of a
		matching rank. If none are present, the bundle will be empty.

		.. seealso:: cribbagehelper/scorehand/src/score.h

	Notes
	-----
	As a consequence of how cribbage scores pairs, three of a kind (e.g.,
	three 5's) counts as six points, since there are three unique subsets of
	two pairs from the parent set of three cards. Similarly, four of a kind
	awards twelve points; there are six unique pairs of two cards that can be
	selected from the parent set of four.

	This routine, in combination with cribbagehelper's run detection algorithm,
	naturally account for "double runs" and "triple runs" with duplicate instances
	of a given rank in one hand (e.g., four-four-five-six).

	.. seealso:: cribbagehelper/scorehand/src/runs.h
*/
extern SCOREBUNDLE *pairs(HAND h);

#ifdef __cplupslus
}
#endif /* __cplusplus */



