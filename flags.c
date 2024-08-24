/*!
    \file
    \brief This file is created for input flags in console
*/

#include <stdio.h>
#include <TXLib.h>
#include <getopt.h>
#include "colors.h"
#include "flags.h"

void flags_input_getopt(int argc, char *argv[], bool *only_test, bool *do_test)
{
	while (true)
	{
        int option_index = 0;
		struct option long_options[] = {
			{"help", no_argument, NULL, HELP},
			{"do_test", no_argument, NULL, DO_TEST},
			{"only_test", no_argument, NULL, ONLY_TEST},
		};
		
		int c = getopt_long(argc, argv, "hdo", long_options, &option_index);
		
		if (c == -1)
			break;
		
		switch (c)
		{
			case HELP:
			case 'h':
				flag_help();
				break;
			case DO_TEST:
			case 'd':
				flag_do_test(do_test);
				break;
			case ONLY_TEST:
			case 'o':
				flag_only_test(only_test);
				break;
			case '?':
				break;
			default:
				red_print("Error\n");
        }
	}
	
	if (optind < argc) {
        fprintf(stderr, "elemts of ARGV, not pararmetrs: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }
}


void flags_input(int argc, char *argv[], bool *only_test, bool *do_test)
{
    for (int count = 1; count < argc; count++)
    {
        if (!strcmp(argv[count], "--help"))
        {
            flag_help();
        }
        else if (!strcmp(argv[count], "--only_test"))
        {
            flag_only_test(only_test);
        }
        else if (!strcmp(argv[count], "--do_test"))
        {
            flag_do_test(do_test);
        }
    }

}

void flag_help()
{
    yellow_print("Help information \n"
				 "--help        show this information\n"
				 "--only_test   no solving equation, just test\n"
				 "--do_test turn on testing quadratic equation\n");
}

void flag_only_test(bool *only_test)
{
    *only_test = true;
}

void flag_do_test(bool *do_test)
{
    *do_test = true;
}
