# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

from .src cimport HAND, setupHand, freeHand
from ...scorehand cimport scoreHand

cdef class Hand:
	cdef HAND *h

