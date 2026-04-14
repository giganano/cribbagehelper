/*
This file is part of the Cribbagehelper package.
Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
License: MIT License. See LICENSE under top-level directory
at: https://github.com/giganano/cribbagehelper.git
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../../core/card/src/card.h"
#include "../../core/hand/src/hand.h"

/*
TODO: documentation for this function.
*/
inline unsigned short heels(HAND h) {

	return 2u * ((*h.cards[h.nCards - 1u]).rank == 11u);

}

#ifdef __cplupslus
}
#endif /* __cplusplus */

