#include <stdio.h>
#include <stdlib.h>

#define MVNum 100
#define OK 1
#define maxSize 100

//存储表示
int visited[MVNum];
typedef int Status;
typedef char VerTexType;
typedef int OtherInfo;
typedef struct ArcNode
{
	int adjvex;             //该边指向顶点的位置
	struct ArcNode *nextarc;  //指向下一条边的指针
	OtherInfo info;           //和边相关的信息，例如：权值
}ArcNode;
typedef struct VNode
{
	VerTexType data;        //存储顶点名字或一些相关信息
	ArcNode *firstarc;      //指向链表中第一个结点
}VNode,AdjList[MVNum];    //AdjList 则是数组类型
typedef struct
{
	AdjList vertices;      //vertices VNode类型的一个数组，表示顶点表
	int vexnum,arcnum;    //顶点数和边数
}ALGraph;

//在顶点表里定位顶点的位置
int LocateVex(ALGraph G,char v)  //顶点名称v
{
	for(int i=0;i<G.vexnum;i++)
		if(G.vertices[i].data==v) return i;
}

//创建无向图
Status CreateUDG(ALGraph *G)
{
	printf("请输入顶点数和边数：");
	scanf("%d %d",&(*G).vexnum,&(*G).arcnum);    //输入顶点数和边数
	printf("请输入%d顶点名称：",(*G).vexnum);
	for(int i=0;i<(*G).vexnum;i++)
	{
		scanf(" %c",&((*G).vertices[i].data));   //输入图的顶点名称
		(*G).vertices[i].firstarc = NULL;        //顶点表指向边链表指针初始化为NULL
	}
	for(int k=0;k<(*G).arcnum;k++)
	{
		int i,j;
		char v1,v2;     //两个顶点
		printf("请输入连接那条边的两个顶点：");
		scanf(" %c%c",&v1,&v2);
		i=LocateVex(*G,v1);      //定位两个顶点的位置
		j=LocateVex(*G,v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //开辟一个结点加到 边链表里
		p1->nextarc = (*G).vertices[i].firstarc;    //边链表新加入结点插到头
		p1->adjvex = j;       //将边的另一个顶点位置设置为j
		p1->info = 1;         //权值
		(*G).vertices[i].firstarc = p1;   //顶点连接边链表
		//无向网另一顶点
		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
		p2->nextarc = (*G).vertices[j].firstarc;
		p2->adjvex = i;
		p2->info = 1;
		(*G).vertices[j].firstarc = p2;
	}
	return OK;
}

//创建无向网
Status CreateUDW(ALGraph *G)
{
	printf("请输入顶点数和边数：");
	scanf("%d %d",&(*G).vexnum,&(*G).arcnum);    //输入顶点数和边数
	printf("请输入%d顶点名称：",(*G).vexnum);
	for(int i=0;i<(*G).vexnum;i++)
	{
		scanf(" %c",&((*G).vertices[i].data));   //输入图的顶点名称
		(*G).vertices[i].firstarc = NULL;        //顶点表指向边链表指针初始化为NULL
	}
	for(int k=0;k<(*G).arcnum;k++)
	{
		int i,j;
		char v1,v2;     //两个顶点
		printf("请输入连接那条边的两个顶点和权值：");
		scanf(" %c%c",&v1,&v2);
		i=LocateVex(*G,v1);      //定位两个顶点的位置
		j=LocateVex(*G,v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //开辟一个结点加到 边链表里
		p1->nextarc = (*G).vertices[i].firstarc;    //边链表新加入结点插到头
		p1->adjvex = j;     //将边的另一个顶点位置设置为j
		scanf("%d",&p1->info);
		(*G).vertices[i].firstarc = p1;   //顶点连接边链表
		//无向网另一顶点
		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
		p2->nextarc = (*G).vertices[j].firstarc;
		p2->adjvex = i;
		p2->info = p1->info;
		(*G).vertices[j].firstarc = p2;
	}
	return OK;
}

//创建有向图
Status CreateDG(ALGraph *G)
{
	printf("请输入顶点数和边数：");
	scanf("%d %d",&(*G).vexnum,&(*G).arcnum);    //输入顶点数和边数
	printf("请输入%d顶点名称：",(*G).vexnum);
	for(int i=0;i<(*G).vexnum;i++)
	{
		scanf(" %c",&((*G).vertices[i].data));   //输入图的顶点名称
		(*G).vertices[i].firstarc = NULL;        //顶点表指向边链表指针初始化为NULL
	}
	for(int k=0;k<(*G).arcnum;k++)
	{
		int i,j;
		char v1,v2;     //两个顶点
		printf("请输入连接那条边的两个顶点：");
		scanf(" %c%c",&v1,&v2);
		i=LocateVex(*G,v1);      //定位两个顶点的位置
		j=LocateVex(*G,v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //开辟一个结点加到 边链表里
		p1->nextarc = (*G).vertices[i].firstarc;    //边链表新加入结点插到头
		p1->adjvex = j;       //将边的另一个顶点位置设置为j
		p1->info = 1;         //权值
		(*G).vertices[i].firstarc = p1;   //顶点连接边链表

	}
	return OK;
}

//创建有向网
Status CreateDW(ALGraph *G)
{
	printf("请输入顶点数和边数：");
	scanf("%d %d",&(*G).vexnum,&(*G).arcnum);    //输入顶点数和边数
	printf("请输入%d顶点名称：",(*G).vexnum);
	for(int i=0;i<(*G).vexnum;i++)
	{
		scanf(" %c",&((*G).vertices[i].data));   //输入图的顶点名称
		(*G).vertices[i].firstarc = NULL;        //顶点表指向边链表指针初始化为NULL
	}
	for(int k=0;k<(*G).arcnum;k++)
	{
		int i,j;
		char v1,v2;     //两个顶点
		printf("请输入连接那条边的两个顶点和权值：");
		scanf(" %c%c",&v1,&v2);
		i=LocateVex(*G,v1);      //定位两个顶点的位置
		j=LocateVex(*G,v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));   //开辟一个结点加到 边链表里
		p1->nextarc = (*G).vertices[i].firstarc;    //边链表新加入结点插到头
		p1->adjvex = j;//将边的另一个顶点位置设置为j
		scanf("%d",&p1->info);
		(*G).vertices[i].firstarc = p1;   //顶点连接边链表

	}
	return OK;
}


//邻接表深度优先遍历
void DFS(ALGraph G,int i)
{
	ArcNode *p;     //指向边链表结点指针
	visited[i]=1;   //辅助数组该位置设置为1
	printf("%c",G.vertices[i].data);
	p=G.vertices[i].firstarc;    //指向边链表结点首结点
	while(p)    //指针不为空继续循环
	{
		if(!visited[p->adjvex])
			DFS(G,p->adjvex);
		p=p->nextarc;    //继续指向下一个结点
	}
}

//深度优先遍历基本操作
void DFSTraverse(ALGraph G)
{
	//初始化辅助数组
	for(int i=0;i<G.vexnum;i++)    //初始化辅助数组
		visited[i]=0;
	for(int i=0;i<G.vexnum;i++)     //从第一个顶点作为入口进行遍历
		if(!visited[i]) DFS(G,i);
}


//邻接表广度优先遍历
int visitBFS[maxSize];
void BFS(ALGraph G,int i)
{

	ArcNode *p;     //指向边链表结点指针
	int que[maxSize], front = 0, rear = 0;   //队列定义的简单写法
	int j;
	printf("%c ",G.vertices[i].data);
	visitBFS[i]=1;   //辅助数组该位置设置为1
	rear = (rear + 1) % maxSize;     //当前顶点v进入队列
	que[rear] = i;
	while (front!=rear)     //队空时遍历完成
	{
		front = (front + 1) % maxSize;     //顶点出队
		j = que[front];
		p = G.vertices[j].firstarc;    //p指向出队顶点j的第一条边
		while (p != NULL)
		{
			if (visitBFS[p->adjvex] == 0)
			{
				printf("%c", p->adjvex);
				visited[p->adjvex] = 1;
				rear = (rear + 1) % maxSize;   //该顶点进队
				que[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
}

void BFSTraverse(ALGraph G)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (visitBFS[i] == 0)
			BFS(G, i);
	}
}


int main()
{
	ALGraph G;
	int i;
	printf("请选择：0-有向图，1-有向网，2-无向图，3-无向网：");
   scanf("%d",&i);
   switch(i)
   {
   case 0:
    CreateDG(&G);
    break;

   case 1:
    CreateDW(&G);
    break;

   case 2:
    CreateUDG(&G);
    break;

    case 3:
    CreateUDW(&G);
    break;

    default:
        break;
   }

   getchar();
    printf("深度优先搜索结果为：");
    printf("\n");
 	DFSTraverse(G);
 	printf("\n广度优先搜索结果为：");
 	printf("\n");
 	BFSTraverse(G);
}
