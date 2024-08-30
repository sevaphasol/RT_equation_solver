/*!
    \file
    \brief This file is main in this project
*/

#include <TXLib.h>
#include "colors.h"
#include "flags.h"
#include "quad_solve.h"
#include "quad_test.h"
#include "user_interaction.h"

int main(int argc, char *argv[])
{
	Coefficients coeffs = {0, 0, 0};
    Roots roots = {NOT_INITIALIZED, 0, 0};
    bool only_test = false;
    bool do_test = false;

	flags_input_getopt(argc, argv, &only_test, &do_test);

    if (!only_test)
    {
        coeffs_input(&coeffs);

        quad_solver(coeffs, &roots);

        roots_output(roots);
    }

    if (do_test)
    {
        quad_solver_testing();
	}

    return EXIT_SUCCESS;
}
