#
# m4/mode.m4
#
# pyc m4 build configuration macros
#
# Copyright (c) 2015-220 F. Aragon. All rights reserved.
# Released under the BSD 3-Clause License (see the doc/LICENSE)
#

# Develoment (debug) / release mode switch

AC_MSG_CHECKING("Build mode selection")

AC_ARG_ENABLE(debug,
	AS_HELP_STRING([--enable-debug], [turn on debug mode [default=no]]),
	 , enable_debug=no)

AC_ARG_ENABLE(profiling,
	AS_HELP_STRING([--enable-profiling], [turn on profiling mode [default=no]]),
	 , enable_profiling=no)

if test "$enable_profiling" = "yes"; then
	CFLAGS="$CFLAGS -fprofile-arcs -ftest-coverage -g -pg"
	LDFLAGS="$LDFLAGS -lgcov -coverage"
fi

if test "$enable_debug" = "yes"; then
	CFLAGS="$CFLAGS -g -O0"
	AC_DEFINE([DEBUG], [], [])
	AC_MSG_RESULT(yes)
else
	CFLAGS="$CFLAGS -O3"
	AC_DEFINE([NDEBUG], [], [])
	AC_MSG_RESULT(no)
fi

AM_CONDITIONAL(DEBUG, test "$enable_debug" = yes)
