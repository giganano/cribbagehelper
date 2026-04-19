/*
This file is part of the Cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation of extern functions in knobs.h
(not duplicated here for brevity).
*/

#include <stdlib.h>
#include "knobs.h"

extern SCOREBUNDLE *findKnobs(HAND h) {

	SCOREBUNDLE *sb = setupScoreBundle();
	for (unsigned short i = 0u; i < h.nCards - 1u; i++) {
		if ((*h.cards[i]).rank == 11 &&
			(*h.cards[i]).suit == (*h.cards[h.nCards - 1u]).suit) {
			HAND *dummy = setupHand(2u);
			dummy -> isCrib = 0u;
			dummy -> cards[0] -> rank = (*h.cards[i]).rank;
			dummy -> cards[0] -> suit = (*h.cards[i]).suit;
			dummy -> cards[1] -> rank = (*h.cards[h.nCards - 1u]).rank;
			dummy -> cards[1] -> suit = (*h.cards[h.nCards - 1u]).suit;
			addScoreCombo(sb, dummy, 2u);
			free(dummy);
			break;
		} else {}
	}
	return sb;

}


extern unsigned short scoreKnobs(SCOREBUNDLE sb) {

	return sb.nCombinations;

}

