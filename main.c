#include <stdio.h>
#include <TXLib.h>
#include <math.h>

int main(void){

    int a, b, c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int d = pow(b, 2) - 4*a*c;

    int x1 = (-b + sqrt(d))/(2*a);
    int x2 = (-b - sqrt(d))/(2*a);
    printf("%d %d", x1, x2);
}
