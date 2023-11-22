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
    Elemtype *base;//��ʼ����̬�����ڴ�
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

Status EnQueue(SqQueue*Q,Elemtype elemt)//�����
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
        printf("��������³������!");
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
        printf("���г�ʼ���Ѿ��ɹ���\n");

    else
        printf("���г�ʼ��δ�ɹ���\n");
    printf("\n������Ҫ��ӵ�Ԫ�ظ���������0�����֣���\n");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("��������󣡳��������");
        return 0;
    }
    else
    {
        printf("���������Ԫ�أ�\n");
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%c",&elemt);
            if(EnQueue(&Q,elemt))
                printf("��%d��Ԫ���Ѿ��ɹ����\n",i+1);
              }
    }
    printf("\n������Ҫ���Ӹ�����С�ڵ�������Ӹ�������\n");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("��������³��������");
        return 0;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            DeQueue(&Q,&elemt);
            printf("��%d������Ԫ��Ϊ\t%c\n",i+1,elemt);

        }
        return 0;
    }
}


































