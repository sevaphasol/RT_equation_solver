/*!
    \file
    \brief This file is created for color text in console
*/

#include <stdio.h>
#include <TXLib.h>
#include <string.h>
#include "colors.h"

void color_print(const char *color_code, const char *str, ...)
{	
	va_list list;        
    va_start(list, str);   
    
	set_color(color_code);
	
    vprintf(str, list);
	
	reset_color();
	
    va_end(list);
}

void set_color(const char *color_code)
{
	int len = strlen(color_code);
	for (int i = 0; i < len; i++)
	{
		putchar(*color_code++);
	}
}

void reset_color()
{
	printf(WHITE_CODE);
}
