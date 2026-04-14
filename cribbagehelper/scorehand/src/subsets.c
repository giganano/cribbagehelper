/*
This file is part of the cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation of extern functions in subsets.h
(not duplicated here for brevity)
*/

#include <stdlib.h>
#include "subsets.h"

/* Static function comment headers not duplicated here for brevity */
static void subsetIndexGenerator(
	unsigned short **indices,
	unsigned short subsetSize,
	unsigned short maximum,
	unsigned long n);


extern HAND **subsets(HAND input, unsigned short nCards) {

	if (nCards > input.nCards) return NULL;
	unsigned long nCombinations = choose(input.nCards, nCards);
	HAND **combinations = (HAND **) malloc (nCombinations * sizeof(HAND *));
	unsigned short **indices = (unsigned short **) malloc (nCombinations *
		sizeof(unsigned short *));
	for (unsigned long i = 0ul; i < nCombinations; i++) {
		indices[i] = (unsigned short *) malloc (nCards * sizeof(unsigned short));
	}
	for (unsigned short i = 0u; i < nCards; i++) {
		indices[0][i] = i;
	}
	subsetIndexGenerator(indices, nCards, input.nCards - 1u, 1ul);
	for (unsigned long i = 0ul; i < nCombinations; i++) {
		// unsigned short *ranks = (unsigned short *) malloc (
		// 	nCards * sizeof(unsigned short));
		// char *suits = (char *) malloc (nCards * sizeof(char));
		// for (unsigned short j = 0ul; j < nCards; j++) {
		// 	ranks[j] = (*input.cards[indices[i][j]]).rank;
		// 	suits[j] = (*input.cards[indices[i][j]]).suit;
		// }
		// combinations[i] = setupHand(nCards, ranks, suits);
		// free(ranks);
		// free(suits);
		combinations[i] = setupHand(nCards);
		for (unsigned short j = 0u; j < nCards; j++) {
			combinations[i] -> cards[j] -> rank = (*input.cards[indices[i][j]]).rank;
			combinations[i] -> cards[j] -> suit = (*input.cards[indices[i][j]]).suit;
		}
	}
	free(indices);
	return combinations;

}


/*
TODO: docs for this function. recursive approach.
*/
static void subsetIndexGenerator(
	unsigned short **indices,
	unsigned short subsetSize,
	unsigned short maximum,
	unsigned long n) {

	/*
	Check if the last entry to ``indices`` was the last possible combination
	of ``subsetSize`` integers.
	*/
	unsigned short last = 1u;
	for (unsigned short i = 0u; i < subsetSize; i++) {
		last &= indices[n - 1ul][i] == maximum - subsetSize + i + 1ul;
	}
	if (last) return;

	/*
	Copy over the last iteration
	*/
	for (unsigned short i = 0u; i < subsetSize; i++) {
		indices[n][i] = indices[n - 1ul][i];
	}

	/*
	Find the latest element of indices[n] that can be incremented by 1 without
	going above ``maximum`` or becoming equal to the subsequent element of
	indices[n].
	*/
	unsigned short idx;
	if (indices[n][subsetSize - 1u] < maximum) {
		idx = subsetSize - 1u;
	} else {
		idx = subsetSize - 2u;
		while (indices[n][idx] == indices[n][idx + 1] - 1u) idx--;
	}

	/* increment it by one */
	indices[n][idx]++;

	/*
	If there are subsequent elements, "reset" them to the lowest possible
	values.
	*/
	for (unsigned short i = idx + 1u; i <= subsetSize - 1u; i++) {
		indices[n][i] = indices[n][i - 1] + 1u;
	}

	return subsetIndexGenerator(indices, subsetSize, maximum, n + 1ul);

}


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
		Returns 0 as a safeguard when a < b.
*/
extern unsigned long choose(unsigned long a, unsigned long b) {

	unsigned long numerator = 1ul, denominator = 1ul;
	if (a >= b) {
		while (b > 0) {
			numerator *= a--;
			denominator *= b--;
		}
		return numerator / denominator; /* should always be divisible */
	} else {
		return 0u; /* should never happen */
	}

}

