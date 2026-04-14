/*
This file is part of the Cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation of extern functions in flush.h
(not duplicated here for brevity)
*/

#include "flush.h"

extern unsigned short flush(HAND h) {

	unsigned short suitsMatch = 1u;
	for (unsigned short i = 1u; i < h.nCards - 1u; i++) {
		suitsMatch &= (*h.cards[i]).suit == (*h.cards[0]).suit;
	}
	if (suitsMatch && h.isCrib) {
		return ((*h.cards[h.nCards - 1u]).suit == (*h.cards[0]).suit) * h.nCards;
	} else if (suitsMatch) {
		return h.nCards - 1u + (
			(*h.cards[h.nCards - 1u]).suit == (*h.cards[0]).suit
			);
	} else {
		return 0u;
	}

}


