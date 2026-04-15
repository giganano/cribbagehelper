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
	unsigned short parentsetSize,
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
	for (unsigned short i = 0u; i < nCards; i++) indices[0][i] = i;
	subsetIndexGenerator(indices, nCards, input.nCards, 1ul);
	for (unsigned long i = 0ul; i < nCombinations; i++) {
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
.. c:function:: static void subsetIndexGenerator(unsigned short **indices,
	unsigned short subsetSize,
	unsigned short parentsetSize,
	unsigned short n);

	Generate all possible integers between zero and some maximum value
	(inclusive).
	These values are used as array indices to generate all possible
	subsets of a given size from larger parent sets of playing cards for
	scoring hands.

	Parameters
	----------
	indices : ``unsigned short **``
		A pointer to the array of indices, with memory allocated and only the
		first row of elements initialized.
		There must be memory allocated for ``choose(parentsetSize, subsetSize)``
		values along the first axis of indexing and ``subsetSize`` along the
		second.
		This first row must be equal to the lowest integers starting from zero
		in ascending order (e.g., 0-1-2-3 for a ``parentsetSize`` value of 3).
		The remaining rows will be populated through recursion.
	subsetSize : ``unsigned short``
		The number of elements in each subset.
	parentsetSize : ``unsigned short``
		The number of elements in the parent set (often all of the cards in a
		player's hand).
	n : ``unsigned short``
		Should always be called with a value of 1.
		Value will be incremented through recursion to track progress through
		the algorithm.

	Upon completion of this routine, all subsequent rows of ``indices`` will
	be populated. For example, the following first row:

	0 1 2

	with a parentsetSize of 5, ``indices`` will become

	0 1 2
	0 1 3
	0 1 4
	0 2 3
	0 2 4
	0 3 4
	1 2 3
	1 2 4
	1 3 4
	2 3 4
*/
static void subsetIndexGenerator(
	unsigned short **indices,
	unsigned short subsetSize,
	unsigned short parentsetSize,
	unsigned long n) {

	/*
	Check if the last entry to ``indices`` was the last possible combination
	of ``subsetSize`` integers.
	This state functions as a base case for this implementation, since the
	recursive implementation should halt.
	*/
	unsigned short last = 1u;
	for (unsigned short i = 0u; i < subsetSize; i++) {
		last &= indices[n - 1ul][i] == parentsetSize - subsetSize + i;
	}
	if (last) return;

	/*
	Copy the previous "row" into the current "row" (i.e., ``indicies[n - 1]``
	into ``indices[n]``).
	*/
	for (unsigned short i = 0u; i < subsetSize; i++) {
		indices[n][i] = indices[n - 1ul][i];
	}

	/*
	Find the latest element of indices[n] that can be incremented by 1 without
	going above ``parentsetSize - 1ul`` or becoming equal to the subsequent
	element of indices[n].
	*/
	unsigned short idx;
	if (indices[n][subsetSize - 1u] < parentsetSize - 1ul) {
		idx = subsetSize - 1u;
	} else {
		idx = subsetSize - 2u;
		while (indices[n][idx] == indices[n][idx + 1] - 1u) idx--;
	}

	/* increment that one by one */
	indices[n][idx]++;

	/*
	If there are subsequent elements, "reset" them to the lowest possible
	values.
	*/
	for (unsigned short i = idx + 1u; i <= subsetSize - 1u; i++) {
		indices[n][i] = indices[n][i - 1] + 1u;
	}

	return subsetIndexGenerator(indices, subsetSize, parentsetSize, n + 1ul);

}


extern unsigned long choose(unsigned long a, unsigned long b) {

	unsigned long numerator = 1ul, denominator = 1ul;
	if (a >= b) {
		while (b > 0) {
			numerator *= a--;
			denominator *= b--;
		}
		return numerator / denominator; /* always divisible bc number theory */
	} else {
		return 0u; /* safeguard */
	}

}

