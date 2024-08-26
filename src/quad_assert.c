/*!
    \file
    \brief This file is created for testing solving quadratic equation
*/

#include <stdio.h>
#include <TXLib.h>
#include "quad_assert.h"

void quad_assert_func(bool statement, int line, const char *file, const char *function)
{
	if (!statement)
	{
		printf("Assertion failed: string %d, file %s, function %s\n", line, file, function);
		exit(0);
	}
}
