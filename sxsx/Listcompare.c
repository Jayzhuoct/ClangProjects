int listcompare1(Sqlit La,Sqlist Lb)
{
    int j=1;
    while(j<=La.length&&j<=Lb.length)
    {
        if(La.elem[j]<Lb.elem[j])
            return -1;
        else if(La.elem[j]>Lb.elem[j])
            return 1;
        else j++;
    }
    if(La.length==Lb.length)
        return 0;
    else if(La.length<Lb.length)
        return -1;
    else return 1;
}
