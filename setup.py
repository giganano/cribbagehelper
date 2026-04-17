#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at https://github.com/giganano/cribbagehelper.git

from setuptools import setup, Extension
import glob
import json
import os
if os.name != "posix": raise OSError("""\
Sorry, Windows is not supported. We recommend using the Windows Subsystem for \
Linux as a solution.""")

COMPILER_DIRECTIVES = {
	"embedsignature": True,
	"embedsignature.format": "python"
}


class build:

	r"""
	A class providing functions for compiling cribbagehelper.
	"""

	@staticmethod
	def extensions(metadatafile = "extensions.json"):
		r"""
		Create the extensions to compile with Cython.
		The extension names, and the directories where C headers and source
		files can be found are stored in a JSON mapping in extensions.json.
		"""
		extensions = []
		metadata = json.load(open(metadatafile, 'r'))
		for ext in metadata.keys():
			cython_src_file = "%s.pyx" % (ext.replace('.', '/'))
			c_src_files = []
			for item in metadata[ext]["source_directories"]:
				if item.endswith(".c"):
					c_src_files.append(item)
				else:
					c_src_files.extend(glob.glob("%s/*.c" % (item)))
			extensions.append(
				Extension(
					ext,
					[cython_src_file] + c_src_files,
					include_dirs = metadata[ext]["include_directories"]
					)
				)
		return extensions


	@staticmethod
	def packages(path = "./cribbagehelper"):
		r"""
		Determine which directories should be treated as packages based on the
		presence or lack of an __init__.py file.
		"""
		pkgs = []
		for root, dirs, files in os.walk(path):
			if "__init__.py" in files:
				pkgs.append(root[2:].replace('/', '.'))
			else: pass
		return pkgs


if __name__ == "__main__":
	setup(
		ext_modules = build.extensions(),
		packages = build.packages(),
		compiler_directives = COMPILER_DIRECTIVES
		)
