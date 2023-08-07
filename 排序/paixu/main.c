#include<stdio.h>
#include<stdlib.h>
#define RADIX 10//基数的个数 0-9
typedef struct node
{
    int  key;//关键字
    struct node *next;//指向下一个数据节点的指针
}Node;//数据节点指针
void simple_insertsort(int *s,int length);//简单插入排序
void insert_sort(int *s,int length,int k);//插入排序
void bubble_sort(int *s,int length);//冒泡排序
void pre_bubblesort(int *s,int length);//改进的冒泡排序的算法
void select_sort(int *s,int length);//选择排序
void shell_sort(int *s,int length);//希尔排序
void Quick_Sort(int *s,int i,int j);//快速排序算法
int partition(int *s,int i,int j);//快速划分函数  配合快速排序函数的使用
void Heap_Sort(int *s,int length);//堆排序算法
void Heap_Adjust(int *s,int i,int length);//排序调整函数 配合堆排序函数的使用
void Radix_sort(int a[],int n);//基数排序函数
int resolve(int key,int level);//对数据进行划分层次
void Arrange(Node*arraynode,Node*group[],int level);//对待排序数据进行分配处理
Node*collect(Node*group[]);//对group数组进行收集处理的函数
void Merge_sort(int *a,int i,int j,int*b );//归并排序函数
void Merge(int *a,int s1,int e1,int s2,int e2,int *b);//合并函数
void  main()
{
    int m;//数据的个数
    int n[100];//待排序的数组
    int s[100];//中间数组
    int i;
    int k;//输入的插入数据
    printf("请输入数据的个数:\n");
      scanf("%d",&m);
      printf("请依次输入数据:\n");
        for(i=0;i<m;i++)
            scanf("%d",&n[i]);
          printf("===========堆排序==============\n");
          Heap_Sort(n,m);
          for(i=0;i<m;i++)
            printf("%d\t",n[i]);
             printf("\n");
              printf("==========简单插入排序==============\n");
                simple_insertsort(n,m);
                for(i=0;i<m;i++)
                    printf("%d\t",n[i]);
                   printf("\n");

        printf("==========冒泡排序==============\n");
                bubble_sort(n,m);
                for(i=0;i<m;i++)
                    printf("%d\t",n[i]);
                   printf("\n");
        printf("==========改进的冒泡排序==============\n");
            pre_bubblesort(n,m);
              for(i=0;i<m;i++)
                printf("%d\t",n[i]);
               printf("\n");
       printf("==========选择排序==============\n");
              select_sort(n,m);
              for(i=0;i<m;i++)
                  printf("%d\t",n[i]);
                  printf("\n");
    printf("==========希尔排序==============\n");
         shell_sort(n,m);
           for(i=0;i<m;i++)
              printf("%d\t",n[i]);
           printf("\n");
    printf("==========快速排序==============\n");
          Quick_Sort(n,0,m-1);//传值传的是第一个数组元素和最后一个数组元素的下标
          for(i=0;i<m;i++)
            printf("%d\t",n[i]);
            printf("\n");
            printf("==========基数排序==============\n");
              Radix_sort(n,m);
              for(i=0;i<m;i++)
                printf("%d\t",n[i]);
              printf("\n");//换行
            printf("==========归并排序==============\n");
                 Merge_sort(n,0,m-1,s);
                 for(i=0;i<m;i++)
                    printf("%d\t",n[i]);
                    printf("\n");
         printf("==========插入排序==============\n");
              printf("请输入要插入的数据:\n");
                 scanf("%d",&k);
                 insert_sort(n,m,k);
                   for(i=0;i<m+1;i++)
                      printf("%d\t",n[i]);
                     printf("\n");
}
void Heap_Sort(int *s,int length)//堆排序算法
{
    int i;
    int temp;//中间变量
    for(i=length/2-1;i>=0;--i)
        Heap_Adjust(s,i,length);//构建堆的过程
      //调整排序范围的过程
          for(i=length-1;i>0;--i)
          {
                 temp=s[i];//将数组中的第一各元素和最后一个元素交换数值
                 s[i]=s[0];
                 s[0]=temp;
                 Heap_Adjust(s,0,i);//将最大值赋值给后面的节点  创造遍历时递增排序的效果

          }
}
void Heap_Adjust(int *s,int i,int length)
{
    int temp;
    int child;//用来存储孩子节点在数组中的下标
      for( ; 2*i+1<length;i=child)//循环的判断条件是判断是否该节点存在孩子节点
      {
                child=2*i+1;
                 if(child<length-1&&s[child]<s[child+1])//length-1代表最后一个元素的下标
                 // 如果child<length-1说明child所在的节点还有一个兄弟节点
                  child++;//如果右节点大于左节点  将右节点的值  赋值给其父亲节点
                 if(s[i]<s[child])//该节点的值小于其孩子节点的值   将值进行交换
                 {
                     temp=s[i];
                     s[i]=s[child];
                     s[child]=temp;//交换数值

                 }
                 else
                    break;

      }
}
void simple_insertsort(int *s,int length)//简单插入排序
{
    int i,j;
    int temp;//中间变量
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
    //递增的冒泡排序
    int i,j;
    int t;
    for(i=0;i<length-1;i++)
        for(j=0;j<length-i-1;j++)
       {
                if(s[j+1]< s[j])
                {
                    t=s[j+1];
                    s[j+1]=s[j];
                    s[j]=t;//数值交换
                }

      }
    //进行插入排序
      for(i=length-1;i>=0;i--)
      {
            if(k<s[i])
            {
                s[i+1]=s[i];
            }
            else
                break;

      }
      s[i+1]=k;//进行插入
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
            s[i+1]=t;//交换数据
        }
    }
}
void pre_bubblesort(int *s,int length)
{
    int i;
    int j=length-1;
    int flag;//循环结束的标志
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
                flag=1;//以flag的值作为循环结束的标志
                         // 可以在有序的情况下降低时间复杂度
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
            s[i]=t;//交换数据
        }

    }
}
void  shell_sort(int *s,int length)
{
    int increment;//增量变量
     int i;
     int j;
     int temp;
       for(increment=length/2;increment>0;increment/=2)//控制增量的规则变化
          for(i=increment;i<length;i++)//进行快速排序在 增量规则变化的基础上
       {
           temp=s[i];
           for(j=i-increment;j>=0&&s[j]>temp;j-=increment)
           {
               s[j+increment]=s[j];
           }
           s[j+increment]=temp;
       }
}
void Quick_Sort(int *s,int i,int j)//快速排序算法
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
    //划分函数
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
    //将temp的值赋值给最后停留在的数组的元素
    //保证数组两边以temp为基准左边的小于temp右边的大于temp的数据
    return i;//返回调整完之后的数组的下标  便于之后以下标两边为基准做划分调整
}
void Radix_sort(int a[],int n)
{
    int i,j;//循环
    int  level;//层次变量
    Node*pnode;
    Node*postnode;//指向最后一个节点的指针
    Node*group[RADIX];//创建一个存储各个分组头指针的指针数组
    Node*arraynode=(Node*)malloc(sizeof(Node)*n);//创建一个储存待排序数据的链表
    //对group数组进行初始化
      for(i=0;i<RADIX;i++)
      {
          group[i]=NULL;
      }
      //对arraynode数组进行初始化
        for(j=0;j<n;j++)
        {
            arraynode[j].key=a[j];
            arraynode[j].next=&arraynode[j+1];

        }
        arraynode[j-1].next=NULL;//创建一个完整的链表
        //对arraynode链表的节点进行分配处理
          for(level=1;level<=2;level++)
          {
              while(arraynode!=NULL)
             {
                      pnode=arraynode->next;
                      Arrange(arraynode,group,level);//对每一个节点进行分配
                      arraynode=pnode;
            }
            arraynode=collect(group);//对主关键字进行再次分配处理
        }
        pnode=arraynode;
        j=0;
        while(pnode!=NULL)
        {
            a[j++]=pnode->key;
            pnode=pnode->next;
        }
        free(arraynode);//释放arraynode链表的空间
}
int resolve(int key,int level)//对数据进行划分层次
{
    switch(level)
    {
        case 1: key=key%10;break;//划分为次关键字
        case 2: key=(key%100)/10;break;//求主关键字
    }
    return key;//返回关键字的层次
}
void Arrange(Node*arraynode,Node*group[],int level)//对待排序数据进行分配处理
{
    int index;//链表节点划分层次
    //Node*pnode;
    Node*postnode;//指向最后一个节点的指针
    index=resolve(arraynode->key,level);
    //对group数组进行分配数据
       if(group[index]==NULL)//该分组的为空  进行初始操作
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
          arraynode->next=NULL;//一直保持最后一个节点的next指针为空

       }

}
Node*collect(Node*group[])
{
    Node*pnode;
    int i;
    Node*postnode;//指向最后一个节点的指针
    Node*pHead=NULL;//要返回的链表的头节点指针
    //对group数组进行收集操作
      for(i=0;i<RADIX;i++)
      {
          if(group[i]==NULL)
              continue;
            pnode=group[i];//进行赋初值操作
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
void Merge_sort(int *a,int i,int j,int*b )//归并排序函数
{
    int k;
    if(i<j)
    {
      k=(i+j)/2;//取得中间的分割边界
      Merge_sort(a,i,k,b);
      Merge_sort(a,k+1,j,b);
      Merge(a,i,k,k+1,j,b);//将分开的数据进行合并
    }
}

void Merge(int*a,int s1,int e1,int s2,int e2,int *b)
{
    int k=s1;
    int i=s1;
    while(s1<=e1&&s2<=e2)//判断两个划分部分是否为空
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
    k--;//将k的值指向最后一个节点
    while(k>=i)
    {
        a[k]=b[k];
        k--;
    }
}

