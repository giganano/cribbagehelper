/*
This file is part of the Cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation of extern functions in runs.h
(not duplicated here for brevity)
*/

#include <stdlib.h>
#include <stdio.h>
#include "runs.h"
#include "subsets.h"
#include "score.h"

/* static function comment headers not duplicated here for brevity */
static unsigned short *quicksort(unsigned short *input, unsigned short length);
static unsigned short consecutive(unsigned short *input, unsigned short length);


extern SCOREBUNDLE *findRuns(HAND h) {

	SCOREBUNDLE *sb = setupScoreBundle();
	unsigned short length = h.nCards;
	while (length >= 3u && (*sb).nCombinations == 0u) {
		/*
		Start by looking for long runs, then short ones to not "hallucinate",
		e.g., a run of three that is part of a longer run of four or five.
		Look at all possible combinations of cards from the whole hand down to
		three cards. Sort them from least to greatest, then check if they're
		consecutive and add the points to a running total.
		*/
		HAND **combos = subsets(h, length);
		for (unsigned short i = 0u; i < choose(h.nCards, length); i++) {
			unsigned short *ranks = (unsigned short *) malloc (
				length * sizeof(unsigned short));
			for (unsigned short j = 0u; j < length; j++) {
				ranks[j] = (*(*combos[i]).cards[j]).rank;
			}
			unsigned short *sorted = quicksort(ranks, length);
			free(ranks);
			/*
			By not stopping the loop and checking all possible combinations of
			a given length, double and triple runs are naturally caught.
			*/
			if (consecutive(sorted, length)) {
				addScoreCombo(sb, combos[i], length);
			} else {}
			freeHand(combos[i]);
			free(sorted);
		}
		free(combos);
		length--;
	}
	return sb;

}


extern unsigned short scoreRuns(SCOREBUNDLE sb) {

	unsigned short total = 0u;
	for (unsigned short i = 0u; i < sb.nCombinations; i++) {
		total += sb.nCards[i];
	}
	return total;

}


/*
.. c:function:: static unsigned short quicksort(unsigned short *input, unsigned short length);

	Sort an array of integers from least to greatest.

	Parameters
	----------
	input : ``unsigned short *``
		The array to sort.
	length : ``unsigned short``
		The number of entries in ``input``.

	Returns
	-------
	sorted : ``unsigned short *``
		An array of the same length as input, but sorted least-to-greatest.

	Notes
	-----
	This function implements a simple, commonly found recursive sorting
	algorithm:

		- *Base Case*: occurs when there is only one or no element left in the
		  array.

		- *Recursive Case*: pick the first element of the array as a 'pivot'
		  point. Split the input array into the elements that are less than or
		  equal to the pivot and those that are greater than the pivot.
*/
static unsigned short *quicksort(unsigned short *input, unsigned short length) {

	if (length == 0u || input == NULL) {
		return NULL; /* safeguard base case */
	} else if (length == 1u) {
		unsigned short *copy = (unsigned short *) malloc (sizeof(unsigned short));
		copy[0] = input[0];
		return copy;
	} else {
		unsigned short pivot = input[0];
		unsigned short nAbove = 0u, *above = NULL;
		unsigned short nBelow = 0u, *below = NULL;
		for (unsigned short i = 1u; i < length; i++) {
			if (input[i] > pivot) {
				above = (unsigned short *) realloc (above,
					++nAbove * sizeof(unsigned short));
				above[nAbove - 1u] = input[i];
			} else {
				below = (unsigned short *) realloc (below,
					++nBelow * sizeof(unsigned short));
				below[nBelow - 1u] = input[i];
			}
		}

		unsigned short *sortedAbove = quicksort(above, nAbove);
		unsigned short *sortedBelow = quicksort(below, nBelow);
		if (above != NULL) free(above);
		if (below != NULL) free(below);

		unsigned short n = 0u, *copy = (unsigned short *) malloc (
			length * sizeof(unsigned short));
		for (unsigned short i = 0u; i < nBelow; i++) copy[n++] = sortedBelow[i];
		copy[n++] = pivot;
		for (unsigned short i = 0u; i < nAbove; i++) copy[n++] = sortedAbove[i];
		if (sortedAbove != NULL) free(sortedAbove);
		if (sortedBelow != NULL) free(sortedBelow);
		return copy;
	}

}


/*
.. c:function:: static unsigned short consecutive(unsigned short *input, unsigned short length);

	Determine if an array of integers is consecutive or not.

	Parameters
	----------
	input : ``unsigned short``
		The array of integers itself.
	length : ``unsigned short``
		The number of elements in ``input``.

	Returns
	-------
	cons : ``unsigned short``
		1 if the elements of input are adjacent integers in increasing order
		(e.g., [2, 3, 4], [7, 8, 9, 10]).
		0 otherwise.
*/
static unsigned short consecutive(unsigned short *input, unsigned short length) {

	if (length <= 1) {
		return 1u;
	} else {
		unsigned short result = 1u;
		for (unsigned short i = 1u; i < length; i++) {
			result &= input[i] == input[i - 1] + 1u;
		}
		return result;
	}

}


