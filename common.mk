# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at https://github.com/giganano/cribbagehelper.git

CYTHON_SOURCES := $(wildcard *.pyx)
CYTHON_OUTPUTS := $(CYTHON_SOURCES:.pyx=.c)
SUBDIRS := $(filter-out __pycache__/ cribbagehelper.egg-info/, $(wildcard */))

.PHONY: clean
clean:
	@ echo Cleaning $(THIS_DIR)

	@ if [ -d "__pycache__" ] ; then \
		rm -rf __pycache__ ; \
	fi
	@ for i in $(CYTHON_OUTPUTS) ; do \
		rm -f $$i ; \
	done
	@ for i in $(SUBDIRS) ; do \
		$(MAKE) -C $$i clean ; \
	done
