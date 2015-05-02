# Automakefile for GNU diffutils programs.

# Copyright (C) 2001, 2002 Free Software Foundation, Inc.

## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2, or (at your option)
## any later version.

## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.

## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
## 02111-1307, USA.

bin_PROGRAMS = cmp diff diff3 sdiff

EXTRA_DIST = alloca.c memchr.c waitpid.c

noinst_HEADERS = diff.h system.h

LDADD = libdiffutils.la

cmp_SOURCES = cmp.c version.c
diff3_SOURCES = diff3.c version.c
sdiff_SOURCES = sdiff.c version.c
diff_SOURCES = diff.c \
	analyze.c context.c dir.c ed.c ifdef.c io.c \
	normal.c side.c util.c \
	version.c

lib_LTLIBRARIES = libdiffutils.la
libdiffutils_la_SOURCES = \
	error.c fnmatch.c \
	cmpbuf.c \
	regex.c xmalloc.c \
	getopt1.c getopt.c

libdiffutils_la_LDFLAGS = -version-info 0:0:0
libdiffutils_la_LIBADD = @ALLOCA@ @LIBOBJS@
libdiffutils_la_DEPENDENCIES = $(libdiffutils_la_LIBADD)

MAINTAINERCLEANFILES = $(srcdir)/version.c

$(srcdir)/version.c: $(top_srcdir)/configure.in
	(echo '#include <config.h>' && \
	 echo 'char const version_string[] = "(GNU $(PACKAGE)) $(VERSION)";') \
		>$@
