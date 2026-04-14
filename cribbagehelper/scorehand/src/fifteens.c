/*
This file is part of the cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation of extern functions in fifteens.h
(not duplicated here for brevity)
*/

#include <stdlib.h>
#include "fifteens.h"
#include "subsets.h"

/* Static function comment headers not duplicated here for brevity */
static unsigned short cardCountValue(CARD c);


extern unsigned short fifteens(HAND h) {

	unsigned short total = 0u;
	for (unsigned short n = 2u; n < h.nCards; n++) {
		HAND **combos = subsets(h, n);
		for (unsigned long i = 0ul; i < choose(h.nCards, n); i++) {
			unsigned short *values = (unsigned short *) malloc (
				n * sizeof(unsigned short));
			unsigned short sum = 0u;
			for (unsigned short j = 0u; j < n; j++) {
				sum += cardCountValue(*(*combos[i]).cards[j]);
			}
			if (sum == 15u) total += 2u;
			freeHand(combos[i]);
		}
		free(combos);
	}
	return total;

}

/*
.. c:function: inline unsigned short cardCountValue(CARD c);

	Determine the numerical value that a card carries for the purposes of
	identifying combinations that add up to 15. Jack, Queen, and King each
	count as ten. For example, a King and a 5 count as 15, just like a Ten and
	a 5.

	Parameters
	----------
	c : `CARD`
		The card itself.

	Returns
	-------
	value : `unsigned short`
		The numerical value between 1 and 10.
*/
static unsigned short cardCountValue(CARD c) {

	/* jack, queen, and king each count as 10 when adding to 15 */
	return c.rank > 10 ? 10 : c.rank;

}

#if 0
extern unsigned short fifteens(HAND h) {

	unsigned short total = 0u;
	
	/* the count values of each card */
	unsigned short *values = (unsigned short *) malloc (
		h.ncards * sizeof(unsigned short));
	for (unsigned short i = 0u; i < h.ncards; i++) {
		values[i] = cardCountValue(*h.cards[i]);
	}

	/* two card combos */
	for (unsigned short i = 1u; i < h.ncards; i++) {
		for (unsigned short j = 0u; j < i; j++) {
			if (values[i] + values[j] == 15u) total += 2u;
		}
	}

	/* three card combos */
	for (unsigned short i = 2u; i < h.ncards; i++) {
		for (unsigned short j = 1u; j < i; j++) {
			for (unsigned short k = 0u; k < j; k++) {
				if (values[i] + values[j] + values[k] == 15u) total += 2u;
			}
		}
	}

	/* four card combos */
	for (unsigned short i = 3u; i < h.ncards; i++) {
		for (unsigned short j = 2u; j < i; j++) {
			for (unsigned short k = 1u; k < j; k++) {
				for (unsigned short l = 0u; l < k; l++) {
					if (values[i] + values[j] + values[k] + values[l] == 15u) {
						total += 2u;
					}
				}
			}
		}
	}

	/* all five cards */
	unsigned short sum = 0u;
	for (unsigned short i = 0u; i < h.ncards; i++) sum += values[i];
	if (sum == 15u) total += 2u;

	free(values);
	return total;

}
#endif
