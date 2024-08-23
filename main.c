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
#include <getopt.h>


/// Number of quad equation roots
enum NumberOfRoots
{
    NOT_INITIALIZED = -2, ///< equation hasn't been made
    INF             = -1, ///< equation has infinte roots
    ZERO            = 0,  ///< equation has 0 roots
    ONE             = 1,  ///< equation has 1 root
    TWO             = 2,  ///< equation has 2 roots
};

/// Color of output text in console
enum Colors
{
	RED        = 0,
	GREEN      = 1,
	TURQUOISE,
	PURPLE,
};

/// Vals for getopt_long() return 
enum long_option_vals
{
	HELP = 1,
	DO_TEST = 2,
	ONLY_TEST = 3,
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

/// Structure for testing programm
typedef struct TestQuad { 
	int number_of_test; ///< number of test 
	Coefficients coeffs; ///< coefficients of equation
	Roots right_roots; ///< right roots of equation 
} TestQuad;

/*!
\brief Solves quad equation
\param[out] roots quad equation roots
\param[in] coeffs quad equation coefficients
\return nothing
*/
void quad_solver(const Coefficients coeffs, Roots* const roots);

/*!
\brief Displays quad equation roots
\param[in] roots quad equation roots
\return nothing
*/
void roots_output(const Roots roots);

/*!
\brief Receives quad equation coefficients 
\param[out] coeffs quad equation coeffs
\ return nothing
*/
void coeffs_input(Coefficients* const coeffs);

/*!
\brief Checks input flags in console
\param[out] only_test no input data, only tests if true 
\param[out] do_test turn on testing if true
\param[in] argc
\param[in] argv
\return nothing
*/
void flags_input(int argc, char * argv[], bool *only_test, bool *do_test);

/*!
\brief
Print help flag information
\return nothing
*/
void flag_help();

/*!
\brief Turn off input data
\param[out] only_test no input data, only tests if true 
\return nothing
*/
void flag_only_test(bool *only_test);

/*!
\brief Turn on testing
\param[out] do_test turn on testing if true
\return nothing
*/
void flag_do_test(bool *do_test);

/*!
\brief Clears stdout for scanf
\return nothing
*/
void clear_stdout();

/*!
\brief Compares two double
\param[in] x 1st number
\param[in] y 2nd number
\return true if equal else false
*/
int double_compare(const double x, const double y);

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

/*!
\brief Prints color text in cosole
\param[in] color color of text
\param[in] format pointer on the beginning of the line
\return nothing
*/
void color_print(const Colors color, const char* format, ...);

/*!
\brief Sets color of text in concole 
\param[in] color color of text
\return nothing
*/
void set_color(Colors color);

/*!
\brief Resets color of text in console to white
\return nothing
*/
void reset_color();

void flags_input_getopt(int argc, char * const argv[], bool *only_test, bool *do_test);




int main(int argc, char *argv[])
{
	Coefficients coeffs = {0, 0, 0};
    Roots roots = {NOT_INITIALIZED, 0, 0};
    bool only_test = false;
    bool do_test = false;

    // flags_input(argc, argv, &only_test, &do_test);
	
	flags_input_getopt(argc, argv, &only_test, &do_test);
	
    if (!only_test)
    {
        coeffs_input(&coeffs);

        quad_solver(coeffs, &roots);

        roots_output(roots);
    }

    if (do_test)
    {
        if (quad_solver_testing())
            colorprint(GREEN, "������������ �������\n");
        else
            colorprint(RED, "������������ ���������\n");
    }


    return EXIT_SUCCESS;
}

void color_print(const Colors color, const char *format, ...)
{
    va_list factor;        
    va_start(factor, format);   
    
	set_color(color);
	
    vprintf(format, factor);
	
	reset_color();
	
    va_end(factor);
}

void set_color(Colors color)
{
	switch(color)
	{
		case RED:
			printf("\033[31m");
			break;
		case GREEN:
			printf("\033[32m");
			break;
		case TURQUOISE:
			printf("\033[36m");
			break;
		case PURPLE:
			printf("\033[35m");
			break;
		default:
		;
	}
}

void reset_color()
{
	printf("\033[0m");
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
			colorprint(TURQUOISE, "������ ��� \n");
            break;
        case ONE: 
			colorprint(TURQUOISE, "%lf \n", roots.x1);
			break;
        case TWO: 
			colorprint(TURQUOISE, "%lf %lf \n", roots.x1, roots.x2);
            break;
        case INF: 
			colorprint(TURQUOISE, "����� ����� \n");
            break;
        case NOT_INITIALIZED:
        default: 
			colorprint(RED, "���-�� ������ \n");
    }
}

void coeffs_input(Coefficients* const coeffs)
{
    assert(coeffs != NULL);
    while (true)
    {
        colorprint(PURPLE, "������� ������������ a, b, c: \n");
        int accepted_values = scanf("%lf %lf %lf", &(coeffs->a), &(coeffs->b), &(coeffs->c));
        if (accepted_values != 3)
            clear_stdout();
        else
            break;
    }
}

void flags_input_getopt(int argc, char * const argv[], bool *only_test, bool *do_test)
{
	while (true)
	{
        int option_index = 0;
		struct option long_options[] = {
			{.name = "help", .has_arg = no_argument, .flag = NULL, .val = HELP},
			{.name = "do_test", .has_arg = no_argument, .flag = NULL, .val = DO_TEST},
			{.name = "only_test", .has_arg = no_argument, .flag = NULL, .val = ONLY_TEST},
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
				colorprint(RED, "Error\n");
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
               "���� %d\n"
               "��������� c �������������� %lf, %lf, %lf ����� %d ������, ��� �����: %lf %lf\n"
               "���������� ���������� ���������� ������: %d. ����� ���������� ����������: %lf � %lf\n",
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
