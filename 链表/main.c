#include <stdio.h>
#include <stdlib.h>
#include "Lnode.h"
int main()
{
    printf("Hello world!\n");
    LNode *L;
    L=InitList(L);
    DestroyList(L);
    return 0;
}
