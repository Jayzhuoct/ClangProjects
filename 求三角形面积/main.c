#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a,b,c,s,area;
    a=3;
    b=4;
    c=5;
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("a=%f\tb=%f\tc=%f\n",a,b,c);
    printf("area=%f\n",area);
    return 0;
}
