void ListInsert_Sq(Sqlist *L,int loc,ElemType,e)
{
    ElemType*newsbase,*q;
    if(loc<1||loc>L->length+1)
    {
        printf("Local error");
    }
    if(L->length>=L->listsize)
    {
        newsbase=(ElemType*)realloc(L->elem(L-listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newsbase)
        {
            printf("error");
            exit(OVERFLOW);
        }
        L->elem=newsbase;
        L->listsize+=LISTINCREMENT;
    }
    q=&L->elem[loc-1];
    for(ElemType*p=&L->elem[L->length-1];p>=q;p--)
    {
        *(p+1)=*p;
    }
    *q=e;L->length++;
}
