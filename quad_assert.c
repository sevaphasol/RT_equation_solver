/*!
    \file
    \brief This file is created for testing solving quadratic equation
*/

#include <stdio.h>
#include <TXLib.h>
#include "quad_assert.h"

void quad_assert(bool statement, int line, const char *file)
{
	if (!statement)
	{
		printf("Assertion failed: string %d, file %s\n", line, file);
		exit(0);
	}
}
