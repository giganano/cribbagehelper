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
.. c:function::	extern HAND **subsets(HAND input, unsigned short nCards);

	Obtain all possible combinations of some number of cards from a
	player's hand.

	Parameters
	----------
	input : ``HAND``
		The hand of cards itself.

	Returns
	-------
	combinations : ``HAND **``
		A pointer to all possible distinct combinations of nCards drawn from
		the input hand of cards.
		Index along the first axis to access different cards, and simply
		dereference along the second axis.
		There will be ``choose(input.nCards, nCards)`` unique hands of cards
		stored in this pointer.
		A NULL pointer is returned if ``nCards > input.nCards``.
*/
extern HAND **subsets(HAND input, unsigned short nCards);

/*
.. c:function:: static unsigned long choose(unsigned long a, unsigned long b);

	Compute the mathematical operation of ``a`` "choose" ``b``, according to:

	.. math::

		f(a, b) \equiv \frac{a!}{b!(a - b)!}

	From a set containing ``a`` elements, ``a`` choose ``b`` evaluates to the
	number of unique subsets (i.e., possible combinations) of ``b`` elements.

	Parameters
	----------
	a : ``unsigned long``
		The first operand of the choose operation.
	b : ``unsigned long``
		The second operand of the choose operation.

	Returns
	-------
	result : ``unsigned long``
		The operation :math:`f(a, b)` defined above.
		Returns 0 as a safeguard when a < b or :math:`f` does not evaluate to
		an integer, which should be mathematically impossible without floating
		point arithmetic.
*/
extern unsigned long choose(unsigned long a, unsigned long b);

#ifdef __cplusplus
}
#endif /* __cplusplus */

