/***************************************************************************
 *	Dmtx-OOB for Bluez OOB support                                     *
 *	Author: Md Omar Faruque Sarker <writefaruq@gmail.com>              *
 *	Developed as a part of Bluez GSoC 2009 project                     *
 *	Mentor: Claudio Takahasi <claudio.takahasi@openbossa.org>          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.              *
***************************************************************************/
#include <glib.h>

#include "symbol.h"
#include "dbus.h"

#define DMTX_SYMBOL_OUTPUT "output.txt"
#define OOB_ROLE "initiator"

static void handle_symbol(const char *infile)
{
	const gchar *outfile = DMTX_SYMBOL_OUTPUT;
	const gchar *oobrole = OOB_ROLE;
	gchar *data;
	gsize len;

	if (symbol_decode(infile, outfile) != 1) {
		printf("Failed to decode dmtx symbol\n");
		return;
	}

	/* Assuming successful decode */
	printf("Decoded dmtx symbol %s to file  %s\n", infile, outfile);

	/* Test file */
	if (!g_file_test(outfile, G_FILE_TEST_IS_REGULAR)) {
		printf("No valid file found");
		return;
	}

	/* parse xml file containing bdaddr */
	if (g_file_get_contents(outfile, &data, &len, NULL) == FALSE) {
		printf("Couldn't load XML file %s\n", outfile);
		return;
	}

	/* Create a paired OOB device from symbol xml data */
	dmtx_oob_gdbus_create_paired_oob_device(data, oobrole);

	g_free(data);
}

int main (int argc, char *argv[])
{
	if (argc == 2)
		handle_symbol(argv[1]);
	else
		fprintf(stderr, "Usage: %s <dmtx-symbol-file> \n", argv[0]);

	return 0;
}
