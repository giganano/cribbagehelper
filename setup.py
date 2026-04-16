#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at https://github.com/giganano/cribbagehelper.git

from setuptools import setup, Extension
import os
if os.name != "posix": raise OSError("""\
Sorry, Windows is not supported. We recommend using the Windows Subsystem for \
Linux as a solution.""")

if __name__ == "__main__":
	compilerdirectives = {"embedsignature": True}
	extensions = [
		Extension(
			"cribbagehelper.core.card.card",
			["cribbagehelper/core/card/card.pyx"],
			include_dirs = ["cribbagehelper/core/card/src"]
		),
		Extension(
			"cribbagehelper.core.hand.hand",
			["cribbagehelper/core/hand/hand.pyx",
			"cribbagehelper/core/hand/src/hand.c",
			"cribbagehelper/scorehand/src/fifteens.c",
			"cribbagehelper/scorehand/src/flush.c",
			"cribbagehelper/scorehand/src/knobs.c",
			"cribbagehelper/scorehand/src/pairs.c",
			"cribbagehelper/scorehand/src/runs.c",
			"cribbagehelper/scorehand/src/subsets.c"],
			include_dirs = [
				"cribbagehelper/core/hand/src",
				"cribbagehelper/core/card/src",
				"cribbagehelper/scorehand/src"],
			)
	]
	setup(ext_modules = extensions)
