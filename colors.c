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

/*
void set_color(Colors color)
{
	switch(color)
	{
		case RED:
			printf("\033[31m");
			break;
		case GREEN:
			printf("\033[32m");
			break;
		case YELLOW:
			printf("\033[33m");
			break;
		case BLUE:
			printf("\033[34m");
			break;
		case PURPLE:
			printf("\033[35m");
			break;
		case TURQUOISE:
			printf("\033[36m");
			break;
		default:
		;
	}
}
*/


void reset_color()
{
	printf("\033[0m");
}
