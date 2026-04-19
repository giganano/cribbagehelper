/*
This file is part of the Cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation of extern functions in heels.h
(not duplicated here for brevity)
*/

#include <stdlib.h>
#include "heels.h"

extern SCOREBUNDLE *heels(HAND h) {

	SCOREBUNDLE *sb = setupScoreBundle();
	HAND *dummy = setupHand(1u);
	dummy -> isCrib = 0u;
	if (!h.isCrib && (*h.cards[h.nCards - 1u]).rank == 11u) {
		dummy -> cards[0] -> rank = 11u;
		dummy -> cards[0] -> suit = (*h.cards[h.nCards - 1u]).suit;
		addScoreCombo(sb, dummy, (*dummy).nCards);
	} else {}
	free(dummy);
	return sb;

}

