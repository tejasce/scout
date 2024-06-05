#
# Common top level values
#
TOPDIR := $(shell git rev-parse --show-toplevel 2>/dev/null)
ifeq ($(TOPDIR),)
$(error "Not a git repository.")
endif
SHELL := $(shell which bash)

#
# Apply clang-format to new+modified src files.
#
format:
	@git diff -U0 --no-color | $(TOPDIR)buildtools/clang-format-diff.py -p1

help:
	@echo "Build Targets"
	@echo "       format: run 'clang-format' on new+modified files on this branch"
	@echo "         help: show this message"
