#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    for (n=3;n<=200000;n++)
    {
        if(n%9==0)
            continue;
        printf("%8d",n);
    }
    printf("\n");
    return 0;
}
