#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


#define MaxVertexNum 50

#define QueueSize 50

typedef enum{FALSE,TRUE}define;

typedef char VertexType;  //顶点是字符型
typedef int EdgeType;   //边是整型

define visited[MaxVertexNum];
typedef struct Arcshuzhu{

   EdgeType adj;/*顶点关系类型，无权图中1是相邻0是不相邻；带权图中为权值*/
   VertexType *info;
   }Adj[MaxVertexNum][MaxVertexNum];


typedef struct

{
    VertexType vexs[MaxVertexNum];  //顶点向量
    Adj arcs; //邻接矩阵
    int vexnum,arcnum;
    int kind;   //图中当前的顶点数和边数

}Graph;

/* 有向图的建立*/

void CreateDGGraph(Graph *G)

{

    int i,j,k;

    char ch1[5],ch2[5];

    printf("请输入顶点数和边数(输入格式为:顶点数,边数):");

    scanf("%d,%d",&(G->vexnum),&(G->arcnum));

    printf("请输入顶点名称(输入格式为:a,b,c...)：");

    for(i=0;i<G->vexnum;i++)

    {

       getchar();

        scanf("%c",&(G->vexs[i]));

    }

    for(i=0;i<G->vexnum;i++)

      {

       for(j=0;j<G->vexnum;j++)

           {

            G->arcs[i][j].adj=0;

            G->arcs[i][j].info=0;
           }
      }


        printf("请输入每条边对应的两个顶点名称(输入格式为:a,b):\n");
        for(k=0;k<G->arcnum;k++)

        {
            printf("请输入第%d条边的两个顶点名称：",k+1);
            scanf("%s%s",ch1,ch2);
            i=LocateVex(G,ch1);
            i=LocateVex(G,ch2);

            G->arcs[i][j].adj=1;

        }

}



/*有向网的建立*/
void CreateDNGraph(Graph *G){

    int i,j,k,w;

    char ch1[5],ch2[5];

    printf("请输入顶点数和边数(输入格式为:顶点数,边数):");

    scanf("%d,%d",&(G->vexnum),&(G->arcnum));

    printf("请输入顶点名称(输入格式为:a,b,c...)：");

    for(i=0;i<G->vexnum;i++)

    {

       getchar();

        scanf("%c",&(G->vexs[i]));

    }

    for(i=0;i<G->vexnum;i++)

      {

       for(j=0;j<G->vexnum;j++)

           {

            G->arcs[i][j].adj=0;

            G->arcs[i][j].info=0;
           }
      }


        printf("请输入每条边对应的两个顶点名称(输入格式为:a,b):\n");
        for(k=0;k<G->arcnum;k++)

        {
            printf("请输入第%d条边的两个顶点名称和权值：",k+1);
            scanf("%s%s%d",ch1,ch2,&w);
            i=LocateVex(G,ch1);
            i=LocateVex(G,ch2);

            G->arcs[i][j].adj=w;

        }

}

/*无向图的建立*/
void CreateUDGGraph(Graph *G){

    int i,j,k;

    char ch1[5],ch2[5];

    printf("请输入顶点数和边数(输入格式为:顶点数,边数):");

    scanf("%d,%d",&(G->vexnum),&(G->arcnum));

    printf("请输入顶点名称(输入格式为:a,b,c...)：");

    for(i=0;i<G->vexnum;i++)

    {

       getchar();

        scanf("%c",&(G->vexs[i]));

    }

    for(i=0;i<G->vexnum;i++)

      {

       for(j=0;j<G->vexnum;j++)

           {

            G->arcs[i][j].adj=0;

            G->arcs[i][j].info=0;
           }
      }


        printf("请输入每条边对应的两个顶点名称(输入格式为:a,b):\n");
        for(k=0;k<G->arcnum;k++)

        {
            printf("请输入第%d条边的两个顶点名称：",k+1);
            scanf("%s%s",ch1,ch2);
            i=LocateVex(G,ch1);
            i=LocateVex(G,ch2);

            G->arcs[i][j].adj=1;
            G->arcs[i][j].adj=G->arcs[i][j].adj;
        }

}


/*无向网的建立*/
void CreateUDNGraph(Graph *G){

    int i,j,k,w;

    char ch1[5],ch2[5];

    printf("请输入顶点数和边数(输入格式为:顶点数,边数):");

    scanf("%d,%d",&(G->vexnum),&(G->arcnum));

    printf("请输入顶点名称(输入格式为:a,b,c...)：");

    for(i=0;i<G->vexnum;i++)

    {

       getchar();

        scanf("%c",&(G->vexs[i]));

    }

    for(i=0;i<G->vexnum;i++)

      {

       for(j=0;j<G->vexnum;j++)

           {

            G->arcs[i][j].adj=0;

            G->arcs[i][j].info=0;
           }
      }

          printf("请输入每条边对应的两个顶点名称(输入格式为:a,b):\n");
          for(k=0;k<G->arcnum;k++)

        {
             printf("请输入第%d条边的两个顶点名称和权值：",k+1);
            scanf("%s%s%d",ch1,ch2,&w);
            i=LocateVex(G,ch1);
            i=LocateVex(G,ch2);

            G->arcs[i][j].adj=w;
            G->arcs[i][j].adj=G->arcs[i][j].adj;
        }

}

int LocateVex(Graph *G,char ch[])
{
    int k;

    for(k=0;k<G->vexnum;k++)
    {
        if(strcmp(G->vexs[k],ch)==0)
            break;
    }
    return k;
}


/* 深度优先遍历 */

void Depth(Graph *G,int i)

{

    int j;

    printf("%c\n",G->vexs[i]);   //访问顶点vi

    visited[i]=TRUE;

    for(j=0;j<G->vexnum;j++)           //依次搜索vi邻接点

        if(G->arcs[i][j]==1 && !visited[j])

            Depth(G,j);

}

void Depthsearch(Graph *G)

{

    int i;

    for(i=0;i<G->vexnum;i++)

        visited[i]=FALSE;

    for(i=0;i<G->vexnum;i++)

        if(!visited[i])

            Depth(G,i);

}





/*广度优先遍历*/

typedef struct

{

    int front;

    int rear;

    int count;

    int data[QueueSize];

}AQueue;



void InitQueue(AQueue *Q)

{

    Q->front=Q->rear=0;

    Q->count=0;

}



int QueueEmpty(AQueue *Q)

{

    return Q->count=QueueSize;

}



int QueueFull(AQueue *Q)

{

    return Q->count==QueueSize;

}



void EnQueue(AQueue *Q,int x)

{

    if (QueueFull(Q))

        printf("Queue overflow");

    else

    {

        Q->count++;

        Q->data[Q->rear]=x;

        Q->rear=(Q->rear+1)%QueueSize;

    }

}



int DeQueue(AQueue *Q)

{

    int temp;

    if(QueueEmpty(Q))

    {

        printf("Queue underflow");

        return NULL;

    }

    else

    {

        temp=Q->data[Q->front];

        Q->count--;

        Q->front=(Q->front+1)%QueueSize;

        return temp;

    }

}





void Breadth(Graph *G,int k)

{

    int i,j;

    AQueue Q;

    InitQueue(&Q);

    printf("%c\n",G->vexs[k]);

    visited[k]=TRUE;

    EnQueue(&Q,k);

    while (!QueueEmpty(&Q))

    {

        i=DeQueue(&Q);

        for (j=0;j<G->vexnum;j++)

            if(G->arcs[i][j]==1&&!visited[j])

            {

                printf("%c\n",G->vexs[j]);

                visited[j]=TRUE;

                EnQueue(&Q,j);

            }

    }

}



void Breadthsearch(Graph *G)

{

    int i;

    for (i=0;i<G->vexnum;i++)

        visited[i]=FALSE;

    for (i=0;i<G->vexnum;i++)

        if (!visited[i])

            Breadth(G,i);

}





void main()

{

    Graph *G;

   G=(Graph *)malloc(sizeof(Graph));

   ptintf("请选择：0-有向图，1-有向网，2-无向图，3-无向网：");
   scanf("%d",&G->kind);

   switch(G->kind)
   {
   case 0:
    CreateDGGraph(G);
    break;

   case 1:
    CreateDNGraph(G);
    break;

   case 2:
    CreateUDGGraph(G);
    break;

    case 3:
    CreateUDNGraph;
    break;

    default:
        break;

   }
   getchar();

    printf("深度优先搜索结果为：");

    printf("\n");

    Depthsearch(&G);

    printf("广度优先搜索结果为：");

    printf("\n");

    Breadthsearch(&G);

}

