/*!
    \file
    \brief This file is created for testing solving quadratic equation
*/

#include <stdio.h>
#include <TXLib.h>
#include "quad_assert.h"
#include "colors.h"

void quad_assert_func(const bool statement, const int line, const char *file, const char *function)
{
	if (!statement)
	{
		red_print("Assertion failed: string %d, file %s, function %s\n", line, file, function);
		exit(EXIT_FAILURE);
	}
}
