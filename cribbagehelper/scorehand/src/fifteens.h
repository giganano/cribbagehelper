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

	Count up all the point in the hand from fifteens.

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	total : ``unsigned short``
		Two times the number of combinations of cards that add up to fifteen.
*/
extern unsigned short fifteens(HAND h);

#ifdef __cplusplus
}
#endif /* __cplusplus */
