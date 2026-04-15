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

/*
.. c:function:: extern unsigned short fifteens(HAND h);

	Count up all the points in the hand from fifteens (i.e., combinations
	of two cards whose point values add up to 15).

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	total : ``unsigned short``
		Two times the number of combinations of cards that add up to fifteen.

	Notes
	-----
	For these purposes, the jack, queen, and king each have a point value of 10
	(e.g., a king and a five add up to 15 as opposed to 18).
*/
extern unsigned short fifteens(HAND h);

#ifdef __cplusplus
}
#endif /* __cplusplus */
