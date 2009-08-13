/***************************************************************************
 *	Dmtx-OOB for Bluez OOB support                                     *
 *	Author: Md Omar Faruque Sarker <writefaruq@gmail.com>              *
 *	Developed as a part of Bluez GSoC 2009 project                     *
 *	Mentor: Claudio Takahasi <claudio.takahasi@openbossa.org>          *
 *                                                                         *
 *	libdmtx - Data Matrix Encoding/Decoding Library                    *
 *	Copyright (C) 2008, 2009 Mike Laughton                             *
 *	Copyright (C) 2008 Ryan Raasch                                     *
 *	Copyright (C) 2008 Olivier Guilyardi                               *
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
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>
#include <dmtx.h>

#include "util.h"

extern char *program_name;

extern void fatal_error(int errorCode, char *fmt, ...)
{
	va_list va;

	va_start(va, fmt);
	fprintf(stderr, "%s: ", program_name);
	vfprintf(stderr, fmt, va);
	va_end(va);
	fprintf(stderr, "\n\n");
	fflush(stderr);

	exit(errorCode);
}

/* TODO: What this function does? */
extern DmtxPassFail
string_to_int(int *numberInt, const char *number_string, char **terminate)
{
	long number_long;
	int err = 0;

	if (!isdigit(*number_string)) {
		*numberInt = DmtxUndefined;
		return DmtxFail;
	}


	number_long = strtol(number_string, terminate, 10);

	while (isspace((int)**terminate))
	(*terminate)++;
	err = errno;
	if (err != 0 || (**terminate != '\0' && **terminate != '%')) {
		*numberInt = DmtxUndefined;
		return DmtxFail;
	}

	*numberInt = (int)number_long;

	return DmtxPass;
}
