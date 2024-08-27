/*!
    \file
    \brief This file is created for testing solving quadratic equation
*/

#ifndef QUAD_TEST_H__
#define QUAD_TEST_H__

#define TEST_FILE "tests.txt"

/// Structure for testing programm
typedef struct TestQuad {
	int number_of_test;  ///< number of test
	Coefficients coeffs; ///< coefficients of equation
	Roots right_roots;   ///< right roots of equation
} TestQuad;

/*!
\brief Test sollving of quad equation
\param[in] test equation, contains coefficients and right roots
\return 1 if test is ok else 0
*/
int quad_solver_test(const TestQuad test);

/*!
\brief Checks if quad equation solved correctly
\param[in] roots roots from solving
\param[in] right_roots expected roots
\return true if quad equation solved correctly else false
*/
bool is_quad_solved_incorrectly(const Roots roots, const Roots right_roots);

/*!
\brief Does many tests
\return true if test is ok else false
*/
bool quad_solver_testing();

#endif // QUAD_TEST_H__
