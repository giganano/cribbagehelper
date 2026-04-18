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

	Determine the number of points in the hand due to heels, which arises
	when a Jack is turned up when the deck is cut and awards two points.

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	sb : ``SCOREBUNDLE *``
		A ``SCOREBUNDLE`` object containing the cut card if it is a Jack.
		Empty bundle otherwise.

		.. seealso:: cribbagehelper/scorehand/src/score.h
*/
extern SCOREBUNDLE *heels(HAND h);

#ifdef __cplupslus
}
#endif /* __cplusplus */

