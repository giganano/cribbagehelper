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


# CC 			:= gcc
# CFLAGS 		:= -fPIC -Wsign-conversion -Wsign-compare
# SOURCES 	:= $(wildcard *.c)
# HEADERS 	:= $(wildcard *.h)
# OBJECTS 	:= $(SOURCES:.c=.o)
# SUBDIRS 	:= $(filter-out __pycache__/, $(wildcard */))

# all: print_message $(OBJECTS) $(SUBDIRS)

# .PHONY: print_message
# print_message:
# 	@ echo Compiling vice/src/toolkit/gaussian/

# %.o: %.c $(HEADERS)
# 	@ $(CC) $(CFLAGS) -c $< -o $@

# .PHONY: $(SUBDIRS)
# $(SUBDIRS):
# 	@ $(MAKE) -C $@

# .PHONY: clean
# clean:
# 	@ echo Cleaning vice/src/toolkit/gaussian/
# 	@ if [ -d "__pycache__" ] ; then \
# 		rm -rf __pycache__ ; \
# 	fi
# 	@ for i in $(OBJECTS) ; do \
# 		rm -f $$i ; \
# 	done
# 	@ for i in $(SUBDIRS) ; do \
# 		$(MAKE) -C $$i clean ; \
# 	done
