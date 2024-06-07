#
# Common top level values
#
TOPDIR := $(shell git rev-parse --show-toplevel 2>/dev/null)
ifeq ($(TOPDIR),)
$(error "Not a git repository.")
endif
SHELL := $(shell which bash)
OBJS := $(TOPDIR)/.objs

#
# Include helper makefiles
#
include $(TOPDIR)/buildtools/Makefile.buildenv

#
# Bazel build options
#
BUILD ?= debug
BAZEL_OPTS := --output_user_root=$(OBJS)
BAZEL_CMD := $(BUILDENV_C) bazel $(BAZEL_OPTS)
BAZEL_BUILD_OPTS := --config=$(BUILD)
BAZEL_BUILD_CMD := $(BAZEL_CMD) build $(BAZEL_BUILD_OPTS)

#
# Basic targets to invoke bazel
#
all: startenv
	@$(BAZEL_BUILD_CMD) :all

clean: startenv
	@$(BAZEL_CMD) clean --expunge 2>/dev/null || true

clobber: clean
	@rm -rf $(OBJS) cscope.* tags

#
# Apply clang-format to new+modified src files.
#
format:
	@git diff -U0 --no-color HEAD^ | $(TOPDIR)/buildtools/clang-format-diff.py -p1 -i

tidy:
	@bazel build //... \
	--aspects @bazel_clang_tidy//clang_tidy:clang_tidy.bzl%clang_tidy_aspect \
	--output_groups=report

.DEFAULT_GOAL := all

help:
	@echo "Build Targets"
	@echo "          all: build all $(ARCH) products (default)"
	@echo "        clean: remove all previously built $(ARCH) products"
	@echo "      clobber: cleanall + remove cscope/ctags"
	@echo "       format: run 'clang-format' on new+modified files on this branch"
	@echo "         tidy: run 'clang-tidy' on all cpp files in TOPDIR"
	@echo "         help: show this message"
	@echo
	@$(MAKE) --no-print-directory help.buildenv
	@echo
	@echo "Commmand-line overrides"
	@echo "      DRY_RUN: perform dry-run but do not apply changes"
	@echo "               tgts: format"
