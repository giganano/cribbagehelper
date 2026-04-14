/*
This file is part of the Cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git
*/

#include <stdlib.h>
#include "runs.h"
#include "subsets.h"

static unsigned short *quicksort(unsigned short *input, unsigned short length);
static unsigned short consecutive(unsigned short *input, unsigned short length);


extern unsigned short runs(HAND h) {

	unsigned short total = 0u;
	unsigned short length = h.nCards;
	while (length >= 3u && total == 0u) {
		HAND **combos = subsets(h, length);
		for (unsigned short i = 0u; i < choose(h.nCards, length); i++) {
			unsigned short *ranks = (unsigned short *) malloc (
				length * sizeof(unsigned short));
			ranks[i] = (*h.cards[i]).rank;
			unsigned short *sorted = quicksort(ranks, length);
			free(ranks);
			if (consecutive(sorted, length)) total += length;
			freeHand(combos[i]);
			free(sorted);
		}
		free(combos);
		length--;
	}
	return total;

}


static unsigned short *quicksort(unsigned short *input, unsigned short length) {

	if (length == 0u) {
		return NULL;
	} else if (length <= 1u) {
		unsigned short *copy = (unsigned short *) malloc (sizeof(unsigned short));
		copy[0] = input[0];
		return copy;
	} else if (length == 2u) {
		unsigned short min = input[0] < input[1] ? input[0] : input[1];
		unsigned short max = input[0] > input[1] ? input[0] : input[1];
		unsigned short *copy = (unsigned short *) malloc (
			2u * sizeof(unsigned short));
		copy[0] = min;
		copy[1] = max;
		return copy;
	} else {
		unsigned short pivot = length / 2u;
		unsigned short nAbove = 0u, nBelow = 0u;
		unsigned short *above = NULL, *below = NULL;
		for (unsigned short i = 0u; i < length; i++) {
			if (input[i] > input[pivot]) {
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
		unsigned short n = 0u;
		unsigned short *sorted = (unsigned short *) malloc (
			length * sizeof(unsigned short));
		for (unsigned short i = 0u; i < nBelow; i++) sorted[n++] = sortedBelow[i];
		for (unsigned short i = 0u; i < nAbove; i++) sorted[n++] = sortedAbove[i];
		if (sortedAbove != NULL) free(sortedAbove);
		if (sortedBelow != NULL) free(sortedBelow);
		return sorted;
	}

}


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


