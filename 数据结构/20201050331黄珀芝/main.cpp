#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 999 /* 存储空间初始分配量 */
#define MAX_TREE_SIZE 999 /* 二叉树的最大结点数 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int TElemType;  /* 树结点的数据类型，目前暂定为整型 */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0号单元存储根结点  */

typedef struct
{
	int level,order; /* 结点的层,本层序号(按满二叉树计算) */
}Position;

void visit(char e)
{
    if(e!=' ')
	printf("%c",e);

}
typedef struct QueueNode
{
	int data;
	struct QueueNode *next;
}QueueNode,*QueuePtr;

typedef struct LinkQueue
{
	QueuePtr front, rear;//这里的首尾都是指针型的
}LinkQueue;

TElemType Nil=0; /*  设整型以0为空 */


/* 构造空二叉树T。因为T是固定数组，不会改变，故不需要& */
void InitBiTree(SqBiTree T)
{
	int i;
	for(i=0;i<MAX_TREE_SIZE;i++)
		T[i]=Nil; /* 初值为空 */

}

/* 按层序次序输入二叉树中结点的值(字符型或整型), 构造顺序存储的二叉树T */
void CreateBiTree(SqBiTree T)
{
	int i=0;
 	int l;
   char s[MAX_TREE_SIZE];
  // InitBiTree(T); /* 构造空二叉树T */
   printf("请按层序输入结点的值(字符)，空格表示空结点，结点数≤%d:\n",MAX_TREE_SIZE);
   getchar();
   gets(s); /* 输入字符串 */
   l=strlen(s); /* 求字符串的长度 */
   for(;i<l;i++) /* 将字符串赋值给T */
   T[i]=s[i];
 }

#define ClearBiTree InitBiTree /* 在顺序存储结构中，两函数完全一样 */

/* 初始条件: 二叉树T存在 */
/* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
Status BiTreeEmpty(SqBiTree T)
{
	if(T[0]==Nil) /* 根结点为空,则树空 */
		return TRUE;
	else
		return FALSE;
}

/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
int BiTreeDepth(SqBiTree T)
{
   int i,j=-1;
   for(i=MAX_TREE_SIZE-1;i>=0;i--) /* 找到最后一个结点 */
     if(T[i]!=Nil)
       break;
   i++;
   do
     j++;
   while(i>=powl(2,j));/* 计算2的j次幂。 */
   return j;
}

/* 初始条件: 二叉树T存在 */
/* 操作结果:  当T不空,用e返回T的根,返回OK;否则返回ERROR,e无定义 */
Status Root(SqBiTree T,TElemType *e)
{
	if(BiTreeEmpty(T)) /* T空 */
		return ERROR;
	else
	{
		*e=T[0];
		return OK;
	}
}

/* 初始条件: 二叉树T存在,e是T中某个结点(的位置) */
/* 操作结果: 返回处于位置e(层,本层序号)的结点的值 */
TElemType Value(SqBiTree T,Position e)
{
	 return T[(int)powl(2,e.level-1)+e.order-2];
}

/* 初始条件: 二叉树T存在,e是T中某个结点(的位置) */
/* 操作结果: 给处于位置e(层,本层序号)的结点赋新值value */
Status Assign(SqBiTree T,Position e,TElemType value)
{
	int i=(int)powl(2,e.level-1)+e.order-2; /* 将层、本层序号转为矩阵的序号 */
	if(value!=Nil&&T[(i+1)/2-1]==Nil) /* 给叶子赋非空值但双亲为空 */
		return ERROR;
	else if(value==Nil&&(T[i*2+1]!=Nil||T[i*2+2]!=Nil)) /*  给双亲赋空值但有叶子（不空） */
		return ERROR;
	T[i]=value;
	return OK;
}

/* 初始条件: 二叉树T存在,e是T中某个结点 */
/* 操作结果: 若e是T的非根结点,则返回它的双亲,否则返回＂空＂ */
TElemType Parent(SqBiTree T,TElemType e)
{
	int i;
	if(T[0]==Nil) /* 空树 */
		return FALSE;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* 找到e */
			return T[(i+1)/2-1];
	return Nil; /* 没找到e */
}


/* 初始条件: 二叉树T存在,e是T中某个结点 */
/* 操作结果: 返回e的左孩子。若e无左孩子,则返回＂空＂ */
TElemType LeftChild(SqBiTree T,TElemType e)
{
	int i;
	if(T[0]==Nil) /* 空树 */
		return FALSE;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* 找到e */
			return T[i*2+1];
	return FALSE; /* 没找到e */
}

/* 初始条件: 二叉树T存在,e是T中某个结点 */
/* 操作结果: 返回e的右孩子。若e无右孩子,则返回＂空＂ */
TElemType RightChild(SqBiTree T,TElemType e)
{
	int i;
	if(T[0]==FALSE) /* 空树 */
		return FALSE;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* 找到e */
			return T[i*2+2];
	return FALSE; /* 没找到e */
}

/* 初始条件: 二叉树T存在,e是T中某个结点 */
/* 操作结果: 返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂ */
TElemType LeftSibling(SqBiTree T,TElemType e)
{
	int i;
	if(T[0]==FALSE) /* 空树 */
		return FALSE;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2==0) /* 找到e且其序号为偶数(是右孩子) */
			return T[i-1];
	return FALSE; /* 没找到e */
}

/* 初始条件: 二叉树T存在,e是T中某个结点 */
/* 操作结果: 返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂ */
TElemType RightSibling(SqBiTree T,TElemType e)
{
	int i;
	if(T[0]==FALSE) /* 空树 */
		return FALSE;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2) /* 找到e且其序号为奇数(是左孩子) */
			return T[i+1];
	return FALSE; /* 没找到e */
}

void Move(SqBiTree q,int j,SqBiTree T,int i) /* InsertChild()用到。加 */
 { /* 把从q的j结点开始的子树移为从T的i结点开始的子树 */
   if(q[2*j+1]!=Nil) /* q的左子树不空 */
     Move(q,(2*j+1),T,(2*i+1)); /* 把q的j结点的左子树移为T的i结点的左子树 */
   if(q[2*j+2]!=Nil) /* q的右子树不空 */
     Move(q,(2*j+2),T,(2*i+2)); /* 把q的j结点的右子树移为T的i结点的右子树 */
   T[i]=q[j]; /* 把q的j结点移为T的i结点 */
   q[j]=FALSE; /* 把q的j结点置空 */
 }

void InsertChild(SqBiTree T,TElemType p,int LR,SqBiTree q)
 { /* 初始条件：二叉树T存在，p是T中某个结点的值，LR为0或1，非空二叉树c与T不相交且右子树为空 */
   /* 操作结果: 根据LR为0或1,插入c为T中p结点的左或右子树。p结点的原有左或右子树则成为c的右子树 */
   int j,k,i=0;
   for(j=0;j<(int)pow(2,BiTreeDepth(T))-1;j++) /* 查找p的序号 */
     if(T[j]==p) /* j为p的序号 */
       break;
   k=2*j+1+LR; /* k为p的左或右孩子的序号 */
   if(T[k]!=FALSE) /* p原来的左或右孩子不空 */
   Move(T,k,T,2*k+2); /* 把从T的k结点开始的子树移为从k结点的右子树开始的子树 */
   Move(q,i,T,k); /* 把从c的i结点开始的子树移为从T的k结点开始的子树 */
 }

//↓↓↓********************************************
//LevelOrderTraverse(T, Visit())中需要调用的队列算法
Status	InitQueue(LinkQueue &Q)
{	// 构造一个空队列Q
	if(!(Q.front=Q.rear=(QueuePtr)malloc(sizeof(QueueNode))))  exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}

Status	DestroyQueue(LinkQueue &Q)
{	// 销毁队列Q(无论空否均可)
	while(Q.front)
	{
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}

Status	EnQueue(LinkQueue &Q,TElemType e)
{	// 插入元素e为Q的新的队尾元素
	QueuePtr p;
	if(!(p=(QueuePtr)malloc(sizeof(QueueNode)))) // 存储分配失败
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}

Status	QueueEmpty(LinkQueue Q)
{	// 若Q为空队列,则返回TRUE,否则返回FALSE
	if(Q.front==Q.rear) return TRUE; else return FALSE;
}

Status	DeQueue(LinkQueue &Q,TElemType &e)
{	// 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR
	QueuePtr p;
	if(Q.front==Q.rear) return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return OK;
}
//LevelOrderTraverse(T, Visit())中需要调用的队列算法
//↑↑↑********************************************


 Status DeleteChild(SqBiTree T,Position p,int LR)
 { /* 初始条件：二叉树T存在，p指向T中某个结点，LR为1或0 */
   /* 操作结果：根据LR为1或0，删除T中p所指结点的左或右子树 */
   int i;
   Status k=OK; /* 队列不空的标志 */
   LinkQueue q;
   InitQueue(q); /* 初始化队列，用于存放待删除的结点 */
   i=(int)pow(2,p.level-1)+p.order-2; /* 将层、本层序号转为矩阵的序号 */
   if(T[i]==FALSE) /* 此结点空 */
     return ERROR;
   i=i*2+1+LR; /* 待删除子树的根结点在矩阵中的序号 */
   while(k)
   {
     if(T[2*i+1]!=NULL) /* 左结点不空 */
       EnQueue(q,2*i+1); /* 入队左结点的序号 */
     if(T[2*i+2]!=NULL) /* 右结点不空 */
       EnQueue(q,2*i+2); /* 入队右结点的序号 */
     T[i]=NULL; /* 删除此结点 */
     k=DeQueue(q,i); /* 队列不空 */
   }
   return OK;
 }



/* PreOrderTraverse()调用 */
void PreTraverse(SqBiTree T,int e)
{
	visit(T[e]);
	if(T[2*e+1]!=Nil) /* 左子树不空 */
		PreTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* 右子树不空 */
		PreTraverse(T,2*e+2);
}

/* 初始条件: 二叉树存在 */
/* 操作结果: 先序遍历T。 */
void PreOrderTraverse(SqBiTree T)
{
	if(!BiTreeEmpty(T)) /* 树不空 */
	 PreTraverse(T,0);
	printf("\n");

}

/* InOrderTraverse()调用 */
void InTraverse(SqBiTree T,int e)
{
	if(T[2*e+1]!=Nil) /* 左子树不空 */
		InTraverse(T,2*e+1);
	visit(T[e]);
	if(T[2*e+2]!=Nil) /* 右子树不空 */
		InTraverse(T,2*e+2);
}

/* 初始条件: 二叉树存在 */
/* 操作结果: 中序遍历T。 */
void InOrderTraverse(SqBiTree T)
{
	if(!BiTreeEmpty(T)) /* 树不空 */
		InTraverse(T,0);
	printf("\n");

}

/* PostOrderTraverse()调用 */
void PostTraverse(SqBiTree T,int e)
{
	if(T[2*e+1]!=Nil) /* 左子树不空 */
		PostTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* 右子树不空 */
		PostTraverse(T,2*e+2);
	visit(T[e]);
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 后序遍历T。 */
void PostOrderTraverse(SqBiTree T)
{
	if(!BiTreeEmpty(T)) /* 树不空 */
		PostTraverse(T,0);
	printf("\n");

}

/* 层序遍历二叉树 */
void LevelOrderTraverse(SqBiTree T)
{
	int i=MAX_TREE_SIZE-1,j;
	while(T[i]==Nil)
		i--; /* 找到最后一个非空结点的序号 */
	for(j=0;j<=i;j++)  /* 从根结点起,按层序遍历二叉树 */
		if(T[j]!=Nil)
			visit(T[j]); /* 只遍历非空的结点 */
	printf("\n");
}

/* 逐层、按本层序号输出二叉树 */
void Print(SqBiTree T)
{
	int j,k;
	Position p;
	TElemType e;
	for(j=1;j<=BiTreeDepth(T);j++)
	{
		printf("第%d层: ",j);
		for(k=1;k<=powl(2,j-1);k++)
		{
			p.level=j;
			p.order=k;
			e=Value(T,p);
			if(e!=Nil)
				printf("%d:%d ",k,e);
		}
		printf("\n");
	}
}



int main()
{
    int LR;
    char f;
	Status i;
	Position p;
	TElemType e;
	SqBiTree T;
	SqBiTree q;
	InitBiTree(T);

    printf("--------输入二叉树--------");
	printf("\n第一个二叉树T：\n");
	CreateBiTree(T);
	printf("建立二叉树后,树空否？%d(1:是 0:否) \n树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("第一个二叉树的根为：%c\n",e);
	else
		printf("树空，无根\n");
    printf("-------------\n");


    i=2;
    int j;j=3;
    InitBiTree(q);
    printf("第二个二叉树q：\n");
	CreateBiTree(q);
	printf("建立二叉树后,树空否？%d(1:是 0:否) \n树的深度=%d\n",BiTreeEmpty(q),BiTreeDepth(q));
	i=Root(q,&e);
	if(i)
		printf("第二个二叉树的根为：%c\n",e);
	else
		printf("树空，无根\n");

    printf("\n-----移动二叉树-----");
    printf("\n把从q的%d结点开始的子树移为从T的%d结点开始的子树:",i,j);
    Move(q,j,T,i);
    LevelOrderTraverse(q);

    printf("\n-----遍历二叉树-----");
	printf("\n层序遍历二叉树T:");
	LevelOrderTraverse(T);

	printf("前序遍历二叉树T:");
	PreOrderTraverse(T);

	printf("中序遍历二叉树T:");
	InOrderTraverse(T);

	printf("后序遍历二叉树T:");
	PostOrderTraverse(T);

    printf("\n------插入二叉树-------");
    printf("\n请输入LR的值，根据LR为0或1,插入c为T中p结点的左或右子树：");
    scanf("%d",&LR);
    printf("插入q为T中e结点的左或右子树。e结点的原有左或右子树则成为q的右子树(这里为了演示方便，直接用q来代替c了):\n");
    InsertChild(T,e,LR,q);
    LevelOrderTraverse(T);



    printf("\n---------修改某层结点的值--------");
	printf("\n修改结点的层号3,本层序号2。\n");
	p.level=3;
	p.order=2;
	e=Value(T,p);
	printf("待修改结点的原值为%c\n请输入新值:q\n",e);
    f='q';
	Assign(T,p,f);
	printf("修改后的T二叉树为：");
    LevelOrderTraverse(T);

	printf("\n---------左右孩子或者左右兄弟-------");
	printf("\n结点%c的双亲为%c,左右孩子分别为%c %c",e,Parent(T,e),LeftChild(T,e),RightChild(T,e));
	printf("\n左右兄弟分别为%c %c(无左右孩子或者左右兄弟则显示空格)\n",LeftSibling(T,e),RightSibling(T,e));

    printf("\n-----删除二叉树T中某个子树------");
    printf("\n请输入LR的值，根据LR为1或0，删除T中p所指结点的左或右子树：");
    scanf("%d",&LR);
    DeleteChild(T,p,LR);
    printf("删除后的T的二叉树：");
    LevelOrderTraverse(T);

	printf("\n---------清除二叉树------------------");
	ClearBiTree(T);
	printf("\n清除二叉树后,树空否？%d(1:是 0:否) \n树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("二叉树的根为：%c\n",e);
	else
		printf("树空，无根\n");

	return 0;
}

