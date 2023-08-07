#include <stdio.h>
#include <stdlib.h>
#include "List.h"
int main()
{
    LinkQueue *Q;
    Q=InitLQeue(Q);
    Q=CreatLQueue(Q);
    traverseLQeue(Q);
    Q=DeLQeue(Q);
    traverseLQeue(Q);
    printf("\n");
    EmptyLQueue(Q);
    char c;
    c=GetLQueue(Q);
    putchar(c);
    return 0;
}
