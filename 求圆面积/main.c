#include <stdio.h>
#include <stdlib.h>
#define pi 3.1415926
int main()
{
  float r,area,perimeter;
  printf("������Բ�İ뾶r:\n");
  scanf("%f",&r);
  area=pi*r*r;
  perimeter=2*pi*r;
  printf("Բ�����Ϊ��%0.03f\n�ܳ�Ϊ��%0.02f",area,perimeter);
   return 0;

}
