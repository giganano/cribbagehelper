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
.. c:function:: extern SCOREBUNDLE *knobs(HAND h);

	Determine the number of points in the nand from knobs, which awards
	one point when a jack matches the suit of the turn card.

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	sb : ``SCOREBUNDLE *``
		A ``SCOREBUNDLE`` object containing the Jack in the hand whose suit
		matches the cut card, if applicable. Empty bundle otherwise.

		.. seealso:: cribbagehelper/scorehand/src/score.h
*/
extern SCOREBUNDLE *knobs(HAND h);

#ifdef __cplupslus
}
#endif /* __cplusplus */

