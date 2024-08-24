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
                  "Number of roots solved by programm: %d. Roots given by programm: %lf и %lf\n",
                  test.number_of_test, test.coeffs.a, test.coeffs.b, test.coeffs.c, test.right_roots.amount_of_roots, test.right_roots.x1, test.right_roots.x2,
                  roots.amount_of_roots, roots.x1, roots.x2);
        return -1;
    }
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
	const int number_os_tests = 5;
    int failed = 0;
	// fscanf
	// 
	TestQuad data_tests[number_os_tests] = {{0, {1, 2, -3}, {TWO, 1, -3}}, 
											{1, {0, 0, 0}, {INF, 0, 0}},
											{2, {0, 0, 1}, {ZERO, 0, 0}},
											{3, {0.0000001, 1, -1}, {ONE, 1, 1}},
											{4, {10.101, -2043.997956, 98390.5925184}, {TWO, 123.456, 78.9}}};
    for (int i = 0; i < number_os_tests; i++)
	{
		failed += quad_solver_test(data_tests[i]);
	}
    
	return (!failed);
}


// green_test_print
// запустить крипт 
// как использовать проект 
// о чем проект
// какие фишки
// картинку с тестами
// флаги
// TODO: __LINE__ __func__ __DATE__ _exit()
// свой assert quad_assert