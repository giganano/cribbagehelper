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
#include "fifteens.h"
#include "flush.h"
#include "heels.h"
#include "knobs.h"
#include "pairs.h"
#include "runs.h"

/*
.. c:function:: inline unsigned short scoreHand(HAND h);

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
inline unsigned short scoreHand(HAND h) {

	return fifteens(h) + flush(h) + heels(h) + knobs(h) + pairs(h) + runs(h);

}

#ifdef __cplusplus
}
#endif /* __cplusplus */

