/*
This file is part of the cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level direcotry
at: https://github.com/giganano/cribbagehelper.git
*/

#include <stdlib.h>
#include "deck.h"

static unsigned short sum(unsigned short *arr, unsigned short length);

extern DECK *setupDeck(void) {

	DECK *d = (DECK *) malloc (sizeof(DECK));
	d -> skip = (unsigned short *) malloc (DECK52 * sizeof(unsigned short));
	d -> order = (unsigned short *) malloc (DECK52 * sizeof(unsigned short));
	resetDeck(d);
	return d;

}


extern void freeDeck(DECK *d) {

	if (d != NULL) {
		if ((*d).skip != NULL) free(d -> skip);
		if ((*d).order != NULL) free(d -> order);
		free(d);
	} else {}

}


extern void resetDeck(DECK *d) {

	for (unsigned short i = 0u; i < DECK52; i++) {
		d -> skip[i] = 0u;
		d -> order[i] = i;
	}

}


extern CARD **drawFromDeck(DECK *d, unsigned short nCards) {

	unsigned short nDiscarded = sum((*d).skip, DECK52);
	if (nCards < nDiscarded) {
		CARD **cards = (CARD **) malloc (nCards * sizeof(CARD *));
		for (unsigned short i = 0u; i < nCards; i++) {
			unsigned short idx = 0;
			while (!(*d).skip[idx]) idx++;
			cards[i] = (CARD *) malloc (sizeof(CARD));
			cards[i] -> rank = RANKS[idx % NSUITS];
			cards[i] -> suit = SUITS[idx % NRANKS];
		}
		return cards;
	} else {
		return NULL;
	}

}

static unsigned short sum(unsigned short *arr, unsigned short length) {

	unsigned short sum = 0u;
	for (unsigned short i = 0u; i < length; i++) sum += arr[i];
	return sum;

}


extern void shuffleDeck(DECK *d) {

	/*
	Fisher-Yates shuffle

	High performance, but only provides as many degrees of freedom as the
	number of bits of randomness. The current implementation uses ``rand``,
	which only provides 32 bits of randomness compared to the ~225 needed to
	resolve all 52! possible orders of a deck of cards.
	*/
	for (unsigned short i = 0u; i < DECK52; i++) {
		/* A random index between i and the end of the deck */
		unsigned short j = i + (unsigned) rand() / (RAND_MAX / (DECK52 - i) + 1u);
		unsigned short tmp = (*d).order[i];
		d -> order[i] = (*d).order[j];
		d -> order[j] = tmp;
		tmp = (*d).skip[i];
		d -> skip[i] = (*d).skip[j];
		d -> skip[j] = tmp;
	}

}
