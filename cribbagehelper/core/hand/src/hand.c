/*
This file is part of the cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation in hand.h
*/

#include <stdlib.h>
#include "hand.h"

extern HAND *setup_hand(unsigned short ncards,
	unsigned short *ranks,
	char *suits) {

	HAND *h = (HAND *) malloc (sizeof(HAND));
	h -> ncards = ncards;
	h -> cards = (CARD **) malloc (ncards * sizeof(CARD *));
	for (unsigned short i = 0u; i < ncards; i++) {
		h -> cards[i] = (CARD *) malloc (sizeof(CARD));
		h -> cards[i] -> rank = ranks[i];
	}
	return h;

}

extern void free_hand(HAND *h) {

	if (h != NULL) {
		if ((*h).cards != NULL) {
			for (unsigned short i = 0u; i < (*h).ncards; i++) {
				if ((*h).cards[i] != NULL) free(h -> cards[i]);
			}
			free(h -> cards);
		}
		free(h);
	} else {}

}
