#include <stdio.h>
#include <stdlib.h>
#define OK             1
#define ERROR          0
#define OVERFLOW      -2
#define MAXQSIZE      100


typedef int Status;
typedef char Elemtype;

typedef struct QNode
{
    Elemtype *base;//初始化动态分配内存
    int front;
    int rear;
    struct QNode*next;
}SqQueue;


Status InitQueue(SqQueue*Q)
{
    Q->base=(Elemtype*)malloc(MAXQSIZE*sizeof(Elemtype));
    if(!Q->base)
        exit(OVERFLOW);
   Q->front=Q->rear=0;
    return OK;
}

Status EnQueue(SqQueue*Q,Elemtype elemt)//入队列
{

    if((Q->rear+1)%MAXQSIZE==(Q->front))
        return ERROR;
    Q->base[Q->rear]=elemt;
    Q->rear=(Q->rear+1)%MAXQSIZE;
    return OK;
}

char DeQueue(SqQueue *Q,Elemtype*e)
{
    if(Q->front==Q->rear)
        printf("输入错误导致程序结束!");
    *e=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXQSIZE;
    return*e;
}

Status OutputQueue(SqQueue Q)
{
    int i;
    for(i=Q.front;i<Q.rear;++i)
    printf("%c",Q.base[i]);
    return OK;
}

int main()
{
    int i,n;
    Elemtype elemt;
    SqQueue Q;
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
            scanf("%c",&elemt);
            if(EnQueue(&Q,elemt))
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
            DeQueue(&Q,&elemt);
            printf("第%d个出队元素为\t%c\n",i+1,elemt);

        }
        return 0;
    }
}


































