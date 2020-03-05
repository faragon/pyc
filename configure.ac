#
# configure.ac
#
# pyc Autoconf template
#
# Copyright (c) 2015-2020 F. Aragon. All rights reserved.
# Released under the BSD 3-Clause License (see the doc/LICENSE)
#

AC_INIT([pyc], [0.1-master], [https://github.com/faragon/pyc/issues])

PACKAGE_URL="https://github.com/faragon/pyc"
AC_SUBST([PACKAGE_URL])
PACKAGE_FULLNAME="pyc"
AC_SUBST([PACKAGE_FULLNAME])

AC_CONFIG_AUX_DIR([m4/tmp/config-aux])
AC_CONFIG_MACRO_DIR([m4/tmp/config-m4])

CONFIG_ARGS="`echo $ac_configure_args | sed -e \"s% '[[A-Z]]*FLAGS=[[^']]\+'%%g\"`"
AC_SUBST([CONFIG_ARGS])

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

CFLAGS="${CFLAGS:-}"
ori_cf="$CFLAGS"
AC_LANG([C])
AC_PROG_INSTALL
AC_PROG_CC
AC_PROG_LD
AM_PROG_CC_C_O
CFLAGS="$ori_cf"
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

PKG_PROG_PKG_CONFIG

AUTOCONF_ENV="SHELL=/bin/sh"

LT_INIT
AC_ENABLE_STATIC

m4_include([m4/mode.m4])

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	test/Makefile
])

AC_OUTPUT

