/*
This file is part of the cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation in hand.h
*/

#include <stdlib.h>
#include "hand.h"

extern HAND *setupHand(unsigned short nCards) {

	HAND *h = (HAND *) malloc (sizeof(HAND));
	h -> nCards = nCards;
	h -> cards = (CARD **) malloc (nCards * sizeof(CARD *));
	for (unsigned short i = 0u; i < nCards; i++) {
		h -> cards[i] = (CARD *) malloc (sizeof(CARD));
	}
	return h;

}


extern HAND *copyHand(HAND h) {

	HAND *copy = setupHand(h.nCards);
	for (unsigned short i = 0u; i < h.nCards; i++) {
		copy -> cards[i] -> rank = (*h.cards[i]).rank;
		copy -> cards[i] -> suit = (*h.cards[i]).suit;
	}
	return copy;

}


extern void freeHand(HAND *h) {

	if (h != NULL) {
		if ((*h).cards != NULL) {
			for (unsigned short i = 0u; i < (*h).nCards; i++) {
				if ((*h).cards[i] != NULL) free(h -> cards[i]);
			}
			free(h -> cards);
		}
		free(h);
	} else {}

}
