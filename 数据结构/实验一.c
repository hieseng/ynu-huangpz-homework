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

Status InitQueue(LinkQueue *Q)//��ʼ��
{
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
        exit(OVERFLOW);
    Q->front->next=NULL;
    return OK;
}

Status DeQueue(LinkQueue *Q,Elemtype *e)//QΪ�ǿն��У�ɾ��Q�Ķ�ͷԪ�أ�����e������ֵ
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


Status EnQueue(LinkQueue *Q,Elemtype *e)//����Q���ڣ�����Ԫ��eΪQ�Ķ�βԪ��
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
            scanf("%c",&e);
            if(EnQueue(&Q,&e))
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
            DeQueue(&Q,&e);
            printf("��%d������Ԫ��Ϊ\t%c\n",i+1,e);
        }
        return 0;
    }
}
