/*
This file is part of the cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
.. c:type:: CARD

	A playing card from a standard 52-card deck.

	.. c:member:: ``unsigned short rank``

		The rank of the card. 1 for ace, 11 for jack, 12 for queen, and 13
		for king.

	.. c:member:: ``char suit``

		The suit of the card. 'c' for clubs, 'd' for diamonds, 'h' for
		hearts, and 's' for spades.
*/
typedef struct card {

	unsigned short rank;
	char suit;

} CARD;

/*
.. c:function: inline unsigned short card_count_value(CARD c);

	Determine the numerical value that a card carries for the purposes of
	identifying combinations that add up to 15. Jack, Queen, and King each
	count as ten. For example, a King and a 5 count as 15, just like a Ten and
	a 5.

	Parameters
	----------
	c : `CARD`
		The card itself.

	Returns
	-------
	value : `unsigned short`
		The numerical value between 1 and 10.
*/
inline unsigned short card_count_value(CARD c) {

	/* jack, queen, and king each count as 10 when adding to 15 */
	return c.rank > 10 ? 10 : c.rank;

}

#ifdef __cplusplus
}
#endif
