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
	
	/*
	TestQuad data_tests[number_of_tests] = {{0, {1, 2, -3}, {TWO, 1, -3}}, 
											{1, {0, 0, 0}, {INF, 0, 0}},
											{2, {0, 0, 1}, {ZERO, 0, 0}},
											{3, {0.0000001, 1, -1}, {ONE, 1, 1}},
											{4, {10.101, -2043.997956, 98390.5925184}, {TWO, 123.456, 78.9}}};
	*/
	
    while (true)
	{
		TestQuad test = {};
		int amount_of_roots = 0;
		if (fscanf(fp, "%d %lf %lf %lf %d %lf %lf\n", &test.number_of_test, &test.coeffs.a, &test.coeffs.b,
		          &test.coeffs.c, &amount_of_roots, &test.right_roots.x1, &test.right_roots.x2) != 7)
			break;
		test.right_roots.amount_of_roots = (NumberOfRoots) amount_of_roots;

		// failed += quad_solver_test(data_tests[i]);
		failed += quad_solver_test(test);
	}
    
	if (!failed)
		green_print("Testing is successfull\n");
	else
		red_print("Testing failed\n");
	
	return !failed;
}

// запустить крипт 
// как использовать проект 
// о чем проект
// какие фишки
// картинку с тестами
// флаги
// TODO: __LINE__ __func__ __DATE__ _exit()
// свой assert quad_assert