## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(pkgdatadir)/ui
ui_DATA = clock_puzzle.ui


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir). \
	$(cairo_CFLAGS)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(CLOCK_PUZZLE_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = clock_puzzle

clock_puzzle_SOURCES = \
	main.c \
	callbacks.c \
	callbacks.h \
	dependencies.h \
	main_window.c \
	main_window.h \
	game.c \
	game.h


clock_puzzle_LDFLAGS =

clock_puzzle_LDADD = $(CLOCK_PUZZLE_LIBS) \
	$(cairo_LIBS) \
	-L/usr/lib/x86_64-linux-gnu \
	-lm


if PLATFORM_WIN32
clock_puzzle_LDFLAGS += -Wl,--export-all-symbols
else
clock_puzzle_LDFLAGS += -Wl,--export-dynamic
endif

if NATIVE_WIN32
clock_puzzle_LDFLAGS += -mwindows
endif


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(pkgdatadir)

