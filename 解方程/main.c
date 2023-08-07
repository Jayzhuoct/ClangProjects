#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a,b,c,t,x1,x2,p,q;
    scanf("%lf%lf%lf",&a,&b,&c);
    t=b*b-4*a*c;
    p=-b/(2.0*a);
    q=sqrt(t)/(2.0*a);
    x1=p+q;
    x2=p-q;
    printf("x1=%7.2f\nx2=%7.2f\n",x1,x2);
    return 0;
}
