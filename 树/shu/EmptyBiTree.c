#include "List.h"
#include <stdio.h>
#include <stdlib.h>

void EmptyBiTree(BiTree *T)
{
    if(T->data==NULL)
        printf("Empty\n");
    else printf("not Empty\n");
}
