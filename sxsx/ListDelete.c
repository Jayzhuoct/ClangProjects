void ListDelete_Sq(Sqlist*L,int Loc,ElemType *e)
{
    if(Loc<1||Loc>L->length)
    {
        printf("error!");
    }
    ElemType*p=&L->elem[Loc-1];
    *e=L->elem[Loc-1];
    ElemType*q=&L->elem[L->length-1];
    for(p++;p<=q;p++)
    {
        *p(p-1)=*p;
    }
    L->length--;
}
