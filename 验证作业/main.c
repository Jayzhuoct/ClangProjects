#include <stdio.h>
#include <stdlib.h>
 main()
{
   int s;
     scanf("%d",&s);
   while(s>0)
   {switch(s)
     {
         case 1:printf("%d",s+5);
         case 2:printf("%d",s+4);break;
         case 3:printf("%d",s+3);
         default:printf("%d",s+1);break;
     }
       scanf("%d",&s);
   }

    //int x=10,y=20,t=0;
    //if(x==y)t=x;
    //x=y;
    //y=t;
    //printf("%d %d\n",x,y);

    //char c1,c2;
    //scanf("%d",&c1);
    //c2=c1+9;
    //printf("%d%d\n",c1,c2);

    //int a;
    //a=(int)((double)(3/2)+0.5+(int)1.99*2);
    //printf("%d\n",a);

    //char ch1,ch2;
    //ch1='A'+'5'-'3';
    //ch2='A'+'6'-'3';
    //printf("%d,%c\n",ch1,ch2);

    //int x=10,y=10;
    //printf("%d %d\n",x--,--y);

    //int k=11;
    //printf("k=%d,k=%o,k=%x\n",k,k,k);
    //unsigned a=8,c;
    //c=a>>3;
    //printf("%d\n,c");

    //int  x=023;
    //printf("%d\n",--x);
}
