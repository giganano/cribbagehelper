/*
This file is part of the Cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation of extern functions in flush.h
(not duplicated here for brevity)
*/

#include "flush.h"

extern SCOREBUNDLE *findFlush(HAND h) {

	SCOREBUNDLE *sb = setupScoreBundle();

	unsigned short suitsMatch = 1u;
	for (unsigned short i = 1u; i < h.nCards - 1u; i++) {
		suitsMatch &= (*h.cards[i]).suit == (*h.cards[0]).suit;
	}

	if (suitsMatch) {
		suitsMatch &= (*h.cards[h.nCards - 1u]).suit == (*h.cards[0]).suit;
		if (suitsMatch) {
			addScoreCombo(sb, &h, h.nCards);
		} else if (!h.isCrib) {
			addScoreCombo(sb, &h, h.nCards - 1u);
		}
	} else {}

	return sb;

}


extern unsigned short scoreFlush(SCOREBUNDLE sb) {

	return sb.nCombinations > 0 ? sb.nCards[0] : 0u;

}


