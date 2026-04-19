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
.. c:function:: extern SCOREBUNDLE *flush(HAND h);

	Find a combination of cards of the same suit that would award a flush,
	if present.

	.. seealso::

		The ``scoreFlush`` function for information on how many points a flush
		is worth, depending on whether it is in a player's hand or in the crib.

	Parameters
	----------
	h : ``HAND``
		The hand of cards itself.

	Returns
	-------
	sb : ``SCOREBUNDLE *``
		A ``SCOREBUNDLE`` object containing each card of a matching suit.

		.. seealso:: cribbagehelper/scorehand/src/score.h
*/
extern SCOREBUNDLE *findFlush(HAND h);

/*
.. c:function:: extern unsigned short scoreFlush(SCOREBUNDLE sb);

	Determine the number of points from a flush or lack thereof in a given hand.
	If the hand in question is a crib, then all five suits must match for a
	five-point flush.
	However, in a regular hand, a four-point flush is earned when the suit of
	the turn card does not match the cards in a player's hand.

	Parameters
	----------
	sb : ``SCOREBUNDLE``
		A ``SCOREBUNDLE`` object containing all of the corresponding
		combinations of cards, as returned by ``flush``.

		.. seealso:: cribbagehelper/scorehand/src/score.h

	Returns
	-------
	points : ``unsigned short``
		Either 0, 4, or 5, depending on the above definition of a flush.
*/
extern unsigned short scoreFlush(SCOREBUNDLE sb);

#ifdef __cplupslus
}
#endif /* __cplusplus */

