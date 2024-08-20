#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <stdlib.h>

enum number_of_roots {ZERO, ONE, TWO, INF};

const double EPSILON = 0.000001; //константа для погрешности в сравнении double и нуля

int is_null(double n);
int solver(double a, double b, double c, double* x1, double* x2);
void output(const int nRoots, const double x1, const double x2);
void input(double* a, double* b, double* c);
void clear_std_out();

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    input(&a, &b, &c);

    int nRoots = solver(a, b, c, &x1, &x2);

    output(nRoots, x1, x2);

    return EXIT_SUCCESS;
}

int is_null(double n)
{
    return (fabs(n) < EPSILON);
}

int solver(double a, double b, double c, double* x1, double* x2) // решает квадратное уравнение
{
    if (is_null(a))
    {
        if (is_null(b))
        {
            if (is_null(c))
                return INF; // бесконечное кол-во корней
            else
                return ZERO; // нет корней
        }
        else
            *x1 = *x2 = -c/b;
            return ONE;
    }
    else
    {
        double d = b*b - 4*a*c;

        if (is_null(d))
            {
            *x1 = *x2 = -b/(2*a);
            return ONE;
            }
        else if (d < 0)
            return ZERO;
        else if (d > 0)
            {
            *x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            *x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            return TWO;
            }
    }
    return -1;
}

void output(const int nRoots, const double x1, const double x2)
{
    switch (nRoots){
        case ZERO: printf("Корней нет \n");
                break;
        case ONE: printf("%lf \n", x1);
                break;
        case TWO: printf("%lf %lf \n", x1, x2);
                break;
        case INF: printf("Любое число \n");
                        break;
        default: fprintf(stderr, "Где-то ошибка \n");
    }
}

void input(double* a, double* b, double* c)
{
    printf("Введите коэффициенты a, b, c: \n");

    int accepted_values = scanf("%lf %lf %lf", a, b, c);
    while (accepted_values != 3)
    {
        printf("Введите коэффициенты a, b, c: \n");
        clear_std_out();
        accepted_values = scanf("%lf %lf %lf", a, b, c);
    }
}

void clear_std_out()
{
    int symbol = getchar();
    while (symbol != '\n' && symbol != EOF){
        symbol = getchar();
    }
}


// enum
// структуры
// assert

