/*!
    \file
    \brief This file is created for solving quadratic equation
*/

#include <TXLib.h>
#include <math.h>
#include "quad_solve.h"

int double_compare(const double x, const double y)
{
    assert (isfinite(x));
    assert (isfinite(y));
    return (fabs(x - y) < EPSILON);
}

void quad_solver(const Coefficients coeffs, Roots * const roots)
{
    assert (isfinite(coeffs.a));
    assert (isfinite(coeffs.b));
    assert (isfinite(coeffs.c));
    assert (roots != NULL);

    if (double_compare(coeffs.a, 0))
    {
        if (double_compare(coeffs.b, 0))
        {
            if (double_compare(coeffs.c, 0))
            {
                roots->amount_of_roots = INF;
            }
            else
            {
                roots->amount_of_roots = ZERO;
            }
        }
        else
        {
            roots->x1 = roots->x2 = -coeffs.c/coeffs.b;
            roots->amount_of_roots = ONE;
        }
    }
    else
    {
        double d = coeffs.b*coeffs.b - 4*coeffs.a*coeffs.c;

        if (double_compare(d, 0))
        {
			roots->amount_of_roots = ONE;
            roots->x1 = roots->x2 = -coeffs.b/(2*coeffs.a);
        }
        else if (d < 0)
		{
            roots->amount_of_roots = ZERO;
		}
        else if (d > 0)
        {
			roots->amount_of_roots = TWO;
            roots->x1 = (-coeffs.b + sqrt(d))/(2*coeffs.a);
            roots->x2 = (-coeffs.b - sqrt(d))/(2*coeffs.a);
        }
    }
}
