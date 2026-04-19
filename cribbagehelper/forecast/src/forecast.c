/*
This file is part of the cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level direcotry
at: https://github.com/giganano/cribbagehelper.git
*/

#include <stdlib.h>
#include "forecast.h"
#include "../../scorehand/src/score.h"


extern unsigned short *simpleForecast(HAND base) {

	unsigned short *scoreDistribution = (unsigned short *) malloc (
		MAXIMUM_POSSIBLE_SCORE_5CARDS * sizeof(unsigned short));
	for (unsigned short i = 0u; i < MAXIMUM_POSSIBLE_SCORE_5CARDS; i++) {
		scoreDistribution[i] = 0u;
	}

	HAND *h = setupHand(base.nCards + 1u);
	for (unsigned short i = 0u; i < base.nCards; i++) {
		h -> cards[i] -> rank = (*base.cards[i]).rank;
		h -> cards[i] -> suit = (*base.cards[i]).suit;
	}

	for (unsigned short i = 0u; i < NRANKS; i++) {
		for (unsigned short j = 0u; j < NSUITS; j++) {
			for (unsigned short k = 0u; k < base.nCards; k++) {
				if (RANKS[i] == (*base.cards[k]).rank &&
					SUITS[j] == (*base.cards[k]).suit) {
					continue;
				} else {}
			}
			h -> cards[(*h).nCards] -> rank = RANKS[i];
			h -> cards[(*h).nCards] -> suit = SUITS[j];
			scoreDistribution[scoreHand(*h)]++;
		}
	}
	free(h);
	return scoreDistribution;

}
