/*!
    \file
    \brief This file is created for input/output functions 
*/

#include <stdio.h>
#include <TXLib.h>
#include "colors.h"
#include "quad_solve.h"
#include "user_interaction.h"

void roots_output(const Roots roots)
{
    switch (roots.amount_of_roots){
        case ZERO: 
			turquoise_print("No roots \n");
            break;
        case ONE: 
			turquoise_print("%lf \n", roots.x1);
			break;
        case TWO: 
			turquoise_print("%lf %lf \n", roots.x1, roots.x2);
            break;
        case INF: 
			turquoise_print("Any number \n");
            break;
        case NOT_INITIALIZED:
        default: 
			red_print("Error \n");
    }
}

void coeffs_input(Coefficients * const coeffs)
{
    assert(coeffs != NULL);
    while (true)
    {
        purple_print("Enter coefficients a, b, c: \n");
        int accepted_values = scanf("%lf %lf %lf", &(coeffs->a), &(coeffs->b), &(coeffs->c));
        if (accepted_values != 3)
            clear_stdout();
        else
            break;
    }
}

void clear_stdout()
{
    int symbol = getchar();
    while (symbol != '\n' && symbol != EOF)
	{
        symbol = getchar();
    }
}
