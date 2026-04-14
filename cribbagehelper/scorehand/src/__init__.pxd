# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

from ...core cimport HAND

cdef extern from "./fifteens.h":
	unsigned short fifteens(HAND h)


cdef extern from "./flush.h":
	unsigned short flush(HAND h)


cdef extern from "./heels.h":
	unsigned short heels(HAND h)


cdef extern from "./knobs.h":
	unsigned short knobs(HAND h)


cdef extern from "./pairs.h":
	unsigned short pairs(HAND h)


cdef extern from "./runs.h":
	unsigned short runs(HAND h)


cdef extern from "./score.h":
	unsigned short score(HAND h)

