/*
This file is part of the Cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation of extern functions in knobs.h
(not duplicated here for brevity).
*/

#include "knobs.h"

extern unsigned short knobs(HAND h) {

	for (unsigned short i = 0u; i < h.nCards - 1u; i++) {
		if ((*h.cards[i]).rank == 11 &&
			(*h.cards[i]).suit == (*h.cards[h.nCards - 1u]).suit) {
			return 1u;
		} else {}
	}
	return 0u;

}
