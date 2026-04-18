/*
This file is part of the cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git

See documentation of extern functions in score.h
(not duplated here for brevity)
*/

#include <stdlib.h>
#include "score.h"


extern SCOREBUNDLE *setupScoreBundle(void) {

	SCOREBUNDLE *sb = (SCOREBUNDLE *) malloc (sizeof(SCOREBUNDLE));
	sb -> nCombinations = 0u;
	sb -> nCards = NULL;
	sb -> cards = NULL;
	return sb;

}


extern void freeScoreBundle(SCOREBUNDLE *sb) {

	if (sb != NULL) {
		if ((*sb).nCombinations && (*sb).cards != NULL) {
			for (unsigned short i = 0u; i < (*sb).nCombinations; i++) {
				if ((*sb).nCards[i] && (*sb).cards[i] != NULL) {
					for (unsigned short j = 0u; j < (*sb).nCards[i]; j++) {
						if ((*sb).cards[i][j] != NULL) {
							free(sb -> cards[i][j]);
						} else {}
					}
					free(sb -> cards[i]);
				} else {}
			}
			free(sb -> cards);
		} else {}
		free(sb);
	} else {}

}


extern void addScoreCombo(SCOREBUNDLE *sb, HAND *combo, unsigned short nCards) {

	sb -> nCombinations++;

	/* Store the number of cards in the bundle */
	sb -> nCards = (unsigned short *) realloc (sb -> nCards,
		(*sb).nCombinations * sizeof(unsigned short));
	sb -> nCards[(*sb).nCombinations - 1u] = nCards;

	/* Store the cards themselves */
	sb -> cards = (CARD ***) realloc (sb -> cards,
		(*sb).nCombinations * sizeof(CARD **));
	sb -> cards[(*sb).nCombinations - 1u] = (CARD **) malloc (
		nCards * sizeof(CARD *));
	for (unsigned short i = 0u; i < nCards; i++) {
		CARD c = *(*combo).cards[i];
		sb -> cards[(*sb).nCombinations - 1u][i] = (CARD *) malloc (sizeof(CARD));
		sb -> cards[(*sb).nCombinations - 1u][i] -> rank = c.rank;
		sb -> cards[(*sb).nCombinations - 1u][i] -> suit = c.suit;
	}

}
