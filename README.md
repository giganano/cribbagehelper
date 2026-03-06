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

### Intended Usage

Use `python -m cribbagehelper.scorehand` to compute the score of a hand.
The cards in the hand can be specified with a rank, which should be one of the
following: `a 2 3 4 5 6 7 8 9 t j q k`, and a suit, which should be one of the
following: `c d h s`.
The final of the five cards will be interpreted as the turn card, with the
first four being in the dealt hand.
For example:

```
$ python -m cribbagehelper.scorehand 4s 5d 6h 6s qd
14
```

The hand to be scored is a 4 of spades, a 5 of diamonds, a 6 of hearts, and a
6 of spades, with a queen of diamonds turned up from cutting the deck.
This hand is worth 14 points: six through combinations of cards that add up to
15, two runs of three consecutive ranks (4-5-6) worth three points, and a pair
of 6's worth two points.
The 4-5-6-6 combination is often referred to as a "double run."

Use `python -m cribbagehelper.splithand` to identify the best cards to give to
the crib:

```
$ python -m cribbagehelper.splithand 4s 5s 6h 6s as kd [--theirs] [--mine]
```

The format output from this function is to be determined.


### Developers: To-Do

<ul>
	<li>Setup package infrastructure</li>
	<li>Setup command-line API</li>
	<li>Setup basic backend objects</li>
</ul>
