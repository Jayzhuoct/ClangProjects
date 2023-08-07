#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,n,i=1,sn=0,tn=0;
    printf("ÇëÊäÈëa,nµÄÖµ");
    scanf("%d,%d",&a,&n);
    while(i<=n)
      {
          tn=tn+a;
          sn=sn+tn;
          a=a*10;
          ++i;
      }
      printf("a+aa+aaa+...=%d\n",tn);
      return 0;
}

