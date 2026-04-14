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
.. c:function:: extern unsigned short runs(HAND h);

	Compute the number of points in the hand from runs, referring to three
	cards or more of consecutive rank (e.g., ace-two-three, nine-ten-Jack).

	Parameters
	----------
	h : ``HAND``
		The hand being scored.

	Returns
	-------
	points : ``unsigned short``
		The number of points in the hand from runs alone.
		This function naturally catches double runs, with the additional
		points from pairs being handled in ``pairs.h``.
*/
extern unsigned short runs(HAND h);

#ifdef __cplupslus
}
#endif /* __cplusplus */


