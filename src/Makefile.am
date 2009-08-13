#AM_CFLAGS = -Wall -g

bin_PROGRAMS = dmtxoob

dmtxoob_SOURCES = main.c symbol.c symbol.h\
				util.c  util.h  dbus.c dbus.h

AM_CFLAGS = -Wall -g -I/usr/local/include -I/usr/include -D_MAGICK_CONFIG_H \
                @MAGICK_CFLAGS@ @BLUEZ_CFLAGS@ @DBUS_CFLAGS@ @GLIB_CFLAGS@

dmtxoob_LDFLAGS = -ldmtx @LIBDMTX_CFLAGS@ @MAGICK_LIBS@ \
        @GLIB_LIBS@ @DBUS_LIBS@ @BLUEZ_LIBS@ @MAGICK_LIBS@

LD_ADD = @LIBDMTX_CFLAGS@ @MAGICK_LIBS@ \
        @GLIB_LIBS@ @DBUS_LIBS@ @BLUEZ_LIBS@ @MAGICK_LIBS@
