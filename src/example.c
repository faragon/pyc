/*
 * example.c
 *
 * Python and C interoperatibility example
 *
 * Copyright (c) 2020 F. Aragon. All rights reserved.
 * Released under the BSD 3-Clause License (see the doc/LICENSE)
 */

#include "example.h"
#include <ctype.h>
#include <malloc.h>
#include <stdio.h>

int example_void()
{
	printf("example_void\n");
	return 0;
}

int example_int(int v)
{
	printf("example_int(%i)\n", v);
	return v;
}

int example_str(const char *s)
{
	printf("example_str('%s')\n", s);
	return 0;
}

int example_buf(char *b, unsigned bs)
{
	unsigned i;
	printf("example_buf(0x");
	for (i = 0; i < bs; printf("%02x", 0xff & (unsigned)b[i++]));
	printf(", %u)\n", bs);
	return bs > 0 ? 0 : 1;
}

int example_cb(char *b, unsigned bs, ecb_f cbf, int id)
{
	int r;
	char *bl;
	unsigned i;
	if (!cbf) {
		printf("invalid callback!\n");
		return 1;
	}
	printf("call callback with a copy of uppercased data\n");
	bl = (char *)malloc(bs);
	if (!bl) {
		printf("not enough memory\n");
		return 2;
	}
	for (i = 0; i < bs; i++)
		bl[i] = toupper(b[i]);
	r = cbf(bl, bs, id);
	printf("called callback return code: %i\n", r);
	free(bl);
	return 0;
}
