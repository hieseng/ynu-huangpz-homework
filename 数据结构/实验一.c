#include <stdio.h>
#include <stdlib.h>
#define OK             1
#define ERROR          0
#define OVERFLOW       -2

typedef int Status;
typedef char Elemtype;

typedef struct QNode
{
    Elemtype data;
    struct QNode*next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q)//初始化
{
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
        exit(OVERFLOW);
    Q->front->next=NULL;
    return OK;
}

Status DeQueue(LinkQueue *Q,Elemtype *e)//Q为非空队列，删除Q的队头元素，并用e返回其值
{
    QueuePtr p;
    if(Q->front==Q->rear)
        return ERROR;
    p=Q->front->next;
    e=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return OK;
}


Status EnQueue(LinkQueue *Q,Elemtype *e)//队列Q存在，插入元素e为Q的队尾元素
{
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p)
        exit(OVERFLOW);
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    return OK;
}


int main()
{
    int i,n;
    Elemtype e;
    LinkQueue Q;
    if(InitQueue (&Q))
        printf("队列初始化已经成功！\n");
    else
        printf("队列初始化未成功！\n");
    printf("\n请输入要入队的元素个数（大于0的数字）：\n");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("此输入错误！程序结束！");
        return 0;
    }
    else
    {
        printf("请输入入队元素：\n");
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%c",&e);
            if(EnQueue(&Q,&e))
                printf("第%d个元素已经成功入队\n",i+1);
              }
    }
    printf("\n请输入要出队个数（小于等于已入队个数）：\n");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("输入错误导致程序结束！");
        return 0;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            DeQueue(&Q,&e);
            printf("第%d个出队元素为\t%c\n",i+1,e);
        }
        return 0;
    }
}
