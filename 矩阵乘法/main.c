#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 4
#define K 4
int main()
{
    int A[M][K]={0};
    int B[K][N]={0};
    int C[M][N]={0};
    int i=1;
    int j=1;
    int m=1;
    printf("������3*3��A����\n");
    for(i=1;i<M;i++)
    {
        printf("A�����%d��\n",i);
        for(j=1;j<K;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("������3*3��B����:\n");
    for(i=1;i<K;i++)
    {
        printf("B�����%d��\n",i);
        for(j=1;j<N;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    printf("C����\n");
    for(i=1;i<M;i++)
    {
        for(j=1;j<N;j++)
        {
            int sum=0;
            for(m=1;m<K;m++)
            {
                sum=sum+A[i][m]*B[m][j];
            }
            C[i][j]=sum;

        }
    }
    for(i=1;i<M;i++)
    {
        for(j=1;j<N;j++)
        {
            printf("%6d",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
