#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
int main()
{
    void check(int *);
    int *p1,i;
    printf("请输入五个成绩：\n");
    p1=(int *)malloc(5*sizeof(int));
    for(i=0;i<5;i++)
        scanf("%d",p1+i);
    check(p1);
    return 0;
}
void check(int *p)
{
    int i;
    printf("不合格的成绩是:\n");
    for(i=0;i<5;i++)
        if(p[i]<60)
        printf("%d ",p[i]);
    printf("\n");
}
