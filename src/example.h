/*
 * example.h
 *
 * Python and C interoperatibility example
 *
 * Copyright (c) 2020 F. Aragon. All rights reserved.
 * Released under the BSD 3-Clause License (see the doc/LICENSE)
 */

#ifndef example_h
#define example_h

typedef int (*ecb_f)(char *buf, unsigned buf_size, int id);

int example_void();
int example_int(int v);
int example_str(const char *s);
int example_buf(char *b, unsigned bs);
int example_cb(char *b, unsigned bs, ecb_f cbf, int id);

#endif
