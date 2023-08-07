#include <stdio.h>
#include <stdlib.h>
#define pi 3.1415926
int main()
{
  float r,area,perimeter;
  printf("请输入圆的半径r:\n");
  scanf("%f",&r);
  area=pi*r*r;
  perimeter=2*pi*r;
  printf("圆的面积为；%0.03f\n周长为；%0.02f",area,perimeter);
   return 0;

}
