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
TODO: documentation for this function.
*/
extern HAND **subsets(HAND input, unsigned short nCards);

/*
.. c:function:: static unsigned long choose(unsigned long a, unsigned long b);

	Compute the mathematical operation of ``a`` "choose" ``b``, according to:

	.. math::

		f(a, b) \equiv \frac{a!}{b!(a - b)!}

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

