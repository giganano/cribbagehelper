/*
This file is part of the cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level direcotry
at: https://github.com/giganano/cribbagehelper.git
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef NRANKS
#define NRANKS 13u
#endif /* NRANKS */

#ifndef NSUITS
#define NSUITS 4u
#endif /* NSUITS */

#ifndef DECK52
#define DECK52 NRANKS * NSUITS
#endif /* DECK52 */

const unsigned short RANKS[13u] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const char SUITS[4u] = {'c', 'd', 'h', 's'};

#include "../../card/src/card.h"
#include "../../hand/src/hand.h"

typedef struct deck {

	// unsigned short ranks[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	// char suits[4] = {'c', 'd', 'h', 's'};
	unsigned short *skip;
	unsigned short *order;

} DECK;

extern DECK *setupDeck(void);
extern void freeDeck(DECK *d);
extern void resetDeck(DECK *d);
extern void shuffleDeck(DECK *d);

#ifdef __cplusplus
}
#endif /* __cplusplus */
