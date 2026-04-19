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
.. c:function:: extern SCOREBUNDLE *runs(HAND h);

	Identify the longest possible combinations of cards of consecutive rank,
	starting with a minimum length of three cards (e.g., ace-two-three,
	nine-ten-jack-queen, but not eight-nine).

	Parameters
	----------
	h : ``HAND``
		The hand being scored.

	Returns
	-------
	sb : ``SCOREBUNDLE *``
		A ``SCOREBUNDLE`` object containing each of the runs in the hand,
		determined by finding the longest possible sequences of cards of
		consecutive rank, requiring at least 3 to award points.

		.. seealso:: cribbagehelper/scorehand/src/score.h

	Notes
	-----
	This routine, in combination with cribbagehelper's pair detection
	algorithm, naturally account for so-called "double runs" and "triple runs"
	with duplicate instances of a given rank (e.g., seven-seven-eight-eight-nine).

	.. seealso:: cribbagehelper/scorehand/src/pairs.h
*/
extern SCOREBUNDLE *findRuns(HAND h);

/*
.. c:function:: extern unsigned short scoreRuns(SCOREBUNDLE sb);

	Compute the number of points earned through runs.

	Parameters
	----------
	sb : ``SCOREBUNDLE``
		A ``SCOREBUNDLE`` object containing the combinations of
		conseuctively-ranked cards, as returned by ``runs``.

		.. seealso:: cribbagehelper/scorehand/src/score.h

	Returns
	-------
	points : ``unsigned short``
		The sum total of the length of each run.

	Notes
	-----
	This routine, in combination with cribbagehelper's pair detection
	algorithm, naturally account for so-called "double runs" and "triple runs"
	with duplicate instances of a given rank (e.g., seven-seven-eight-eight-nine).

	.. seealso:: cribbagehelper/scorehand/src/pairs.h
*/
extern unsigned short scoreRuns(SCOREBUNDLE sb);

#ifdef __cplupslus
}
#endif /* __cplusplus */

