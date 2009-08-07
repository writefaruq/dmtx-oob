#AM_CFLAGS = -Wall -g

bin_PROGRAMS = dmtxoob

dmtxoob_SOURCES = dmtx-oob.c symbol.c symbol.h dmtxutil.c \
		dmtxutil.h  dmtx-oob-gdbus.c dmtx-oob-gdbus.h

AM_CFLAGS = -Wall -g -I/usr/local/include -I/usr/include -D_MAGICK_CONFIG_H \
                @MAGICK_CFLAGS@ @BLUEZ_CFLAGS@ @DBUS_CFLAGS@ @GLIB_CFLAGS@ \
                @GDBUS_CFLAGS@

dmtxoob_LDFLAGS = -ldmtx @LIBDMTX_CFLAGS@ @MAGICK_LIBS@ \
        @GDBUS_LIBS@ @GLIB_LIBS@ @DBUS_LIBS@ @BLUEZ_LIBS@ @MAGICK_LIBS@

LD_ADD = @LIBDMTX_CFLAGS@ @MAGICK_LIBS@ \
        @GDBUS_LIBS@ @GLIB_LIBS@ @DBUS_LIBS@ @BLUEZ_LIBS@ @MAGICK_LIBS@
