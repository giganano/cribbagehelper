# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at https://github.com/giganano/cribbagehelper.git

THIS_DIR = "."
include common.mk

clean: pytestclean
.PHONY: pytestclean
pytestclean:
	@ if [ -d ".pytest_cache" ] ; then \
		rm -rf .pytest_cache ; \
	fi

.PHONY: distclean
distclean:
	@ if [ -d "cribbagehelper.egg-info" ] ; then \
		rm -rf cribbagehelper.egg-info ; \
	fi
	@ if [ -d "build" ] ; then \
		rm -rf build ; \
	fi
