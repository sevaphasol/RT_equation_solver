#include <stdio.h>
#include <TXLib.h>
#include <math.h>

const int INF_ROOTS = -1; // ��������� ��� ����������� ������������ ���-�� ������
const double EPSILON = 0.000001; //��������� ��� ����������� � ��������� double � ����

int is_null(double n)
    {
        return (abs(n) < EPSILON);
    }

int solver(double a, double b, double c, double* x1, double* x2) // ������ ���������� ���������
    {
        if (is_null(a))
        {
            if (is_null(b))
            {
                if (is_null(c))
                    return INF_ROOTS; // ����������� ���-�� ������
                else
                    return 0; // ��� ������
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

        printf("������� ������������ a, b � c ����� ������: ");
        scanf("%lg %lg %lg", &a, &b, &c);

        int nRoots = solver(a, b, c, &x1, &x2);

        switch (nRoots){
            case 0: printf("������ ���");
                    break;
            case 1: printf("%lg", x1);
                    break;
            case 2: printf("%lg %lg", x1, x2);
                    break;
            case INF_ROOTS: printf("����� �����");
                            break;
            default: printf("���-�� ������");
                     return 1;
        }

        return 0;
    }







