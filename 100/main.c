#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,anwser;
    int a ,b ,c ;
    int c1=0,c2=0,c3=0,c4=0;
    for(i=0;i<100;i++)
    {
            a =rand()%100+1;
            b =rand()%100+1;
            c =rand()%4+1;
            switch(c )
            {
                case 1:
                    printf("%d+%d=",a,b);
                    scanf("%d",&anwser);
                    c1++;//
                    if(anwser==a+b)
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
                    break;
                case 2:
                    printf("%d-%d=",a,b);
                    scanf("%d",&anwser);
                    c2++;//
                    if(anwser==a-b)
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
                    break;
                case 3:
                    printf("%d*%d=",a,b);
                    scanf("%d",&anwser);
                    c3++;//
                    if(anwser==a*b)
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
                    break;
                case 4:
                    printf("%d/%d=",a,b);
                    scanf("%d",&anwser);
                    c4++;//
                    if(anwser==a/b)
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
                    break;
                    printf("%d",c1);
                    printf("%d",c2);
                    printf("%d",c3);
                    printf("%d",c4);
            }
    }
    return 0;
}
