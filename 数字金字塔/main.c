#include <stdio.h>
#include <stdlib.h>

void main()
{
   int i,j,k,m;
   for(i=1;i<=9;i++){
    for(j=1;j<=9-i;j++)
   {
       printf(" ");
   }
    for(k=1;k<=i;k++)
    {
        printf("%c",48+k);
    }
    for(m=i-1;m>0;m--)
    {
        printf("%c",48+m);
    }
    printf("\n");
 }
}
