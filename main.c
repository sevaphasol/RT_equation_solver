#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <stdlib.h>



enum number_of_Roots
{
    NOT_INITIALIZED = -2,
    INF = -1,
    ZERO = 0,
    ONE = 1,
    TWO = 2
};


const double EPSILON = 0.000001; /* for double_compare */

typedef struct Coefficients { double a; double b; double c; } Coefficients;

typedef struct Roots { int amount_of_roots; double x1; double x2; } Roots;

void solver(Coefficients coeffs, Roots* roots);
void output(const Roots roots);
void input(Coefficients* coeffs);
void clear_std_out();
int double_compare(double x, double y);
int solver_test(int num, Coefficients coeffs, Roots right_roots);
int testing();


int main()
{
    Coefficients coeffs;
    Roots roots;

    input(&coeffs);

    solver(coeffs, &roots);

    output(roots);

    testing();

    return EXIT_SUCCESS;
}

int double_compare(double x, double y)
{
    assert (isfinite(x));
    assert (isfinite(y));
    return (fabs(x - y) < EPSILON);
}

void solver(Coefficients coeffs, Roots* roots)
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
            roots->x1 = (-coeffs.b + sqrt(coeffs.b*coeffs.b - 4*coeffs.a*coeffs.c))/(2*coeffs.a);
            roots->x2 = (-coeffs.b - sqrt(coeffs.b*coeffs.b - 4*coeffs.a*coeffs.c))/(2*coeffs.a);
            roots->amount_of_roots = TWO;
        }
    }
}

void output(const Roots roots)
{
    switch (roots.amount_of_roots){
        case ZERO: printf("Корней нет \n");
                break;
        case ONE: printf("%lf \n", roots.x1);
                break;
        case TWO: printf("%lf %lf \n", roots.x1, roots.x2);
                break;
        case INF: printf("Любое число \n");
                break;
        default: fprintf(stderr, "Где-то ошибка \n");
    }
}

void input(Coefficients* coeffs)
{
    while (true)
    {
        printf("Введите коэффициенты a, b, c: \n");
        int accepted_values = scanf("%lf %lf %lf", &(coeffs->a), &(coeffs->b), &(coeffs->c));
        if (accepted_values != 3)
            clear_std_out();
        else
            break;
    }
}

void clear_std_out()
{
    int symbol = getchar();
    while (symbol != '\n' && symbol != EOF){
        symbol = getchar();
    }
}

int solver_test(int num, Coefficients coeffs, Roots right_roots)
{
    Roots roots = {NOT_INITIALIZED, 0, 0};
    solver(coeffs, &roots);
    if (!((double_compare(roots.x1, right_roots.x1) && double_compare(roots.x2, right_roots.x2))
       || (double_compare(roots.x1, right_roots.x2) && double_compare(roots.x2, right_roots.x1)))
       || roots.amount_of_roots != right_roots.amount_of_roots)
    {
        printf("Error\n"
               "Тест %d\n"
               "Уравнение c коэффициентами %lf, %lf, %lf имеет %d корней, эти корни: %lf %lf\n"
               "Количество получаемых программой корней: %d. Корни получаемые программой: %lf и %lf\n",
                num, coeffs.a, coeffs.b, coeffs.c, right_roots.amount_of_roots, right_roots.x1, right_roots.x2,
                roots.amount_of_roots, roots.x1, roots.x2);
        return 1;
    }
    return 0;
}

int testing()
{
    int failed = 0;
    failed += solver_test(1, {1, 2, -3}, {2, 1, -3});
    failed += solver_test(2, {0, 0, 0}, {INF, 0, 0});
    failed += solver_test(3, {0, 0, 1}, {ZERO, 0, 0});
    failed += solver_test(4, {0.0000001, 1, -1}, {1, 1, 1});
    failed += solver_test(5, {10.101, -2043.997956, 98390.5925184}, {2, 123.456, 78.9});
    if (!failed)
    {
        printf("Тестирование успешно");
        return 0;
    }
    return 1;
}





