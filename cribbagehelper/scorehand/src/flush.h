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
.. c:function:: extern unsigned short flush(HAND h);

	Determine the number of points from a flush or lack thereof in a given hand.
	If the hand in question is a crib, then all five suits must match for a
	five-point flush.
	However, in a regular hand, a four-point flush is earned when the suit of
	the turn card does not match the cards in a player's hand.

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	points : ``unsigned short``
		The number of points in the hand that come from a flush.
*/
extern unsigned short flush(HAND h);

#ifdef __cplupslus
}
#endif /* __cplusplus */

