/*
This file is part of the Cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation of extern functions in pairs.h
(not duplicated here for brevity)
*/

#include <stdlib.h>
#include "pairs.h"
#include "subsets.h"

extern SCOREBUNDLE *findPairs(HAND h) {

	SCOREBUNDLE *sb = setupScoreBundle();
	HAND **twoCardCombos = subsets(h, 2u);
	for (unsigned long i = 0ul; i < choose(h.nCards, 2ul); i++) {
		if ((*(*twoCardCombos[i]).cards[1]).rank ==
			(*(*twoCardCombos[i]).cards[0]).rank) {
			addScoreCombo(sb, twoCardCombos[i], 2u);
		} else {}
		freeHand(twoCardCombos[i]);
	}
	free(twoCardCombos);
	return sb;

}


extern unsigned short scorePairs(SCOREBUNDLE sb) {

	return 2u * sb.nCombinations;

}

