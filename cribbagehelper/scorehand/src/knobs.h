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

	Identify a combination of cards corresponding to Knobs, which arises
	when a Jack in the hand matches the suit of the cut card. The player
	with this hand or crib is awarded one additional point.

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
extern SCOREBUNDLE *findKnobs(HAND h);

/*
.. c:function:: extern unsigned short scoreKnobs(SCOREBUNDLE sb);

	Determine the number of points in the hand from knobs.

	Parameters
	----------
	sb : ``SCOREBUNDLE``
		A ``SCOREBUNDLE`` object containing the corresponding Jack in the
		hand and cut card, if applicable.

		.. seealso:: cribbagehelper/scorehand/src/score.h

	Returns
	-------
	points : ``unsigned short``
		1u if there is a combination of cards found in the bundle.
		0u otherwise.
*/
extern unsigned short scoreKnobs(SCOREBUNDLE sb);

#ifdef __cplupslus
}
#endif /* __cplusplus */

