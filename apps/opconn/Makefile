#!/bin/sh
################################################################################
#
# Copyright (c) 2008 Opulan Technologies Corp., All Rights Reserved.
#
# FILENAME: Makefile.conf
#
# DESCRIPTION: Top level Makefile - builds the final image file for a specified module.
#
# Date Created (optional): 4/13/2008
#
# Authors (optional): Gan Zhiheng
#
# Reviewed by (optional):
#
# Edit History:
#
#
################################################################################

TARGET = opconn
TARGETDIR = $(shell /bin/pwd)

# Include common and TARGET specific defines
include $(TARGETDIR)/Makefile.conf

# Define a prefix for this Makefile, so that the common targets 
# (COMMONTARGS defined in Makefile.conf), such as clean, etc. can be 
# made in the subdirectories. Use the name of the current directory
# for COMMONPREFIX.
COMMONPREFIX = top

# Final target. Define at least one rule before commonrules,
# otherwise the first commonrule will be the default.
# Default is to:
#	1) create output directory if not exists. Directory name is the same as TARGET
#	2) build all COMPONENTS
#	3) build image


all: libdir $(COMPONENTS) image

# Rule to create output directory if it does not exists
libdir:
	@if [ -d $(LIBDIR) ]; then \
		echo "Output directory is $(LIBDIR)."; \
	else \
		echo "Output directory $(LIBDIR) does not exists. Creating ..."; \
		mkdir $(LIBDIR); \
	fi

# Rule to make a directory component
$(COMPONENTS): 
	@echo "=== make COMPONENT ./$@"
	@$(MAKE) -rw -C $@

# All the COMPONENTS are nonexistent targets. 
.PHONY: $(COMPONENTS) $(COMMONTARGS)

# Rule to make common targets, such as clean, etc.
# This loop will propogate any of COMMONTARGS to the directories listed in COMPONENTS. COMPONENTS is defined in the Makefile.
# This rule must live in the parent level Makefile, as opposed to the common rules, so that the leaf node make doesn't confuse the
# rules $(COMMONPREFIX)clean with clean, etc.

$(COMMONTARGS):
	@echo "=== COMMONTARGET '$@' ====================================="
	@echo "=== make -w $@		- prints directories as it walks the tree"
	@echo "=== make -w $@ | sort -u	- get unique list"
	@echo "================================================================"
	@for d in $(COMPONENTS); do \
		$(MAKE) -rsk $@ -C $$d; \
	done

include $(TARGETDIR)/make.rules
