int main()
{
 int x,y,i,choice;
 int La,Lb,Lc,Ld,Le;
 //��ʼ��
 La=list(La);
 Lb=list(Lb);
 Lc=list(Lc);
 Ld=list(Ld);
 Le=list(Le);
 //�˵�
 while(1)
    {
  show();
  printf("�����Ҫѡ��Ĺ��ܣ�\n");
  scanf("%d",&choice);
  if(choice<0)
  {
   clear(La);
   clear(Lb);
   clear(Lc);
   clear(Ld);
   clear(Le);
   printf("���˳�\n");
   return 0;
  }
  switch(choice)
  {
   case 1:
    printf("������A������Ԫ�ظ���\n");
    scanf("%d",&x);
    printf("������B������Ԫ�ظ���\n");
    scanf("%d",&y);
    input(La,x);
    input(Lb,y);
    printf("�밴�س�������\n");
    getchar();
    getchar();
    system("cls");
    break;
   case 2:
    binji(La,Lb,Lc);
    printf("A��B=");
    output(Lc);
    printf("�밴�س�������\n");
    getchar();
    getchar();
    system("cls");
    break;
   case 3:
    jiaoji(La,Lb,Ld);
    printf("A��B=");
    output(Ld);
    printf("�밴�س�������\n");
    getchar();
    getchar();
    system("cls");
    break;
   case 4:
    caji(La,Lb,Le);
    printf("A-B=");
    output(Le);
    printf("�밴�س�������\n");
    getchar();
    getchar();
    system("cls");
    break;
   default:
    printf("��������\n");
    printf("�밴�س�������\n");
    getchar();
    getchar();
    system("cls");
    break;
  }
 }
 return 0;
}

