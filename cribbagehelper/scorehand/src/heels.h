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
.. c:function:: extern SCOREBUNDLE *heels(HAND h);

	Identify a Jack in the cut card position, which awards two points to
	the dealer.

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	sb : ``SCOREBUNDLE *``
		A ``SCOREBUNDLE`` object containing the cut card, if it is a Jack.
		Empty bundle otherwise.

		.. seealso:: cribbagehelper/scorehand/src/score.h
*/
extern SCOREBUNDLE *findHeels(HAND h);

/*
.. c:function:: extern unsigned short scoreHeels(SCOREBUNDLE sb);

	Determine the number of points in the hand due to heels.

	Parameters
	----------
	sb : ``SCOREBUNDLE``
		A ``SCOREBUNDLE`` object containing all of the corresponding
		cut card, as returned by ``heels``.

		.. seealso:: cribbagehelper/scorehand/src/score.h

	Returns
	-------
	points : ``unsigned short``
		2u if a Jack is found in the bundle. 0u otherwise.
*/
extern unsigned short scoreHeels(SCOREBUNDLE sb);

#ifdef __cplupslus
}
#endif /* __cplusplus */

