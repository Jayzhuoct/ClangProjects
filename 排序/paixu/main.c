#include<stdio.h>
#include<stdlib.h>
#define RADIX 10//�����ĸ��� 0-9
typedef struct node
{
    int  key;//�ؼ���
    struct node *next;//ָ����һ�����ݽڵ��ָ��
}Node;//���ݽڵ�ָ��
void simple_insertsort(int *s,int length);//�򵥲�������
void insert_sort(int *s,int length,int k);//��������
void bubble_sort(int *s,int length);//ð������
void pre_bubblesort(int *s,int length);//�Ľ���ð��������㷨
void select_sort(int *s,int length);//ѡ������
void shell_sort(int *s,int length);//ϣ������
void Quick_Sort(int *s,int i,int j);//���������㷨
int partition(int *s,int i,int j);//���ٻ��ֺ���  ��Ͽ�����������ʹ��
void Heap_Sort(int *s,int length);//�������㷨
void Heap_Adjust(int *s,int i,int length);//����������� ��϶���������ʹ��
void Radix_sort(int a[],int n);//����������
int resolve(int key,int level);//�����ݽ��л��ֲ��
void Arrange(Node*arraynode,Node*group[],int level);//�Դ��������ݽ��з��䴦��
Node*collect(Node*group[]);//��group��������ռ�����ĺ���
void Merge_sort(int *a,int i,int j,int*b );//�鲢������
void Merge(int *a,int s1,int e1,int s2,int e2,int *b);//�ϲ�����
void  main()
{
    int m;//���ݵĸ���
    int n[100];//�����������
    int s[100];//�м�����
    int i;
    int k;//����Ĳ�������
    printf("���������ݵĸ���:\n");
      scanf("%d",&m);
      printf("��������������:\n");
        for(i=0;i<m;i++)
            scanf("%d",&n[i]);
          printf("===========������==============\n");
          Heap_Sort(n,m);
          for(i=0;i<m;i++)
            printf("%d\t",n[i]);
             printf("\n");
              printf("==========�򵥲�������==============\n");
                simple_insertsort(n,m);
                for(i=0;i<m;i++)
                    printf("%d\t",n[i]);
                   printf("\n");

        printf("==========ð������==============\n");
                bubble_sort(n,m);
                for(i=0;i<m;i++)
                    printf("%d\t",n[i]);
                   printf("\n");
        printf("==========�Ľ���ð������==============\n");
            pre_bubblesort(n,m);
              for(i=0;i<m;i++)
                printf("%d\t",n[i]);
               printf("\n");
       printf("==========ѡ������==============\n");
              select_sort(n,m);
              for(i=0;i<m;i++)
                  printf("%d\t",n[i]);
                  printf("\n");
    printf("==========ϣ������==============\n");
         shell_sort(n,m);
           for(i=0;i<m;i++)
              printf("%d\t",n[i]);
           printf("\n");
    printf("==========��������==============\n");
          Quick_Sort(n,0,m-1);//��ֵ�����ǵ�һ������Ԫ�غ����һ������Ԫ�ص��±�
          for(i=0;i<m;i++)
            printf("%d\t",n[i]);
            printf("\n");
            printf("==========��������==============\n");
              Radix_sort(n,m);
              for(i=0;i<m;i++)
                printf("%d\t",n[i]);
              printf("\n");//����
            printf("==========�鲢����==============\n");
                 Merge_sort(n,0,m-1,s);
                 for(i=0;i<m;i++)
                    printf("%d\t",n[i]);
                    printf("\n");
         printf("==========��������==============\n");
              printf("������Ҫ���������:\n");
                 scanf("%d",&k);
                 insert_sort(n,m,k);
                   for(i=0;i<m+1;i++)
                      printf("%d\t",n[i]);
                     printf("\n");
}
void Heap_Sort(int *s,int length)//�������㷨
{
    int i;
    int temp;//�м����
    for(i=length/2-1;i>=0;--i)
        Heap_Adjust(s,i,length);//�����ѵĹ���
      //��������Χ�Ĺ���
          for(i=length-1;i>0;--i)
          {
                 temp=s[i];//�������еĵ�һ��Ԫ�غ����һ��Ԫ�ؽ�����ֵ
                 s[i]=s[0];
                 s[0]=temp;
                 Heap_Adjust(s,0,i);//�����ֵ��ֵ������Ľڵ�  �������ʱ���������Ч��

          }
}
void Heap_Adjust(int *s,int i,int length)
{
    int temp;
    int child;//�����洢���ӽڵ��������е��±�
      for( ; 2*i+1<length;i=child)//ѭ�����ж��������ж��Ƿ�ýڵ���ں��ӽڵ�
      {
                child=2*i+1;
                 if(child<length-1&&s[child]<s[child+1])//length-1�������һ��Ԫ�ص��±�
                 // ���child<length-1˵��child���ڵĽڵ㻹��һ���ֵܽڵ�
                  child++;//����ҽڵ������ڵ�  ���ҽڵ��ֵ  ��ֵ���丸�׽ڵ�
                 if(s[i]<s[child])//�ýڵ��ֵС���亢�ӽڵ��ֵ   ��ֵ���н���
                 {
                     temp=s[i];
                     s[i]=s[child];
                     s[child]=temp;//������ֵ

                 }
                 else
                    break;

      }
}
void simple_insertsort(int *s,int length)//�򵥲�������
{
    int i,j;
    int temp;//�м����
    for(i=1;i<length;i++)
    {
        temp=s[i];
        for(j=i-1;j>=0&&temp<s[j];j--)
        {
            s[j+1]=s[j];
        }
        s[j+1]=temp;
    }
}
void insert_sort(int *s,int length,int k)
{
    //������ð������
    int i,j;
    int t;
    for(i=0;i<length-1;i++)
        for(j=0;j<length-i-1;j++)
       {
                if(s[j+1]< s[j])
                {
                    t=s[j+1];
                    s[j+1]=s[j];
                    s[j]=t;//��ֵ����
                }

      }
    //���в�������
      for(i=length-1;i>=0;i--)
      {
            if(k<s[i])
            {
                s[i+1]=s[i];
            }
            else
                break;

      }
      s[i+1]=k;//���в���
}
void bubble_sort(int *s,int length)
{
    int i,j;
    int t;
    for(i=0;i<length-1;i++)
     for(j=0;j<length-i-1;j++)
     {
        if(s[i]>s[i+1])
        {
            t=s[i];
            s[i]=s[i+1];
            s[i+1]=t;//��������
        }
    }
}
void pre_bubblesort(int *s,int length)
{
    int i;
    int j=length-1;
    int flag;//ѭ�������ı�־
    int t;
    while(flag)
    {
        flag=0;
        for(i=0;i<j;i++)
        {
            if(s[i]>s[i+1])
            {
                t=s[i];
                s[i]=s[i+1];
                s[i+1]=t;
                flag=1;//��flag��ֵ��Ϊѭ�������ı�־
                         // ���������������½���ʱ�临�Ӷ�
            }
        }
        j--;
    }
}
void  select_sort(int *s,int length )
{
    int i,j;
    int k;
    int  t;
    for(i=0;i<length;i++)
    {
        k=i;
        for(j=i;j<length;j++)
        {
            if(s[j]<s[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            t=s[k];
            s[k]=s[i];
            s[i]=t;//��������
        }

    }
}
void  shell_sort(int *s,int length)
{
    int increment;//��������
     int i;
     int j;
     int temp;
       for(increment=length/2;increment>0;increment/=2)//���������Ĺ���仯
          for(i=increment;i<length;i++)//���п��������� ��������仯�Ļ�����
       {
           temp=s[i];
           for(j=i-increment;j>=0&&s[j]>temp;j-=increment)
           {
               s[j+increment]=s[j];
           }
           s[j+increment]=temp;
       }
}
void Quick_Sort(int *s,int i,int j)//���������㷨
{
    int k;
    if(i<j)
    {
        k=partition(s,i,j);
       Quick_Sort(s,i,k-1);
       Quick_Sort(s,k+1,j);

    }

}
int  partition(int *s,int i,int j)
{
    //���ֺ���
    int temp=s[i];
    while(i<j)
    {
        while(i<j&&s[j]>temp)
            j--;
           if(i<j)
           {
               s[i++]=s[j];
           }
           while(i<j&&s[i]<temp)
           {
               i++;
           }
           if(i<j)
            {
                s[j--]=s[i];
            }
    }
    s[i]=temp;
    //��temp��ֵ��ֵ�����ͣ���ڵ������Ԫ��
    //��֤����������tempΪ��׼��ߵ�С��temp�ұߵĴ���temp������
    return i;//���ص�����֮���������±�  ����֮�����±�����Ϊ��׼�����ֵ���
}
void Radix_sort(int a[],int n)
{
    int i,j;//ѭ��
    int  level;//��α���
    Node*pnode;
    Node*postnode;//ָ�����һ���ڵ��ָ��
    Node*group[RADIX];//����һ���洢��������ͷָ���ָ������
    Node*arraynode=(Node*)malloc(sizeof(Node)*n);//����һ��������������ݵ�����
    //��group������г�ʼ��
      for(i=0;i<RADIX;i++)
      {
          group[i]=NULL;
      }
      //��arraynode������г�ʼ��
        for(j=0;j<n;j++)
        {
            arraynode[j].key=a[j];
            arraynode[j].next=&arraynode[j+1];

        }
        arraynode[j-1].next=NULL;//����һ������������
        //��arraynode����Ľڵ���з��䴦��
          for(level=1;level<=2;level++)
          {
              while(arraynode!=NULL)
             {
                      pnode=arraynode->next;
                      Arrange(arraynode,group,level);//��ÿһ���ڵ���з���
                      arraynode=pnode;
            }
            arraynode=collect(group);//�����ؼ��ֽ����ٴη��䴦��
        }
        pnode=arraynode;
        j=0;
        while(pnode!=NULL)
        {
            a[j++]=pnode->key;
            pnode=pnode->next;
        }
        free(arraynode);//�ͷ�arraynode����Ŀռ�
}
int resolve(int key,int level)//�����ݽ��л��ֲ��
{
    switch(level)
    {
        case 1: key=key%10;break;//����Ϊ�ιؼ���
        case 2: key=(key%100)/10;break;//�����ؼ���
    }
    return key;//���عؼ��ֵĲ��
}
void Arrange(Node*arraynode,Node*group[],int level)//�Դ��������ݽ��з��䴦��
{
    int index;//����ڵ㻮�ֲ��
    //Node*pnode;
    Node*postnode;//ָ�����һ���ڵ��ָ��
    index=resolve(arraynode->key,level);
    //��group������з�������
       if(group[index]==NULL)//�÷����Ϊ��  ���г�ʼ����
       {
           group[index]=arraynode;
           arraynode->next=NULL;
       }
       else{
          postnode=group[index];
          while(postnode->next!=NULL)
          {
              postnode=postnode->next;
          }
          postnode->next=arraynode;
          arraynode->next=NULL;//һֱ�������һ���ڵ��nextָ��Ϊ��

       }

}
Node*collect(Node*group[])
{
    Node*pnode;
    int i;
    Node*postnode;//ָ�����һ���ڵ��ָ��
    Node*pHead=NULL;//Ҫ���ص������ͷ�ڵ�ָ��
    //��group��������ռ�����
      for(i=0;i<RADIX;i++)
      {
          if(group[i]==NULL)
              continue;
            pnode=group[i];//���и���ֵ����
          if(pHead==NULL)
          {
              postnode=pHead=pnode;

          }
          else
          {
              postnode->next=pnode;
              pnode->next=NULL;
          }
          while(postnode->next!=NULL)
          {
              postnode=postnode->next;
          }
          group[i]=NULL;
      }
       return pHead;
}
void Merge_sort(int *a,int i,int j,int*b )//�鲢������
{
    int k;
    if(i<j)
    {
      k=(i+j)/2;//ȡ���м�ķָ�߽�
      Merge_sort(a,i,k,b);
      Merge_sort(a,k+1,j,b);
      Merge(a,i,k,k+1,j,b);//���ֿ������ݽ��кϲ�
    }
}

void Merge(int*a,int s1,int e1,int s2,int e2,int *b)
{
    int k=s1;
    int i=s1;
    while(s1<=e1&&s2<=e2)//�ж��������ֲ����Ƿ�Ϊ��
    {
        if(a[s1]<a[s2])
        b[k++]=a[s1++];
        else
            b[k++]=a[s2++];

    }
    while(s1<=e1)
    {
        b[k++]=a[s1++];
    }
    while(s2<=e2)
    {
        b[k++]=a[s2++];
    }
    k--;//��k��ֵָ�����һ���ڵ�
    while(k>=i)
    {
        a[k]=b[k];
        k--;
    }
}

