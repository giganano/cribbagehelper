/*
This file is part of the Cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git
*/

#include <stdlib.h>
#include "pairs.h"
#include "subsets.h"

extern unsigned short pairs(HAND h) {

	unsigned short total = 0u;
	HAND **twoCardCombos = subsets(h, 2u);
	for (unsigned long i = 0ul; i < choose(h.nCards, 2ul); i++) {
		total += 2u * (
			(*(*twoCardCombos[i]).cards[1]).rank ==
			(*(*twoCardCombos[i]).cards[0]).rank
			);
		freeHand(twoCardCombos[i]);
	}
	free(twoCardCombos);
	return total;

}

