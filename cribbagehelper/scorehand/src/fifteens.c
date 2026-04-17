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

