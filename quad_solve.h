/*!
    \file
    \brief This file is created for solving quadratic equation
*/

#ifndef QUAD_SOLVE_H__
#define QUAD_SOLVE_H__

	/// Number of quad equation roots
enum NumberOfRoots
{
    NOT_INITIALIZED = -2, ///< equation hasn't been made
    INF             = -1, ///< equation has infinte roots
    ZERO            =  0,  ///< equation has 0 roots
    ONE             =  1,  ///< equation has 1 root
    TWO             =  2,  ///< equation has 2 roots
};

/// Accuracy of double comparison
const double EPSILON = 0.000001; 

/// Structure for coefficients of quad equation
typedef struct Coefficients {
	double a; ///< 1st coeffitient a*x^2
	double b; ///< 2nd coeffitient b*x
	double c; ///< 3d coeffitient c
} Coefficients;

/// Structure for roots of quad equation
typedef struct Roots {
    NumberOfRoots amount_of_roots; ///< amount of roots
    double x1; ///< first root
    double x2; ///< second root
} Roots;

/*!
\brief Solves quad equation
\param[out] roots quad equation roots
\param[in] coeffs quad equation coefficients
\return void
*/
void quad_solver(const Coefficients coeffs, Roots* const roots);

/*!
\brief Compares two double
\param[in] x 1st number
\param[in] y 2nd number
\return true if equal else false
*/
int double_compare(const double x, const double y);

#endif // QUAD_SOLVE_H__