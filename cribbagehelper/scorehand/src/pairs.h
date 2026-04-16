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

/*
.. c:function:: extern unsigned short pairs(HAND h);

	Determine the number of points earned through pairs of cards of
	equal rank (e.g., two jacks, three queens).

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	points : ``unsigned short``
		2 for every pair of two cards of matching rank.
		As a consequence, three of a kind (e.g., three 5's) counts as six
		points, since there are three unique subsets of two pairs from a parent
		set of three cards. Similarly, four of a king awards twelve points because
		there are six unique pairs of two cards that can be selected from a parent
		set of four cards.

	Notes
	-----
	This routine, in combination with cribbagehelper's run detection algorithm,
	naturally account for "double runs" and "triple runs" with duplicate instances
	of a given rank in one hand (e.g., four-four-five-six).

	.. seealso:: cribbagehelper/scorehand/src/runs.h
*/
extern unsigned short pairs(HAND h);

#ifdef __cplupslus
}
#endif /* __cplusplus */



