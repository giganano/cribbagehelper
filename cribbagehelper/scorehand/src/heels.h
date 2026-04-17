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
.. c:function:: inline unsigned short heels(HAND h);

	Determine the number of points in the hand due to heels, which arises
	when a Jack is turned up when the deck is cut and awards two points.

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	points : ``unsigned short``
		2 if the final card in the hand (interpreted as the turn card), has a
		rank value of 11. 0 otherwise.
*/
inline unsigned short heels(HAND h) {

	return 2u * ((*h.cards[h.nCards - 1u]).rank == 11u);

}

#ifdef __cplupslus
}
#endif /* __cplusplus */

