# This file is part of the cribbagehelper package.
# Copyright (C) 2026 James W. Johnson (giganano9@gmail.com)
# License: MIT License. See LICENSE under top-level directory
# at https://github.com/giganano/cribbagehelper.git

CC := gcc
CFLAGS := -fPIC -Wsign-conversion -Wsign-compare
CYTHON_SOURCES := $(wildcard *.pyx)
CYTHON_OUTPUTS := $(CYTHON_SOURCES:.pyx=.c)
SHARED_OBJECTS := $(wildcard *.so)
C_SOURCES := $(filter-out $(CYTHON_OUTPUTS), $(wildcard *.c))
C_OUTPUTS := $(C_SOURCES:.c=.o)
C_HEADERS := $(C_SOURCES:.c=.h)
SUBDIRS := $(filter-out __pycache__/ cribbagehelper.egg-info/, $(wildcard */))

all: print_message $(C_OUTPUTS) $(SUBDIRS)

.PHONY: print_message
print_message:
	@ echo Compiling $(THIS_DIR)

%.o: %.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: tests
tests:
	@ echo Running Unit Tests....
	@ python -m pytest cribbagehelper

.PHONY: clib
clib:
	@ echo Compiling C code in $(THIS_DIR)
	@ for i in $(C_OUTPUTS) ; do \
		$(MAKE) $$i ; \
	done
	@ for i in $(SUBDIRS) ; do \
		$(MAKE) -C $$i clib ; \
	done

.PHONY: $(SUBDIRS)
$(SUBDIRS):
	@ $(MAKE) -C $@

.PHONY: clibclean
clibclean:
	@ echo Cleaning C outputs from $(THIS_DIR)
	@ for i in $(C_OUTPUTS) ; do \
		rm -f $$i ; \
	done
	@ for i in $(SUBDIRS) ; do \
		$(MAKE) -C $$i clibclean ; \
	done

.PHONY: clean
clean:
	@ echo Cleaning $(THIS_DIR)
	@ if [ -d "__pycache__" ] ; then \
		rm -rf __pycache__ ; \
	fi
	@ for i in $(CYTHON_OUTPUTS) ; do \
		rm -f $$i ; \
	done
	@ for i in $(SHARED_OBJECTS) ; do \
		rm -f $$i ; \
	done
	@ for i in $(C_OUTPUTS) ; do \
		rm -f $$i ; \
	done
	@ for i in $(SUBDIRS) ; do \
		$(MAKE) -C $$i clean ; \
	done
