#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string[81];
    int i,num=0,word=0;
    char c;
    gets(string);
    for(i=0;(c=string[i])!='\0';i++)
      if(c==' ')
        word=0;
    else if(word==0)
    {
        word=1;
        num++;
    }
    printf("Have %d words\n",num);
    return 0;
}
