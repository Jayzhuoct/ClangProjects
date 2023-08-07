int main()
{
 int x,y,i,choice;
 int La,Lb,Lc,Ld,Le;
 //初始化
 La=list(La);
 Lb=list(Lb);
 Lc=list(Lc);
 Ld=list(Ld);
 Le=list(Le);
 //菜单
 while(1)
    {
  show();
  printf("请输出要选择的功能：\n");
  scanf("%d",&choice);
  if(choice<0)
  {
   clear(La);
   clear(Lb);
   clear(Lc);
   clear(Ld);
   clear(Le);
   printf("已退出\n");
   return 0;
  }
  switch(choice)
  {
   case 1:
    printf("请输入A集合中元素个数\n");
    scanf("%d",&x);
    printf("请输入B集合中元素个数\n");
    scanf("%d",&y);
    input(La,x);
    input(Lb,y);
    printf("请按回车继续！\n");
    getchar();
    getchar();
    system("cls");
    break;
   case 2:
    binji(La,Lb,Lc);
    printf("A并B=");
    output(Lc);
    printf("请按回车继续！\n");
    getchar();
    getchar();
    system("cls");
    break;
   case 3:
    jiaoji(La,Lb,Ld);
    printf("A交B=");
    output(Ld);
    printf("请按回车继续！\n");
    getchar();
    getchar();
    system("cls");
    break;
   case 4:
    caji(La,Lb,Le);
    printf("A-B=");
    output(Le);
    printf("请按回车继续！\n");
    getchar();
    getchar();
    system("cls");
    break;
   default:
    printf("输入有误！\n");
    printf("请按回车继续！\n");
    getchar();
    getchar();
    system("cls");
    break;
  }
 }
 return 0;
}

