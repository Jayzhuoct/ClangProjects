#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"
int main()
{
    long num;
    int B;
    for(int i=0;i<3;i++)
    {
        printf("\nPlase Enter non-negative decimal number£º\n");
        scanf("%ld",&num);
        printf("base(2<=<=9): \n");
        scanf("%d",&B);
        printf("num = %ld , base = %d\n",num,B);
        MultibaseOutput(num,B);
    }
    return 0;
}
