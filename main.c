/*!
    \file
    \brief This file is main in this project

    It solves quad equation
*/

#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


/// Number of quad equation roots
enum NumberOfRoots
{
    NOT_INITIALIZED = -2, //equation hasn't been made
    INF = -1, //equation has infinte roots
    ZERO = 0, // equation has 0 roots
    ONE = 1, // equation has 1 root
    TWO = 2, // equation has 2 roots
};

/// Accuracy of double comparison
const double EPSILON = 0.000001; 

/// Structure for coeffitients of quad equation
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

/// Structure for testing programm
typedef struct TestQuad { 
	int number_of_test; ///< number of test 
	Coefficients coeffs; /// coeffitients of equation
	Roots right_roots; /// right roots of equation 
} TestQuad;

/*!
Solves quad equation
\param[out] roots quad equation roots
\param[in] coeffs quad equation coeffititens
*/
void quad_solver(const Coefficients coeffs, Roots* const roots);

/*!
Displays quad equation roots
\param[in] roots quad equation roots
*/
void roots_output(const Roots roots);
/*!
Receives quad equation coeffitients 
\param[out] coeffs quad equation coeffs
*/
void coeffs_input(Coefficients* const coeffs);
/*!
Checks input flags in console
\param[out] only_test no input data, only tests if true 
\param[out] do_test turn on testing if true
\param[in] argc
\param[in] argv
*/
void flags_input(int argc, char * argv[], bool *only_test, bool *do_test);
/*!
Print help flag information
*/
void flag_help();
/*!
Turn off input data
\param[out] only_test no input data, only tests if true 
*/
void flag_only_test(bool *only_test);
/*!
Turn on testing
\param[out] do_test turn on testing if true
*/
void flag_do_test(bool *do_test);
/*!
Clears stdout for scanf
*/
void clear_stdout();
/*!
Compares two double
\param[in] x 1st number
\param[in] y 2nd number
\return true if equal else false
*/
int double_compare(const double x, const double y);
/*!
Test sollving of quad equation
\param[in] test equation, contains coefficients and right roots
\return 1 if test is ok else 0
*/
int quad_solver_test(const TestQuad test);
/*!
Checks if quad equation solved correctly
\param[in] roots roots from solving
\param[in] right_roots expected roots
\return true if quad equation solved correctly else false
*/
bool is_quad_solved_incorrectly(const Roots roots, const Roots right_roots);
/*!
Do many tests
\return true if test is ok else false
*/
bool quad_solver_testing();


int main(int argc, char *argv[])
{
	Coefficients coeffs = {0, 0, 0};
    Roots roots = {NOT_INITIALIZED, 0, 0};
    bool only_test = false;
    bool do_test = false;

    flags_input(argc, argv, &only_test, &do_test);

    if (!only_test)
    {
        coeffs_input(&coeffs);

        quad_solver(coeffs, &roots);

        roots_output(roots);
    }

    if (do_test)
    {
        if (quad_solver_testing())
            printf("Тестирование успешно\n");
        else
            printf("Тестирование провалено\n");
    }


    return EXIT_SUCCESS;
}

int double_compare(const double x, const double y)
{
    assert (isfinite(x));
    assert (isfinite(y));
    return (fabs(x - y) < EPSILON);
}

void quad_solver(const Coefficients coeffs, Roots* const roots)
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
            roots->x1 = roots->x2 = -coeffs.b/(2*coeffs.a);
            roots->amount_of_roots = ONE;
        }
        else if (d < 0)
            roots->amount_of_roots = ZERO;
        else if (d > 0)
        {
            roots->x1 = (-coeffs.b + sqrt(d))/(2*coeffs.a);
            roots->x2 = (-coeffs.b - sqrt(d))/(2*coeffs.a);
            roots->amount_of_roots = TWO;
        }
    }
}

void roots_output(const Roots roots)
{
    switch (roots.amount_of_roots){
        case ZERO: 
			printf("Корней нет \n");
            break;
        case ONE: 
			printf("%lf \n", roots.x1);
			break;
        case TWO: 
			printf("%lf %lf \n", roots.x1, roots.x2);
            break;
        case INF: 
			printf("Любое число \n");
            break;
        case NOT_INITIALIZED:
        default: 
			fprintf(stderr, "Где-то ошибка \n");
    }
}

void coeffs_input(Coefficients* const coeffs)
{
    assert(coeffs != NULL);
    while (true)
    {
        printf("Введите коэффициенты a, b, c: \n");
        int accepted_values = scanf("%lf %lf %lf", &(coeffs->a), &(coeffs->b), &(coeffs->c));
        if (accepted_values != 3)
            clear_stdout();
        else
            break;
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
    printf("Help information \n"
           "--help        show this information\n"
           "--only_test   no solving equation, just test\n");
}

void flag_only_test(bool *only_test)
{
    *only_test = true;
}

void flag_do_test(bool *do_test)
{
    *do_test = true;
}

void clear_stdout()
{
    int symbol = getchar();
    while (symbol != '\n' && symbol != EOF)
	{
        symbol = getchar();
    }
}

int quad_solver_test(const TestQuad test)
{
    Roots roots = {NOT_INITIALIZED, 0, 0};
    quad_solver(test.coeffs, &roots);
    if (is_quad_solved_incorrectly(roots, test.right_roots))
    {
        printf("Error\n"
               "Тест %d\n"
               "Уравнение c коэффициентами %lf, %lf, %lf имеет %d корней, эти корни: %lf %lf\n"
               "Количество получаемых программой корней: %d. Корни получаемые программой: %lf и %lf\n",
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
    int failed = 0;
    TestQuad test1 = {1, {1, 2, -3}, {TWO, 1, -3}};
    TestQuad test2 = {2, {0, 0, 0}, {INF, 0, 0}};
    TestQuad test3 = {3, {0, 0, 1}, {ZERO, 0, 0}};
    TestQuad test4 = {4, {0.0000001, 1, -1}, {ONE, 1, 1}};
    TestQuad test5 = {5, {10.101, -2043.997956, 98390.5925184}, {TWO, 123.456, 78.9}};

    failed += quad_solver_test(test1);
    failed += quad_solver_test(test2);
    failed += quad_solver_test(test3);
    failed += quad_solver_test(test4);
    failed += quad_solver_test(test5);
    if (!failed)
    {
        return true;
    }
    return false;
}
