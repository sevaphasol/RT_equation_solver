#include <stdio.h>
#include <TXLib.h>
#include <math.h>

const int INF_ROOTS = -1;

int solver(double a, double b, double c, double* x1, double* x2)
    {
        if (a == 0)
        {
            if (b == 0)
            {
                if (c == 0)
                    return INF_ROOTS;
                else
                    return 0;
            }
            else
                *x1 = *x2 = -c/b;
                return 1;
        }
        else
        {
            int d = b*b - 4*a*c;
            if (d < 0)
                return 0;
            else if (d == 0)
                {
                *x1 = *x2 = -b/(2*a);
                return 1;
                }
            else if (d > 0)
                {
                *x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
                *x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
                return 2;
                }
        }
    }


int main(void)
    {
        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

        printf("Введите коэффициенты a, b и c через пробел: ");
        scanf("%lg %lg %lg", &a, &b, &c);

        int nRoots = solver(a, b, c, &x1, &x2);

        switch (nRoots){
            case 0: printf("Корней нет");
                    break;
            case 1: printf("%lg", x1);
                    break;
            case 2: printf("%lg %lg", x1, x2);
                    break;
            case INF_ROOTS: printf("Любое число");
                            break;
            default: printf("Где-то ошибка");
                     return 1;
        }

        return 0;
    }



