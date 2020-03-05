/*
 * test.c
 *
 * Copyright (c) 2020 F. Aragon. All rights reserved.
 * Released under the BSD 3-Clause License (see the doc/LICENSE)
 */

#include <stdlib.h>

int main()
{
	return WEXITSTATUS(system("python test.py"));
}
