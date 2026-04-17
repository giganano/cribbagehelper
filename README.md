<!--
	This file is part of the cribagehelper package.
	Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
	License: MIT License. See LICENSE under top-level directory
	at: https://github.com/giganano/cribage-helper.git
-->


# Cribbage Helper

`cribbage-helper` is a python package designed to compute and recommend
statistically good choices to make in cribbage, a card game played with a
standard 52-card deck.
The source code is under development.

### Scoring Cribbage Hands

use `python -m cribbagehelper.scorehand` to compute the score of a hand.
The cards in the hand are specified with a rank, which should be one of
the following:

	- a numerical value between 2 and 10 for numbered cards
	- 'a' for an Ace
	- 'j' for a Jack
	- 'q' for a Queen
	- 'k' for a King

and a suit, which should be one of the following

	- 'c' for Clubs
	- 'd' for Diamonds
	- 'h' for Hearts
	- 's' for Spades

Simply place the cards after the call to `scorehand`:

```
$ python -m cribbagehelper.scorehand 4s 4h 5d 6c 6d
24
```

The final card specified is assumed to be the cut card.
Otherwise, the order of the preceding cards is of no consequence.

A breakdown of the score can be printed with `-i` or `--extra-info`:

```
$ python -m cribbagehelper.scorehand js 5c 5d 5h 5s --extra-info
Total points: 29
 - from fifteens: 16
 - from flush: 0
 - from knobs: 1
 - from pairs: 12
 - from runs: 0
```

Additional flags:

	- `-c`, `--crib`: Specifies that the hand being scored is a crib (i.e., the
		bonus hand of four cards reserved for the dealer).
	- `-d`, `--dealer`: Specifies that the hand being scored belongs to the
		dealer. An additional two points is awarded to the dealer when the cut
		card is a Jack.

### Forecast

**Under Development**

For a given hand of four cards, determine the score of all possible outcomes
associated with all 48 possible cut cards.

```
$ python -m cribbagehelper.forecast 10c 10d 5h 5d
```

The output will convey, in some undetermined format, the best, worst, and
range of likely outcomes.

### Recommend a choice in splitting a player's hand

**Under Development**

For a given hand of five or six cards, determine the statistically best
choice of cards to discard to the crib.

```
$ python -m cribbagehelper.splithand 4c 5d 5s 6h qs jh --mycrib
```

For such a hand, the recommendation should clearly be to put the Jack and
Queen in your own crib and keep the high point value double run intact.
This function will reach that conclusion using a probabilistic, programmatic
approach.

### Developers: To-Do

<ul>
	<li>Setup Documentation</li>
	<li>Setup CI Testing</li>
</ul>
