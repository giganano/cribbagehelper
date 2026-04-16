# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at https://github.com/giganano/cribbagehelper.git

from .src cimport CARD
cdef class Card:
	cdef CARD *c
	cdef unsigned short _copy # if this object is a duplicate made for python purposes
