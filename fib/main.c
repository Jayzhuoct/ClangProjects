#include <stdio.h>
#include <stdlib.h>

   int f(int);
   int main()
{
    int n,i,m=0;
    {
        for(i=1;i<=40;i++)
        {
        printf("%14d",f(i));
        m++;
        if(m%5==0)
        printf("\n");
        }

    }
}
  int f(int n)
  {
      if(n==1||n==2)
        return 1;
      else
        return f(n-1)+f(n-2);
  }

