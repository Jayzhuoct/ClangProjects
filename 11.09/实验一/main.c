#include <stdio.h>
#include <stdlib.h>

int main()

  int a,b;
  char operator;
  scanf("%d %c %d",&a,&operator,&b);
  switch(operator)
  {
    case'+':
        printf("%d",a + b);break;
    default:
        printf("error");
  }
  return 0;
}
