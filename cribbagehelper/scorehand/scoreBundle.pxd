# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at: https://github.com/giganano/cribbagehelper.git

from ..core.card cimport Card, CARD
from ..core.hand cimport Hand, HAND
from .src cimport (SCOREBUNDLE, setupScoreBundle, freeScoreBundle,
	addScoreBundle)

cdef class ScoreBundle:
	cdef SCOREBUNDLE *sb

cdef class ScoreBundleFifteens(ScoreBundle):
	pass

cdef class ScoreBundleFlush(ScoreBundle):
	pass

cdef class ScoreBundleHeels(ScoreBundle):
	pass

cdef class ScoreBundleKnobs(ScoreBundle):
	pass

cdef class ScoreBundlePairs(ScoreBundle):
	pass

cdef class ScoreBundleRuns(ScoreBundle):
	pass
