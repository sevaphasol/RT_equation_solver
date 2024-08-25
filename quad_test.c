/*!
    \file
    \brief This file is created for testing solving quadratic equation
*/

#include <stdio.h>
#include <TXLib.h>
#include "colors.h"
#include "quad_solve.h"
#include "quad_test.h"

int quad_solver_test(const TestQuad test)
{
    Roots roots = {NOT_INITIALIZED, 0, 0};
    quad_solver(test.coeffs, &roots);
    if (is_quad_solved_incorrectly(roots, test.right_roots))
    {
        red_print("Error\n"
				  "Test %d\n"
                  "Equation with coefficients %lf, %lf, %lf has %d roots, this roots: %lf %lf\n"
                  "Number of roots solved by programm: %d. Roots given by programm: %lf and %lf\n",
                  test.number_of_test, test.coeffs.a, test.coeffs.b, test.coeffs.c, test.right_roots.amount_of_roots, test.right_roots.x1, test.right_roots.x2,
                  roots.amount_of_roots, roots.x1, roots.x2);
        return -1;
    }
	else 
		green_print("Test %d successfull\n", test.number_of_test);
		return 0;
}

bool is_quad_solved_incorrectly(const Roots roots, const Roots right_roots)
{
    return !((double_compare(roots.x1, right_roots.x1) && double_compare(roots.x2, right_roots.x2))
       || (double_compare(roots.x1, right_roots.x2) && double_compare(roots.x2, right_roots.x1)))
       || roots.amount_of_roots != right_roots.amount_of_roots;
}

bool quad_solver_testing()
{
    int failed = 0;
	FILE *fp = fopen("tests.txt", "r");
	if (fp != NULL)
	{
		while (true)
		{
			TestQuad test = {};
			int amount_of_roots = 0;
			if (fscanf(fp, "%d %lf %lf %lf %d %lf %lf\n", &test.number_of_test, &test.coeffs.a, &test.coeffs.b,
					  &test.coeffs.c, &amount_of_roots, &test.right_roots.x1, &test.right_roots.x2) != 7)
				break;
			test.right_roots.amount_of_roots = (NumberOfRoots) amount_of_roots;

			failed += quad_solver_test(test);
		}

		if (!failed)
			green_print("Testing is successfull\n");
		else
			red_print("Testing failed\n");

		return !failed;		
	}
	else 
	{
		printf("File hasn't been read\n");
	}
	return -1;
}